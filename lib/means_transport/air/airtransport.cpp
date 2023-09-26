#include "airtransport.h"

AirTransport::AirTransport(size_t dist) : Transport(dist)
{
    type = Transport::AIR;
}

AirTransport::~AirTransport()
{
}
double AirTransport::GetTime()
{
    return GetDistance() / speed;
}
double AirTransport::GetDistance()
{
    // Если у воздушного ТС коэффициент сокращения расстояния равен 5%,
    // то вместо дистанции в 1000 км ему нужно пройти дистанцию в 1000 * 0.95 = 950 км.
    return dist_ * (1 - distanceCoefficient);
}
