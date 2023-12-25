#pragma once
#include<QPainter>
#include <QString>
class State
{
private:
   // QString value;
    int value;
    QPoint coordinate;
    bool isSelected;

public:
    //--Constructors--
    State();
   // State(const State* other);
   

    //--Setters--
    // void setValue(QString value);
    void setCoordinate(int x, int y);
    void setCoordiante(QPoint p);
    void setX(int x);
    void setY(int y);
    void setSelected(bool selected);
    void setValue(int v);


    //--Getters--
   // QString getValue() const;
    QPoint getCoordinate() ;
    int getX() ;
    int getY() ;
    bool getSelected();
    int getValue();

    static int radiusOfNode;
};
