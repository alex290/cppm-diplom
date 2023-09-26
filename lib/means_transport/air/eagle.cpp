#include "eagle.h"

Eagle::Eagle(size_t dist) : AirTransport(dist)
{
    name = "Орёл";
    speed = 8;
    distanceCoefficient = 0.06;
}

Eagle::~Eagle()
{

}