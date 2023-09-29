#include "paramdata.h"

ParamData::ParamData()
{
    type_sim = 0;
    distance_sim = 0;
    sizeTransport = 0;

    transport = nullptr;

    SetType();
    SetDistance();
}

ParamData::~ParamData()
{
    DelTransp();
}

int ParamData::GetType()
{
    return type_sim;
}

int ParamData::GetDistance()
{
    return distance_sim;
}

// Регистрация ТС
void ParamData::Register(bool mess)
{
    int numb = 1;
    while (numb != 0)
    {
        std::string text;

        switch (type_sim)
        {
        case 1:
            text = "\nГонка для наземного транспорта.";
            break;
        case 2:
            text = "\nГонка для воздушного транспорта.";
            break;
        default:
            text = "\nГонка для наземного и воздушного транспорта.";
            break;
        }

        std::cout << text << "Расстояние: " << distance_sim << "\n";

        if (sizeTransport > 0)
        {
            std::cout << "Зарегистрированные транспортные средства: ";
            for (size_t i = 0; i < sizeTransport; i++)
            {
                if (i > 0)
                {
                    std::cout << ", ";
                }
                std::cout << GetName(transport[i]);
            }

            std::cout << std::endl;
        }

        std::cout << "1. Ботинки-вездеходы\n2. Метла\n3. Верблюд\n4. Кентавр\n5. Орёл\n6. Верблюд-быстроход\n7. Ковёр-самолет\n0. Закончить регистрацию\nВыберите транспорт или 0 для окончания процесса регистрации: ";
        std::cin >> numb;

        if (numb > 0 && numb < 8)
        {
            if (OneTransport(static_cast<ParamData::NameTransport>(numb)))
            {
                std::cout << "\nТакой транспорт уже существует\n";
            }
            else if (ValidateRegister(static_cast<ParamData::NameTransport>(numb)))
            {
                PushArray(transport, sizeTransport, static_cast<ParamData::NameTransport>(numb));
            }
            else
            {
                std::cout << "\nПопытка зарегистрировать неправильныи тип транспортного средства:\n";
            }
        }
        else if (numb > 7)
        {
            std::cout << "\nНеверное значение\n";
        }
    }
}

size_t ParamData::GetSize()
{
    return sizeTransport;
}

void ParamData::Result()
{
    std::cout << "\nРезультаты гонки\n";
    SortArray(transport);

    if (sizeTransport > 0)
    {
        for (size_t i = 0; i < sizeTransport; i++)
        {
            std::cout << (i + 1) << ". " << GetName(transport[i]) << ". Время: " << GetTime(transport[i]) << std::endl;
        }
    }
    std::cout << std::endl;
}

void ParamData::SetType()
{
    std::cout << "1. Гонка для наземного транспорта\n";
    std::cout << "2. Гонка для воздушного транспорта\n";
    std::cout << "3. Гонка для наземного и воздушного транспорта\n";
    while (type_sim < 1 || type_sim > 3)
    {
        std::cout << "Выбирите тип гонки: ";
        std::cin >> type_sim;
        if (type_sim < 1 || type_sim > 3)
        {
            std::cout << "Неверное значение\n";
        }
    }
}

void ParamData::SetDistance()
{
    while (distance_sim < 1)
    {
        std::cout << "\nУкажите длину дистанции (должна быть положительна): ";
        std::cin >> distance_sim;
        if (distance_sim < 1)
        {
            std::cout << "Неверное значение\n";
        }
    }
}

bool ParamData::ValidateRegister(ParamData::NameTransport name)
{
    switch (name)
    {
    case VEHICLE_BOOTS:
    {
        if (type_sim == 1 || type_sim == 3)
        {
            return true;
        }
        return false;
    }
    case BROOM:
    {
        if (type_sim == 2 || type_sim == 3)
        {
            return true;
        }
        return false;
    }
    case CAMEL:
    {
        if (type_sim == 1 || type_sim == 3)
        {
            return true;
        }
        return false;
    }
    case CENTAUR:
    {
        if (type_sim == 1 || type_sim == 3)
        {
            return true;
        }
        return false;
    }
    case EAGLE:
    {
        if (type_sim == 2 || type_sim == 3)
        {
            return true;
        }
        return false;
    }
    case CAMEL_FAST:
    {
        if (type_sim == 1 || type_sim == 3)
        {
            return true;
        }
        return false;
    }
    case MAGIC_CARPET:
    {
        if (type_sim == 2 || type_sim == 3)
        {
            return true;
        }
        return false;
    }
    default:
        return false;
    }
}

bool ParamData::OneTransport(ParamData::NameTransport name)
{
    if (sizeTransport > 0)
    {
        for (size_t i = 0; i < sizeTransport; i++)
        {
            if (transport[i] == name)
            {
                return true;
            }
        }
    }
    return false;
}

void ParamData::DelTransp()
{
    delete[] transport;
}

std::string ParamData::GetName(ParamData::NameTransport name)
{
    switch (name)
    {
    case VEHICLE_BOOTS:
    {
        VehicleBoots tr(distance_sim);
        return tr.GetName();
    }
    case BROOM:
    {
        Broom tr(distance_sim);
        return tr.GetName();
    }
    case CAMEL:
    {

        Camel tr(distance_sim);
        return tr.GetName();
    }
    case CENTAUR:
    {
        Centaur tr(distance_sim);
        return tr.GetName();
    }
    case EAGLE:
    {
        Eagle tr(distance_sim);
        return tr.GetName();
    }
    case CAMEL_FAST:
    {
        CamelFast tr(distance_sim);
        return tr.GetName();
    }
    case MAGIC_CARPET:
    {
        MagicCarpet tr(distance_sim);
        return tr.GetName();
    }
    default:
        break;
    }
    return "";
}

double ParamData::GetTime(ParamData::NameTransport name)
{
    switch (name)
    {
    case VEHICLE_BOOTS:
    {
        VehicleBoots tr(distance_sim);
        return tr.GetTime();
    }
    case BROOM:
    {
        Broom tr(distance_sim);
        return tr.GetTime();
    }
    case CAMEL:
    {

        Camel tr(distance_sim);
        return tr.GetTime();
    }
    case CENTAUR:
    {
        Centaur tr(distance_sim);
        return tr.GetTime();
    }
    case EAGLE:
    {
        Eagle tr(distance_sim);
        return tr.GetTime();
    }
    case CAMEL_FAST:
    {
        CamelFast tr(distance_sim);
        return tr.GetTime();
    }
    case MAGIC_CARPET:
    {
        MagicCarpet tr(distance_sim);
        return tr.GetTime();
    }
    default:
        break;
    }
    return 0;
}

void ParamData::PushArray(ParamData::NameTransport *&transp, size_t &size, ParamData::NameTransport value)
{
    ParamData::NameTransport *oldTr = new ParamData::NameTransport[sizeTransport + 1];
    if (size > 0)
    {
        for (size_t i = 0; i < size; i++)
        {
            oldTr[i] = transp[i];
        }
    }
    oldTr[size] = value;
    delete[] transp;
    transp = oldTr;
    size++;
}

void ParamData::SortArray(ParamData::NameTransport *&arr)
{
    for (int i = 0; i < sizeTransport - 1; i++)
    {
        for (int j = 0; j < sizeTransport - i - 1; j++)
        {
            if (GetTime(arr[j]) > GetTime(arr[j + 1])) 
            {
                // меняем элементы местами
                ParamData::NameTransport temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
