#include "transport.h"

Transport::Transport(size_t dist) : dist_(dist)
{
    type = GROUND;
}

Transport::~Transport()
{

}

Transport::TypeSym Transport::GetType() {
    return type;
}

std::string Transport::GetName() {
    return name;
}

double Transport::GetTime() {
    return timeEnd;
}
