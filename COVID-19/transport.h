#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <QObject>

class Transport
{
public:
    Transport(class City* A = nullptr, class City* B = nullptr, int st = 0, double risk = 0, int cost = 0);
    int transportKind; //载具种类
    class City* start; //首发站
    class City* destination; //终点站
    int start_time; //出发时间
    double risk; //风险
    int time_cost; //所需时间

signals:

};

#endif // TRANSPORT_H
