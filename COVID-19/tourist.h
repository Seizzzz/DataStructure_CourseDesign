#ifndef TOURIST_H
#define TOURIST_H

#include <QObject>
#include "city.h"
#include "route.h"
using namespace std;

class Tourist
{
public:
    Tourist(City* A = nullptr, City* B = nullptr, int limit = 0, int number = 0);
    int number;
    int status;
    int stlimit; //最早出发时间
    int limit; //最晚到达时间
    void plan_route(int time);
    void update_status(int time);
    City* start;
    City* destination;
    City* nowat;
    Route plan;
    double risk; //当前旅客所承受的风险值
    void dfs(City* at, Route rut, int time); //当前所在位置 路线 当前时间 时间限制

signals:

};

#endif // TOURIST_H
