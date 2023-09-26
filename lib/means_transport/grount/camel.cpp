#include "camel.h"

Camel::Camel(size_t dist) : GrountTransport(dist)
{
    name = "Верблюд";
    speed = 10;
    TimeDoSleep = 30;
    TimeSleep[0] = 5;
    TimeSleep[2] = 8;
}

Camel::~Camel()
{

}

