#pragma once
#include "State.h"
#include "Tranzitie.h"

class DrawAutomaton
{
private:
    std::vector<State*> m_states;
    std::vector<Tranzitie*> m_tranzite;

  
public:
    DrawAutomaton();
    DrawAutomaton(const DrawAutomaton& autom);
    ~DrawAutomaton();
    //getters
    std::vector<State*> getStates() ;
    std::vector<Tranzitie*> getTranzite() ;

    void AddState(QPoint position);
    void AddState(State* state);
   // void AddTranzitie(Tranzitie tranzitie);
    void AddTranzitie(State* s1, State* s2);
    void AddTranzitie(Tranzitie* tranzitie);

    void WriteToFile(const QString& fileName);

    Tranzitie* findTranzitie(State* first, State* second);
};

