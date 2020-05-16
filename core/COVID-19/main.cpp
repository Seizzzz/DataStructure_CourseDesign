#include <iostream>
#include <vector>
#include <Windows.h>
#include "Transport.h"
#include "City.h"
#include "Tourist.h"
#include "Route.h"
using namespace std;

const int UNKNOWN = 0;
const int WAITING = 1;
const int TRAVELLING = 2;
const int ARRIVED = 3;

vector<Tourist*> _Tourist_vector;
vector<City*> _City_vector;
vector<Transport*> _Transport_vector;
static int time = 0;

string digit_to_status(int n)
{
    switch (n)
    {
    case 0: return "UNKNOWN";
    case 1: return "WAITING";
    case 2: return "TRAVELLING";
    case 3: return "ARRIVED";
    default: return "ERROR";
    }
}

void dbg_City()
{
    for (auto city : _City_vector)
    {
        //序号 名称 风险
        cout << city->number << ". " << city->name << " " << city->risk << endl;
    }
}

void dbg_Tourist()
{
    for (auto person : _Tourist_vector)
    {
        //序号 状态 剩余时间
        cout << person->number << ". " << digit_to_status(person->status) << " " << person->limit - time << endl;
    }
}

void update_all_tourist()
{
    for (auto& tor : _Tourist_vector)
    {
        switch (tor->status)
        {
        case UNKNOWN: {
            tor->plan_route(time);
            break;
        }
        case WAITING: {
            tor->update_status(time);
            break;
        }
        case TRAVELLING: {
            tor->update_status(time);
            break;
        }
        case ARRIVED: {
            tor->plan_route(time);
        }
        }
    }
}

void input()
{
    cout << "1. 添加旅客" << endl;
    cout << "2. 添加城市" << endl;
    cout << "3. 添加时刻表" << endl;
    cout << "4. 无操作" << endl;
    int opt; cin >> opt;
    switch (opt)
    {
    case 1: {
        cout << "输入旅客的出发点、目的地、时限" << endl;
        dbg_City();
        int st, des, limit;
        cin >> st >> des >> limit;
        Tourist* newTourist = new Tourist(_City_vector[st], _City_vector[des], limit, _City_vector.size() - 1);
        newTourist->number = _Tourist_vector.size();
        _Tourist_vector.push_back(newTourist);
        break;
    }
    case 2: {
        cout << "输入城市名称、风险值" << endl;
        string name;
        double risk;
        cin >> name >> risk;
        City* newCity = new City(name, _City_vector.size(), risk);
        _City_vector.push_back(newCity);
        break;
    }
    case 3: {
        cout << "输入该次出发站、终点站、每日出发时间、风险值、所需时间" << endl;
        dbg_City();
        int st, des, st_time, cost;
        double risk;
        cin >> st >> des >> st_time >> risk >> cost;
        Transport* newTransport = new Transport(_City_vector[st], _City_vector[des], st_time, risk, cost);
        _Transport_vector.push_back(newTransport);
        _City_vector[st]->everyday_table.push_back(newTransport);
        break;
    }
    }
}

int main()
{
    for (;;++time)
    {
        //Sleep(5000);
        input();
        update_all_tourist();
    }
}