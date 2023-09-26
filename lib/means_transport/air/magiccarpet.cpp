#include "magiccarpet.h"

MagicCarpet::MagicCarpet(size_t dist) : AirTransport(dist)
{
    name = "Ковёр-самолёт";
    speed = 10;

    // Если расстояние меньше 1000 — без сокращения
    // Если расстояние меньше 5000 — 3%
    // Если расстояние меньше 10000 — 10%
    // Если расстояние больше или равно 10000 — 5%
    if (dist_ < 1000)
    {
        distanceCoefficient = 1;
    }
    else if (dist_ < 5000)
    {
        distanceCoefficient = 0.03;
    }
    else if (dist_ < 10000)
    {
        distanceCoefficient = 0.1;
    }
    else if (dist_ >= 10000)
    {
        distanceCoefficient = 0.05;
    }
}

MagicCarpet::~MagicCarpet()
{
}