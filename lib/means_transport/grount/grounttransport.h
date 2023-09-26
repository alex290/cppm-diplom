#pragma once

#include "../transport.h"

class GrountTransport : public Transport
{
public:
    GrountTransport();
    virtual ~GrountTransport();

protected:
    double TimeDoSleep{};  // Время движения до отдыха
    double TimeSleep[3]{}; // Длительность отдыха

    virtual double DistanceCoefficient(); // Коэффициент сокращения расстояния
};