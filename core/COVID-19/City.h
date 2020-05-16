#pragma once
#include <deque>
#include <string>
#include "Transport.h"
#include "City.h"
using namespace std;

class City
{
public:
    City(string name, int number, double risk);
    string name;
    int number;
    double risk;
    void add_route();
    deque<class Transport*> everyday_table;
};