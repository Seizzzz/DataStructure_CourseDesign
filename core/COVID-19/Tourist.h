#pragma once
#include "City.h"
#include "Route.h"
using namespace std;

class Tourist
{
public:
    Tourist(City* A, City* B, int limit, int number);
    int number;
    int status;
    int limit; //最晚到达时间
    void plan_route(int time);
    void update_status(int time);
    City* start;
    City* destination;
private:
    City* nowat;
    Route plan;
    double risk; //当前旅客所承受的风险值
    void dfs(City* at, Route rut, int time); //当前所在位置 路线 当前时间 时间限制
};