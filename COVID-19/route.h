#ifndef ROUTE_H
#define ROUTE_H

#include <QObject>
#include <vector>
#include "city.h"

class Route
{
public:
    Route();
    vector<City*> via;
    vector<int> mid_arrive_time;
    vector<int> mid_again_time;
    int transportKind;
    double risk;
    int start_time; //出发时间
    int time_cost; //下一步到达的时间

signals:

};

#endif // ROUTE_H
