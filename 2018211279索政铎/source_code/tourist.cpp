#include <iostream>
#include "tourist.h"
#include "city.h"
#include "route.h"
using namespace std;

const int UNKNOWN = 0;
const int WAITING = 1;
const int TRAVELLING = 2;
const int ARRIVED = 3;
const int FAILED = 4;

static double min_risk;
static vector<Route> min_plan;

void Tourist::dfs(City* at, Route rut, int time)
{
    if(rut.via.size() > 1) //不访问已经访问过的城市
    {
        for(unsigned i = 0; i < rut.via.size() - 1; i++) //检查路径中之前访问的所有城市
            if(at->name == rut.via[i]->name || at->name == this->start->name) return;
    }

    if (time > this->limit || rut.risk > min_risk) return; //当前规划超过最晚到达时间或风险超过已有方案
    if (at->name == this->destination->name) //完成一次规划 检查是否能更新当前方案
    {
        if (rut.risk < min_risk)
        {
            min_risk = rut.risk;
            min_plan.clear();
            min_plan.push_back(rut);
        }
        else if(rut.risk == min_risk) min_plan.push_back(rut); //若风险值相同 则记录多条符合线路
        return;
    }

    for (auto i : at->everyday_table) //deque<Transport> 查询当地城市的交通工具表
    {
        int nowtime = time % 24, real_start_time;
        if (nowtime <= i->start_time) real_start_time = time + i->start_time - nowtime;
        else real_start_time = time + i->start_time - nowtime + 24;

        if (rut.via.empty()) //第一个
        {
            rut.start_time = real_start_time;
            rut.time_cost = i->time_cost;
            rut.transportKind = i->transportKind;
        }
        rut.via.push_back(i->destination);

        //新增风险值 = 等待时间风险(所在城市风险*停留时间) + 旅行时间风险(乘坐时间*交通工具风险值*起点城市风险值)
        rut.risk += at->risk * (real_start_time - time) + i->time_cost * i->risk * at->risk;
        rut.mid_arrive_time.push_back(real_start_time + i->time_cost); //记录再次出发、到达时间 方便日志功能实现
        rut.mid_again_time.push_back(real_start_time);

        dfs(i->destination, rut, real_start_time + i->time_cost);

        rut.risk -= at->risk * (real_start_time - time) + i->time_cost * i->risk * at->risk; //回溯
        rut.via.pop_back();
        rut.mid_again_time.pop_back();
        rut.mid_arrive_time.pop_back();
    }
}

Tourist::Tourist(City* A, City* B, int limit, int number)
{
    this->start = A;
    this->destination = B;
    this->nowat = A;
    this->risk = 0;
    this->status = UNKNOWN;
    this->number = number;
    this->limit = limit;
}

void Tourist::plan_route(int time)
{
    min_risk = numeric_limits<double>::max();
    min_plan.clear();

    Route res;
    dfs(this->nowat, res, time);
    if(!min_plan.empty())
    {
        this->plan = min_plan[0];
        this->status = WAITING;
        this->risk = min_plan[0].risk;
    }

    //输出至日志文件
    for(unsigned i = 0; i < min_plan.size(); i++)
    {
        outfile << "======为旅客" << this->number << "找到了旅行方案" << i+1 << "/" << min_plan.size() << "======" << endl;
        outfile << "序号 " << "城市名 " << "到达时间 " << "出发时间" << endl;
        outfile << 0 << " " << this->nowat->name << " / " << toRealTime(min_plan[i].start_time) << endl;
        for(unsigned j = 0; j < min_plan[i].via.size(); j++)
        {
            if(j == min_plan[i].via.size() - 1) outfile << j+1 << " " << min_plan[i].via[j]->name << " " << toRealTime(min_plan[i].mid_arrive_time[j]) << " /"  << endl;
            else outfile << j+1 << " " << min_plan[i].via[j]->name << " " << toRealTime(min_plan[i].mid_arrive_time[j]) << " " << toRealTime(min_plan[i].mid_again_time[j+1]) << endl;
        }
        outfile << "====================" << endl;
    }

    return;
}

void Tourist::update_status(int time)
{
    if(time < this->stlimit) return; //时间早于最早出发时间

    if(this->nowat->name == this->destination->name) //到达目的地
    {
        plan.via.clear();
        this->status = ARRIVED;
        this->enabled = false;
        //输出至日志文件
        outfile << "======旅客" << this->number << "已到达目的地" << "======" << endl;
        outfile << "====================" << endl;
    }
    else if(time > this->limit) //当前时间超过最晚到达时间
    {
        this->status = FAILED;
        this->enabled = false;
        //输出至日志文件
        outfile << "======无法为旅客" << this->number << "找到旅行方案" << "======" << endl;
        outfile << "====================" << endl;
    }
    else if(plan.via.empty()) this->plan_route(time); //未到达目的地且无规划
    else if (!plan.via.empty()) //正在实行规划中
    {
        if (time < this->plan.start_time) this->status = WAITING; //还未到达规划路线的出发时间
        else if (time == this->plan.start_time) this->status = TRAVELLING; //到达了出发时间
        else if (time == this->plan.start_time + this->plan.time_cost) //到达了某个目的地
        {
            this->status = ARRIVED;
            this->nowat = plan.via[0];

            //输出至日志文件
            outfile << "======旅客" << this->number << "已到达中转站" << this->nowat->name << "======" << endl;
            outfile << "====================" << endl;

            this->plan_route(time); //不考虑同城内换乘时间，因而在到达时立即搜索一次
            this->update_status(time);
        }
    }

    return;
}
