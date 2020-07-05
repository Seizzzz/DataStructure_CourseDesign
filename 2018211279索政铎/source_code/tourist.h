#ifndef TOURIST_H
#define TOURIST_H

#include <QObject>
#include <fstream>
#include "city.h"
#include "route.h"
using namespace std;

extern ofstream outfile;
extern string toRealTime(int t);

class Tourist
{
public:
    Tourist(City* A = nullptr, City* B = nullptr, int limit = 0, int number = 0);
    bool enabled; //是否启用
    int number; //旅客序号
    int status; //旅客状态
    int stlimit; //最早出发时间
    int limit; //最晚到达时间
    void plan_route(int time); //为旅客规划路线
    void update_status(int time); //更新旅客信息
    City* start; //出发点
    City* destination; //目的地
    City* nowat; //当前位置
    Route plan; //当前规划路径
    double risk; //当前旅客所承受的风险值
    void dfs(City* at, Route rut, int time); //当前所在位置 路线 当前时间 时间限制

signals:

};

#endif // TOURIST_H
