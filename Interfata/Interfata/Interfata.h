#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Interfata.h"
#include "DrawAutomaton.h"
#include "FiniteAutomaton.h"


class Interfata : public QMainWindow
{
    Q_OBJECT

public:
    Interfata(QWidget *parent = nullptr);
    ~Interfata();
    virtual void paintEvent(QPaintEvent* mouseEvent);
    virtual void mouseReleaseEvent(QMouseEvent* mouseEvent);

private slots:
    void ShowEdgeCost();
    void on_RadioButton_Clicked();

private:
    Ui::InterfataClass ui;
    DrawAutomaton* drawAutomaton;
    State* startState;
    //FiniteAutomaton* a;
};
