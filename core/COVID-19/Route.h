#pragma once
#include <vector>
#include "City.h"
using namespace std;

class Route //路径
{
public:
    Route();
    vector<City*> via;
    double risk;
    int start_time; //出发时间
    int time_cost; //下一步到达的时间
};