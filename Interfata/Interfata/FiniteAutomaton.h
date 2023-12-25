#pragma once
#include <iostream>
#include <vector>
#include <tuple>
class FiniteAutomaton
{
public:
	//Constructors
	FiniteAutomaton(std::vector<char>stari, std::vector<char>alfabet, char stare_initiala, const std::vector<char>& stariFinale,
		std::vector<std::tuple<char, char, std::vector<char>>>tranzite);
	FiniteAutomaton();
	//Setter
	void SetStari(std::vector<char>& stari);
	void SetAlfabet(std::vector<char>& alfabet);
	void SetStareInitiala(char stare_initiala);
	void SetStariFinale(const std::vector<char>& stariFinale);
	void SetTranzitionFunction(std::vector<std::tuple<char, char, std::vector<char>>>& tranzite);
	//Getter
	std::vector<char> GetStari() const;
	std::vector<char> GetAlfabet() const;
	std::vector<char> GetStariFinale() const;
	char GetStareInitiala() const;
	std::vector < std::tuple<char, char, std::vector<char>>> GetTranziti() const;
	//Validare
	bool VerifyAutomaton();
	bool IsStareIntrare(int x);
	bool isPartAlfabet(char a);
	bool isFinalState(char a);

	char FindSimbolForFinalState();
	//Read and Write
	void DisplayAutomaton();
	friend std::istream& operator>>(std::istream& in, FiniteAutomaton& automaton);

	void AddFinalState(char a);
	std::vector<char> FindTranzition(char simbol, char state);
	bool CheckWord(const std::string& word);
	bool IsDeterminist();

private:
	std::vector<char>m_stari; //Q 
	std::vector<char>m_alfabet;
	char m_stare_initiala; ///q0
	std::vector<char> m_stariFinale;
	//std::vector<char>m_stariFinale; ////F
	std::vector<std::tuple<char, char, std::vector<char>>>m_tranzite; ////functia de tranzitie
};



