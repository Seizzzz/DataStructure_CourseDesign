#pragma once
#include "City.h"

class Transport //��ͨ����
{
public:
    Transport(class City* A, class City* B, int st, double risk, int cost);
    class City* start;
    class City* destination;
    int start_time; //����ʱ��
    double risk; //����
    int time_cost; //����ʱ��
};