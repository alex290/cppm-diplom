#include "grounttransport.h"

GrountTransport::GrountTransport(size_t dist) : Transport(dist)
{
    type = Transport::GROUND;
}

GrountTransport::~GrountTransport()
{

}

