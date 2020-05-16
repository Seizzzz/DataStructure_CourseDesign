#include <iostream>
#include "Tourist.h"
#include "City.h"
#include "Route.h"
using namespace std;

const int UNKNOWN = 0;
const int WAITING = 1;
const int TRAVELLING = 2;
const int ARRIVED = 3;

static double min_risk;
static Route min_plan;

void Tourist::dfs(City* at, Route rut, int time)
{
	if (time > this->limit) return; //当前规划不符合最晚到达时间
	if (at->name == this->destination->name)
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
		}
		rut.via.push_back(i->destination);
		rut.risk += at->risk * (real_start_time - time) + i->time_cost * i->risk; //等待时间风险 + 旅行时间风险
		dfs(i->destination, rut, real_start_time + i->time_cost);
		rut.risk -= at->risk * (real_start_time - time) + i->time_cost * i->risk;
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
	if (this->status == ARRIVED || this->status == UNKNOWN)
	{
		Route res;
		dfs(this->start, res, time);
		this->plan = min_plan;
		this->status = WAITING;
	}

	return;
}

void Tourist::update_status(int time)
{
	if (!plan.via.empty()) //正在实行规划中
	{
		if (time < this->plan.start_time) this->status = WAITING; //还未到达规划路线的出发时间
		else if (time == this->plan.start_time) this->status = TRAVELLING; //到达了出发时间
		else if (time == this->plan.start_time + this->plan.time_cost) //到达了目的地
		{
			this->status = ARRIVED;
			this->nowat = plan.via[0];
		}
	}
	else this->nowat = this->start; //无规划的未知状态

	return;
}
