#pragma once

#include "../transport.h"

class GrountTransport : public Transport
{
public:
    GrountTransport(size_t dist);
    virtual ~GrountTransport();

protected:
    double TimeDoSleep{};  // Время движения до отдыха
    double TimeSleep[3]{}; // Длительность отдыха
};