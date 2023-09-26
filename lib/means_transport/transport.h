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

    Transport();
    virtual ~Transport();

    virtual Transport::TypeSym GetType();
    virtual std::string GetName();

    virtual double GetTime();

protected:
    Transport::TypeSym type; // Тип ТС
    std::string name;

    int speed{}; // Скорость
};