#include "paramdata.h"

ParamData::ParamData()
{
    type_sim = 0;
    distance_sim = 0;
    sizeTransport = 0;

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
                std::cout << transport[i]->GetName();
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
                AddRgister(static_cast<ParamData::NameTransport>(numb));
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

size_t ParamData::GetSize() {
    return sizeTransport;
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

void ParamData::AddRgister(ParamData::NameTransport name)
{
    Transport **oldTr = new Transport *[sizeTransport + 1];
    if (sizeTransport > 0)
    {
        for (size_t i = 0; i < sizeTransport; i++)
        {
            oldTr[i] = new Transport(*transport[i]);
        }
    }

    switch (name)
    {
    case VEHICLE_BOOTS:
    {
        oldTr[sizeTransport] = new VehicleBoots();
        break;
    }
    case BROOM:
    {
        oldTr[sizeTransport] = new Broom();
        break;
    }
    case CAMEL:
    {

        oldTr[sizeTransport] = new Camel();
        break;
    }
    case CENTAUR:
    {
        oldTr[sizeTransport] = new Centaur();
        break;
    }
    case EAGLE:
    {
        oldTr[sizeTransport] = new Eagle();
        break;
    }
    case CAMEL_FAST:
    {
        oldTr[sizeTransport] = new CamelFast();
        break;
    }
    case MAGIC_CARPET:
    {
        oldTr[sizeTransport] = new MagicCarpet();
        break;
    }
    default:
        break;
    }

    DelTransp(); // Очищаем массив
    sizeTransport++;

    transport = new Transport *[sizeTransport];
    for (size_t i = 0; i < sizeTransport; i++)
    {
        transport[i] = new Transport(*oldTr[i]);
        delete oldTr[i];
    }

    delete[] oldTr;
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
        Transport tr;

        switch (name)
        {
        case VEHICLE_BOOTS:
        {
            tr = VehicleBoots();
            break;
        }
        case BROOM:
        {
            tr = Broom();
            break;
        }
        case CAMEL:
        {

            tr = Camel();
            break;
        }
        case CENTAUR:
        {
            tr = Centaur();
            break;
        }
        case EAGLE:
        {
            tr = Eagle();
            break;
        }
        case CAMEL_FAST:
        {
            tr = CamelFast();
            break;
        }
        case MAGIC_CARPET:
        {
            tr = MagicCarpet();
            break;
        }
        default:
            break;
        }

        for (size_t i = 0; i < sizeTransport; i++)
        {
            if (tr.GetName() == transport[i]->GetName())
            {
                return true;
            }
        }
    }
    return false;
}

void ParamData::DelTransp()
{
    if (sizeTransport > 0)
    {
        for (size_t i = 0; i < sizeTransport; i++)
        {
            delete transport[i];
        }
        delete[] transport;
    }
}
