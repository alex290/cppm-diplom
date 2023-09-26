#pragma once

#include <iostream>
#include <string>

class Transport
{
public:
    enum TypeSym
    {
        GROUND = 1, // Наземный тип
        AIR,        // Воздушный тип
    };

    Transport(size_t dist);
    virtual ~Transport();

    virtual Transport::TypeSym GetType();
    virtual std::string GetName();

    virtual double GetTime();

protected:
    size_t dist_;
    Transport::TypeSym type; // Тип ТС
    std::string name;

    double timeEnd{}; // Время гонки

    int speed{}; // Скорость
};