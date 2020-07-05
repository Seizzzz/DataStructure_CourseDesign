#ifndef CITY_H
#define CITY_H

#include <QPoint>
#include <deque>
#include <string>
#include "transport.h"
using namespace std;

class City : public QObject
{
public:
    City(string name = "", int number = 0, double risk = 0);
    string name; //城市名
    int number; //城市序号
    QPoint pos; //城市在地图上的位置
    double risk; //城市风险值
    void add_route(); //为该城市添加时刻表(未使用)
    vector<class Transport*> everyday_table; //每日时刻表

signals:

};

#endif // CITY_H
