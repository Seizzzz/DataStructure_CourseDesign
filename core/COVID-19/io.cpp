#include "io.h"

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

void dbg_City(vector<City*> _City_vector)
{
    for (auto city : _City_vector)
    {
        //序号 名称 风险
        cout << city->number << ". " << city->name << " " << city->risk << endl;
    }
}

void input_Tourist(vector<City*>& _City_vector, vector<Tourist*>& _Tourist_vector)
{
    cout << "输入旅客的出发点、目的地、时限" << endl;
    dbg_City();
    int st, des, limit;
    cin >> st >> des >> limit;
    Tourist tor(&_City_vector[st], &_City_vector[des], limit, _City_vector.size() - 1);
    tor.number = _Tourist_vector.size();
    _Tourist_vector.push_back(tor);
}

void dbg_Tourist(vector<Tourist*> _Tourist_vector, int time)
{
    for (auto person : _Tourist_vector)
    {
        //序号 状态 剩余时间
        cout << person->number << ". " << digit_to_status(person->status) << " " << person->limit - time << endl;
    }
}