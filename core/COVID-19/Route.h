#pragma once
#include <vector>
#include "City.h"
using namespace std;

class Route //·��
{
public:
    Route();
    vector<City*> via;
    double risk;
    int start_time; //����ʱ��
    int time_cost; //��һ�������ʱ��
};