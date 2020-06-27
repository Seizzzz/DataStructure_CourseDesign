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
static Route min_plan;

void Tourist::dfs(City* at, Route rut, int time)
{
    if(this->limit == INT_MAX) //不限时策略 不访问已经经过的城市
        for(auto i : rut.via)
            if(at->name == i->name) return;

    if (time > this->limit || rut.risk > min_risk) return; //当前规划超过最晚到达时间或风险超过已有方案
    if (at->name == this->destination->name) //完成一次规划 检查是否能更新当前方案
    {
        if (rut.risk < min_risk) min_plan = rut;
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
        rut.risk += at->risk * (real_start_time - time) + i->time_cost * i->risk * at->risk; //等待时间风险 + 旅行时间风险
        dfs(i->destination, rut, real_start_time + i->time_cost);
        rut.risk -= at->risk * (real_start_time - time) + i->time_cost * i->risk * at->risk;
        rut.via.pop_back();
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
    min_plan.via.clear();

    Route res;
    dfs(this->nowat, res, time);
    this->plan = min_plan;
    this->status = WAITING;

    return;
}

void Tourist::update_status(int time)
{
    if(time < this->stlimit) return; //时间早于最早出发时间

    if(this->nowat->name == this->destination->name) //到达目的地
    {
        plan.via.clear();
        this->status = ARRIVED;
        return;
    }
    else if(time > this->limit) this->status = FAILED; //当前时间超过最晚到达时间
    else if(plan.via.empty()) this->plan_route(time); //未到达目的地且无规划
    else if (!plan.via.empty()) //正在实行规划中
    {
        if (time < this->plan.start_time) this->status = WAITING; //还未到达规划路线的出发时间
        else if (time == this->plan.start_time) this->status = TRAVELLING; //到达了出发时间
        else if (time == this->plan.start_time + this->plan.time_cost) //到达了某个目的地
        {
            this->status = ARRIVED;
            this->nowat = plan.via[0];
            this->plan_route(time); //不考虑同城内换乘时间，因而在到达时立即搜索一次
            this->update_status(time);
        }
    }

    return;
}
