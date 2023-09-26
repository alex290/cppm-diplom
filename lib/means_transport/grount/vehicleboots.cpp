#include "vehicleboots.h"

VehicleBoots::VehicleBoots(size_t dist) : GrountTransport(dist)
{
    name = "Ботинки-вездеходы";
    speed = 6;
    TimeDoSleep = 60;
    TimeSleep[0] = 10;
    TimeSleep[2] = 5;
}

VehicleBoots::~VehicleBoots()
{

}