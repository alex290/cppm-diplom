#include "camelfast.h"

CamelFast::CamelFast(size_t dist) : Camel(dist)
{
    name = "Верблюд-быстроход";
    speed = 40;
    TimeDoSleep = 10;
    TimeSleep[0] = 5;
    TimeSleep[1] = 6.5;
    TimeSleep[2] = 8;
}

CamelFast::~CamelFast()
{

}

