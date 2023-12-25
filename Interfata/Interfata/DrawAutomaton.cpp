#include "DrawAutomaton.h"
#include <fstream>
#include <vector>
#include <QFile>
#include <QTextStream>
#include <QMouseEvent>
DrawAutomaton::DrawAutomaton()
{

}
DrawAutomaton::DrawAutomaton(const DrawAutomaton& autom)
{
	std::vector<State*>states;
	for(auto state: autom.m_states)
	{
		State* aux = new State;
		aux->setCoordiante(state->getCoordinate());
		states.push_back(aux);
	}
	this->m_states = states;
	std::vector<Tranzitie*>tranzitii;
	for (auto t : autom.m_tranzite)
	{
		Tranzitie* tranzitie = new Tranzitie;
		for (auto s : this->m_states)
		{
			if (t->getFirstState() == s)
			{
				tranzitie->setFirstState(s);
			}

			if (t->getSecondState() == s)
			{
				tranzitie->setSecondState(s);
			}
		}
		tranzitii.push_back(tranzitie);
	}
	this->m_tranzite = tranzitii;
}
DrawAutomaton::~DrawAutomaton()
{
	// Clean up allocated memory
		for (auto state : m_states)
		{
			delete state;
		}
		for (auto tranzitie : m_tranzite) {
			delete tranzitie;
		}
}

std::vector<State*> DrawAutomaton::getStates() 
{
	return m_states;
}

std::vector<Tranzitie*> DrawAutomaton::getTranzite() 
{
	return m_tranzite;
}




void DrawAutomaton::AddState(QPoint position)
{
	State* s = new State();
	s->setCoordiante(position);
	s->setValue(m_states.size());
	m_states.push_back(s);

}

void DrawAutomaton::AddState(State* state)
{
	m_states.push_back(state);

}



void DrawAutomaton::AddTranzitie(State* s1, State* s2)
{
	if (s1->getValue() == s2->getValue())
		return;
	Tranzitie* newTranzitie = new Tranzitie(s1,s2);
	m_tranzite.push_back(newTranzitie);
}

void DrawAutomaton::AddTranzitie(Tranzitie* tranzitie)
{
	m_tranzite.push_back(tranzitie);
}

void DrawAutomaton::WriteToFile(const QString& fileName)
{
	std::vector<std::vector<int>> matrix(m_states.size(), std::vector<int>(m_states.size(), 0));

	for (auto tranzitie : getTranzite()) {

		matrix[tranzitie->getFirstState()->getValue()][tranzitie->getSecondState()->getValue()] = 1;
	}

	QFile file(fileName);
	if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
		QTextStream out(&file);
		out << matrix.size() << "\n";
		for (auto state : m_states)
		{
			out << state->getX() << " " << state->getY() << " ";
		}

		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix.size(); j++)
				out << matrix[i][j] << " ";
			out << "\n";
		}
		for (auto tranz : m_tranzite) {
			out << tranz->getFirstState()->getValue() << " "
				<< tranz->getSecondState()->getValue() << " "
				<< QString::fromStdString(tranz->getSymbol()) << " ";
		}
	}
	file.close();
}

Tranzitie* DrawAutomaton::findTranzitie(State* first, State* second)
{
	for (auto tranz : m_tranzite)
	{
		if (tranz->getFirstState() == first && tranz->getSecondState() == second)
		{
			return tranz;
		}
	}
	return nullptr;
}
