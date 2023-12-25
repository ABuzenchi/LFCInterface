#include "State.h"
#include <math.h>
int State::radiusOfNode = 40;
State::State()
{
    value =  - 1;
    isSelected = false;
}




void State::setCoordinate(int x, int y)
{
    this->coordinate.setX(x);
    this->coordinate.setY(y);
}

void State::setCoordiante(QPoint p)
{
    coordinate = p;
}

void State::setX(int x)
{
    this->coordinate.setX(x);
}

void State::setY(int y)
{
    this->coordinate.setY(y);
}



QPoint State::getCoordinate()
{
    return coordinate;
}

int State::getX()
{
    return coordinate.x();
}
int State::getY()
{
    return coordinate.y();
}

bool State::getSelected() 
{
    return this->isSelected;
}

int State::getValue()
{
    return value;
}


void State::setSelected(bool selected)
{
    isSelected = selected;
}

void State::setValue(int v)
{
    value = v;
}
