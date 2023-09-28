#include "grounttransport.h"

GrountTransport::GrountTransport(size_t dist) : Transport(dist)
{
    type = Transport::GROUND;
}

GrountTransport::~GrountTransport()
{
}

double GrountTransport::GetTime()
{
    double timeLoc = static_cast<double>(dist_) / static_cast<double>(speed);
    
    // Скорость ТС равна 100 км/ч, дистанция равна 1000 км,
    // время движения до отдыха равно 6 ч, длительность отдыха равна 3 ч.
    // В таком случае ТС пройдёт дистанцию за 1000 / 100 = 10 ч.
    // Так как время движения до отдыха равно 6 часов, то по пути ТС нужно будет отдохнуть 1 раз.
    // Итоговое время составит: 10 + 3 = 13 ч.

    double interval =speed * TimeDoSleep;
    double countOst = dist_ / interval;
    size_t count = static_cast<size_t>(countOst);

    // Если последняя остановка на конце пути уменшаем счетчик
    if (countOst == count)
    {
        count--;
    }
    
    double addTime = 0;
    if (count > 1 && TimeSleep[0] > 0)
    {
        addTime += TimeSleep[0];
        count--;
    }
    if (count > 1 && TimeSleep[1] > 0)
    {
        addTime += TimeSleep[1];
        count--;
    }
    if (count > 1 && TimeSleep[2] > 0)
    {
        
        for (size_t i = 0; i < count; i++)
        {
            addTime += TimeSleep[2];
        }
        count--;
    }
    timeLoc += addTime;

    return timeLoc;
}
