#include "grounttransport.h"

GrountTransport::GrountTransport()
{
    type = Transport::GROUND;
}

GrountTransport::~GrountTransport()
{

}

// Коэффициент сокращения расстояния
double GrountTransport::DistanceCoefficient() {
    return 0;
}
