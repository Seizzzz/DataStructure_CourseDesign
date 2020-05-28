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
    string name;
    int number;
    QPoint pos;
    double risk;
    void add_route();
    deque<class Transport*> everyday_table;

signals:

};

#endif // CITY_H
