#include "centaur.h"

Centaur::Centaur(size_t dist) : GrountTransport(dist)
{
    name = "Кентавр";
    speed = 15;
    TimeDoSleep = 8;

    TimeSleep[2] = 2;
}

Centaur::~Centaur()
{

}
