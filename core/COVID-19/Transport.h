#pragma once
#include "City.h"

class Transport //交通工具
{
public:
    Transport(class City* A, class City* B, int st, double risk, int cost);
    class City* start;
    class City* destination;
    int start_time; //出发时间
    double risk; //风险
    int time_cost; //所需时间
};