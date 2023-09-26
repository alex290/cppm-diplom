#include "broom.h"

Broom::Broom(size_t dist) : AirTransport(dist)
{
    name = "Метла";
    speed = 20;

    // Увеличивается на 1% за каждую 1000 у.е. расстояния
    // Например, для расстояния 5600 коэффициент будет 5
    int count = static_cast<int>(static_cast<double>(dist_) / 1000);
    distanceCoefficient = 0;
    if (count > 0)
    {
        for (size_t i = 0; i < count; i++)
        {
            if (distanceCoefficient < 0.9)
            {
                distanceCoefficient += 0.01;
            }
             
        }
    }
}

Broom::~Broom()
{
}
