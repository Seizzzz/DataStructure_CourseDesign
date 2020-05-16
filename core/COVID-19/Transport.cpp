#include "Transport.h"

Transport::Transport(City* A, City* B, int st, double risk, int cost)
{
	this->start = A;
	this->destination = B;
	this->start_time = st;
	this->risk = risk;
	this->time_cost = cost;
}
