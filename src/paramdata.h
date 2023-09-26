#pragma once

#include <iostream>
#include <air/broom.h>
#include <air/eagle.h>
#include <air/magiccarpet.h>
#include <grount/vehicleboots.h>
#include <grount/camelfast.h>
#include <grount/centaur.h>

// Класс работа с параметрами

class ParamData
{
public:
    enum NameTransport
    {
        VEHICLE_BOOTS = 1, // Ботинки-вездеходы
        BROOM,             // Метла
        CAMEL,             // Верблюд
        CENTAUR,           // Кентавр
        EAGLE,             // Орёл
        CAMEL_FAST,        // Верблюд-быстроход
        MAGIC_CARPET       // Ковёр-самолёт
    };

    ParamData();
    ~ParamData();

    int GetType();     // тип гонки
    int GetDistance(); // Дистанция гонки

    void Register(bool mess = true); // Регистрация ТС

    size_t GetSize(); // Количество TC

private:
    int type_sim;     // тип гонки
    int distance_sim; // Дистанция гонки

    Transport **transport;
    size_t sizeTransport;

    void SetType();     // выбор типа гонки
    void SetDistance(); // выбор Дистанция гонки

    void AddRgister(ParamData::NameTransport name); // Регистрация транспорта

    bool ValidateRegister(ParamData::NameTransport name); // Проверка на правильность регистрации
    bool OneTransport(ParamData::NameTransport name); // Проверка на наличие одинаковых зарегистрированных

    void DelTransp();
};
