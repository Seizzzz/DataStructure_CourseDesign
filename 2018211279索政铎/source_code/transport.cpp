#include "transport.h"

Transport::Transport(class City* A, class City* B, int st, double risk, int cost)
{
    this->start = A;
    this->destination = B;
    this->start_time = st;
    this->risk = risk;
    this->time_cost = cost;
}
