#include "Interfata.h"
#include <QMouseEvent>
#include <QInputDialog>
#include <QString>
#include <limits>
#include <QLineEdit>

#include "qmessagebox.h"
#include "qradiobutton.h"
#include <iostream>
#include <qinputdialog.h>
Interfata::Interfata(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    drawAutomaton = new DrawAutomaton();
    //a = new FiniteAutomaton();
    startState = new State();

    connect(ui.radioButton, &QRadioButton::clicked, this, &Interfata::on_RadioButton_Clicked);
}

Interfata::~Interfata()
{
   // delete drawAutomaton;
    //delete a;
    //delete startState;
}

void Interfata::paintEvent(QPaintEvent* event)
{
    if (drawAutomaton->getStates().size()) {
        QPainter p(this);

        std::vector<State*> states = drawAutomaton->getStates();

        for ( State* state : states) {
          
            QRect r(state->getX() - 20, state->getY() - 20, State::radiusOfNode, State::radiusOfNode);
            p.setBrush(QColor(255, 182, 193, 127));
            p.drawEllipse(r);

            QString s;
            s.setNum(state->getValue());
            p.drawText(r, Qt::AlignCenter, s);
        }

       std::vector<Tranzitie*> tranzitii = drawAutomaton->getTranzite();
        for ( Tranzitie*  tranzitie : tranzitii) {
          
                QLineF arrowLine(tranzitie->getFirstState()->getCoordinate(), tranzitie->getSecondState()->getCoordinate());

                arrowLine.setLength(arrowLine.length() - State::radiusOfNode + 20);
                QPen pen(Qt::darkGray, 2, Qt::DashLine);
                pen.setDashPattern({ 4, 4 });
                p.setPen(pen);

                QVector<QLineF> dashedLines;
                qreal dashLength = 4;
                qreal spaceLength = 4;

                for (qreal i = 0; i < arrowLine.length(); i += dashLength + spaceLength) {
                    QPointF startPoint = arrowLine.pointAt(i / arrowLine.length());
                    QPointF endPoint = arrowLine.pointAt(std::min((i + dashLength) / arrowLine.length(), 1.0));

                    dashedLines.push_back(QLineF(startPoint, endPoint));
                }

                p.drawLines(dashedLines);

                double angle = std::atan2(-arrowLine.dy(), arrowLine.dx());
                qreal arrowSize = 15;

                QPointF arrowP1 = arrowLine.p2() - QPointF(sin(angle + M_PI / 3) * arrowSize, cos(angle + M_PI / 3) * arrowSize);
                QPointF arrowP2 = arrowLine.p2() - QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize, cos(angle + M_PI - M_PI / 3) * arrowSize);

                p.drawLine(arrowLine.p2(), arrowP1);
                p.drawLine(arrowLine.p2(), arrowP2);

                p.drawLine(arrowLine);
            
        }

        if (startState->getValue()>0) {
            QPen pen;

            if (startState->getSelected()==true) {
                pen.setColor(Qt::lightGray);
            }

            p.setPen(pen);

            QRect r(startState->getX() - 20, startState->getY() - 20, State::radiusOfNode,State::radiusOfNode);
            p.drawEllipse(r);

            QString s;
            s.setNum(startState->getValue());
            p.drawText(r, Qt::AlignCenter, s);
        }
    }
}
void Interfata::mouseReleaseEvent(QMouseEvent* mouseEvent)
{
    if (mouseEvent->button() == Qt::RightButton)
    {
       
            drawAutomaton->AddState(mouseEvent->pos());
            update();
            drawAutomaton->WriteToFile("date.out");
    }
    else if (mouseEvent->button() == Qt::LeftButton)
    {
        
            std::vector<State*>states = drawAutomaton->getStates();
            for (State* s : states)
            {
                if (fabs(mouseEvent->pos().x() - s->getX()) < 10 &&
                    fabs(mouseEvent->pos().y() - s->getY()) < 10)
                {
                    if (!startState->getSelected())
                    {
                        startState = s;
                        startState->setSelected(true);
                    }
                    else
                    {


                        /*drawAutomaton->AddTranzitie(startState, s);
                        bool ok;
                        QString defaultSymbol = "~";
                        QString newSymbol = QInputDialog::getText(
                            this,
                            tr("Enter new cost"),
                            tr("Cost:"),
                            QLineEdit::Normal,
                            defaultSymbol,
                            &ok
                        );
                        std::string symbolStr = newSymbol.toStdString();
                        drawAutomaton->findTranzitie(startState, s)->setSymbol(symbolStr);
                        startState->setSelected(false);*/

                        drawAutomaton->AddTranzitie(startState, s);
                        bool ok;
                        int defaultSymbol = 0;
                        int newSymbol = QInputDialog::getInt(
                            this,
                            tr("Enter new symbol"),
                            tr("Symbol:"),
                            defaultSymbol,
                            std::numeric_limits<int>::min(),
                            std::numeric_limits<int>::max(),
                            1,
                            &ok
                        );

                        drawAutomaton->findTranzitie(startState, s)->setSymbol(newSymbol);
                        startState->setSelected(false);
                    }
                    update();
                    drawAutomaton->WriteToFile("date.out");
                    break;
                }
                
            }
        }
    }
void Interfata::ShowEdgeCost()
{


    QString message = "Simboluri intre stari:\n";

    for (auto tranz : drawAutomaton->getTranzite())
    {
        QString edgeInfo = QString("(%1, %2): %3\n")
            .arg(tranz->getFirstState()->getValue())
            .arg(tranz->getSecondState()->getValue())
            .arg(tranz->getSymbol());

        message += edgeInfo;
    }


    QMessageBox::information(this, "Simboluri intre stari", message);
}
void Interfata::on_RadioButton_Clicked()
{
    if (ui.radioButton->isChecked() == true)
    {
        ShowEdgeCost();
    }
}

