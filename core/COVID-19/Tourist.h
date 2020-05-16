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
    int limit; //������ʱ��
    void plan_route(int time);
    void update_status(int time);
    City* start;
    City* destination;
private:
    City* nowat;
    Route plan;
    double risk; //��ǰ�ÿ������ܵķ���ֵ
    void dfs(City* at, Route rut, int time); //��ǰ����λ�� ·�� ��ǰʱ�� ʱ������
};