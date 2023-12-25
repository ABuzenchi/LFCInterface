#pragma once

#include "State.h"

class Tranzitie
{
private:
	State* m_firstState;
	State* m_secondState;
	//std::string m_symbol;
	int m_symbol;

public:
	Tranzitie();
	Tranzitie(State* firstState, State* secondState);

	State* getFirstState() ;
	State* getSecondState() ;
	void setFirstState(State* state);
	void setSecondState(State* state);

	//std::string getSymbol();
	int getSymbol();
	//void setSymbol(std::string s);
	void setSymbol(int s);
	
};
