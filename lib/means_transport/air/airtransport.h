#pragma once

#include "../transport.h"

class AirTransport : public Transport
{
public:
    AirTransport(size_t dist);
    virtual ~AirTransport();

    double GetTime() override;

protected:
    double distanceCoefficient{}; // Коэффициент сокращения расстояния

    virtual double GetDistance(); // получить расстояние
};