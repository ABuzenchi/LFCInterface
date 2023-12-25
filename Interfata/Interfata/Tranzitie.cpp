#include "Tranzitie.h"

Tranzitie::Tranzitie()
{
    m_firstState = nullptr;
    m_secondState = nullptr;
}

Tranzitie::Tranzitie(State* firstState, State* secondState) : m_firstState(firstState), m_secondState(secondState), m_symbol("0")
{
}

State* Tranzitie::getFirstState()
{
    return m_firstState;
}

State* Tranzitie::getSecondState() 
{
    return m_secondState;
}

void Tranzitie::setFirstState(State* state)
{
    m_firstState = state;
}

void Tranzitie::setSecondState(State* state)
{
    m_secondState = state;
}


std::string Tranzitie::getSymbol()
{
    return m_symbol;
}


void Tranzitie::setSymbol(std::string s)
{
    m_symbol = s;
}
