#include "transport.h"

Transport::Transport()
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
    return 0;
}
