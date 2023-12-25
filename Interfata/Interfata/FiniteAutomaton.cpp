#include "FiniteAutomaton.h"
FiniteAutomaton::FiniteAutomaton()
{
}

FiniteAutomaton::FiniteAutomaton(std::vector<char> stari, std::vector<char> alfabet, char stare_initiala, const std::vector<char>& stariFinale,
	std::vector<std::tuple<char, char, std::vector<char>>> tranzite) :m_alfabet(alfabet), m_stare_initiala(stare_initiala),
	m_stari(stari), m_stariFinale(stariFinale), m_tranzite(tranzite)
{
}

void FiniteAutomaton::SetStari(std::vector<char>& stari)
{
	this->m_stari = stari;
}

void FiniteAutomaton::SetAlfabet(std::vector<char>& alfabet)
{
	this->m_alfabet = alfabet;
}

void FiniteAutomaton::SetStareInitiala(char stare_initiala)
{
	this->m_stare_initiala = stare_initiala;
}

void FiniteAutomaton::SetStariFinale(const std::vector<char>& stariFinale)
{
	this->m_stariFinale = stariFinale;
}

void FiniteAutomaton::SetTranzitionFunction(std::vector<std::tuple<char, char, std::vector<char>>>& tranzite)
{
	this->m_tranzite = tranzite;
}

std::vector<char> FiniteAutomaton::GetStari() const
{
	return m_stari;
}

std::vector<char> FiniteAutomaton::GetAlfabet() const
{
	return m_alfabet;
}

std::vector<char> FiniteAutomaton::GetStariFinale() const
{
	return m_stariFinale;
}

char FiniteAutomaton::GetStareInitiala()const
{
	return m_stare_initiala;
}

std::vector<std::tuple<char, char, std::vector<char>>> FiniteAutomaton::GetTranziti() const
{
	return m_tranzite;
}

bool FiniteAutomaton::VerifyAutomaton()
{
	///q apartine Q
	if (IsStareIntrare(m_stare_initiala) == false)
		return false;

	// Q multime nevida
	if (m_stari.size() == 0)
		return false;

	///Alfabet multime nevida
	if (m_alfabet.size() == 0)
		return false;

	/// Stari Finale sa fie in Q
	for (int i = 2; i < m_stariFinale.size(); i++)
	{
		if (IsStareIntrare(m_stariFinale[i]) == false)
			return false;
	}

	//Verificare parametrii functie tranzactie

	for (int i = 0; i < m_tranzite.size(); i++)
	{
		//Verificare stare intrare
		if (IsStareIntrare(std::get<0>(m_tranzite[i])) == false)
			return false;

		/// Verficare alfabet 
		if (isPartAlfabet(std::get<1>(m_tranzite[i]) == false))
			return false;

		///verif rezultat functie
		for (int j = 0; j < std::get<2>(m_tranzite[i]).size(); j++)
		{
			if (std::get<2>(m_tranzite[i])[j] != 'S' || std::get<2>(m_tranzite[i])[j] != 'T')
			{
				if (IsStareIntrare(std::get<2>(m_tranzite[i])[j]) == false)
					return false;
			}

		}

	}
	return true;
}

bool FiniteAutomaton::IsStareIntrare(int x)
{
	for (int i = 0; i < m_stari.size(); i++)
	{
		if (x == m_stari[i])
			return true;
	}
	return false;
}

bool FiniteAutomaton::isPartAlfabet(char a)
{
	for (int j = 0; j < m_alfabet.size(); j++)
	{
		if (m_alfabet[j] == a)
		{
			return true;
		}

	}
	return false;
}

bool FiniteAutomaton::isFinalState(char a)
{
	for (int i = 0; i < m_stariFinale.size(); i++)
	{
		if (m_stariFinale[i] == a)
			return true;
	}
	return false;
}

char FiniteAutomaton::FindSimbolForFinalState()
{
	int AsciiZ = 'Z';
	int AsciiA = 'A';
	std::vector<bool> present(AsciiZ + 1, false);
	for (char c : m_stari) {
		present[static_cast<unsigned char>(c)] = true;
	}

	for (int i = AsciiA; i <= AsciiZ; ++i) {
		if (!present[i]) {
			return static_cast<char>(i);
		}
	}
}

void FiniteAutomaton::DisplayAutomaton()
{
	std::cout << "Stari (Q): {";
	for (const char& stare : m_stari) {
		std::cout << stare << " ";
	}
	std::cout << "}\n";

	std::cout << "Alfabet: {";
	for (const char& simbol : m_alfabet) {
		std::cout << simbol << " ";
	}
	std::cout << "}\n";

	std::cout << "Stare Initiala (q0): " << m_stare_initiala << "\n";

	std::cout << "Stari Finale (F): {";
	for (auto stareFinala : m_stariFinale) {
		std::cout << stareFinala << " ";
	}
	std::cout << "}\n";

	std::cout << "Functia de Tranzitie:\n";
	for (const auto& tranzitie : m_tranzite) {
		std::cout << "(" << std::get<0>(tranzitie) << ", " << std::get<1>(tranzitie) << ") -> {";
		for (const char& stare : std::get<2>(tranzitie)) {
			std::cout << stare << " ";
		}
		std::cout << "}\n";
	}
}

void FiniteAutomaton::AddFinalState(char a)
{
	this->m_stariFinale.push_back(a);
}

std::vector<char> FiniteAutomaton::FindTranzition(char simbol, char state)
{
	for (auto tranzition : m_tranzite)
	{
		if (std::get<0>(tranzition) == state && std::get<1>(tranzition) == simbol)
			return std::get<2>(tranzition);
	}
	std::vector<char> a;
	return a;
}

bool FiniteAutomaton::CheckWord(const std::string& word)
{
	std::vector<char> stareCurenta;
	std::vector<char>result;
	if (word == "~")
		if (std::find(m_stariFinale.begin(), m_stariFinale.end(), m_stare_initiala) != m_stariFinale.end())
			return true;
	stareCurenta.push_back(m_stare_initiala);
	for (auto letter : word)
	{
		if (isPartAlfabet(letter) == false)
			return false;

		for (auto elem : stareCurenta)
		{
			if (FindTranzition(letter, elem).size() > 0)
				for (auto tran : FindTranzition(letter, elem))
					if (std::find(result.begin(), result.end(), tran) == result.end())
						result.push_back(tran);

		}
		stareCurenta.clear();
		stareCurenta = result;
		result.clear();
	}
	for (auto stari : stareCurenta)
	{
		if (isFinalState(stari) == true)
			return true;
	}
	return false;

}

bool FiniteAutomaton::IsDeterminist()
{
	for (auto tranz : m_tranzite)
	{
		if (std::get<2>(tranz).size() > 1)
			return false;
	}
	return true;
}

std::istream& operator>>(std::istream& in, FiniteAutomaton& automaton) {
	int dim;

	// Citire stari (Q)
	in >> dim;
	std::vector<char> stari(dim);
	for (int i = 0; i < dim; i++) {
		in >> stari[i];
	}
	automaton.SetStari(stari);

	// Citire alfabet
	in >> dim;
	std::vector<char> alfabet(dim);
	for (int i = 0; i < dim; i++) {
		in >> alfabet[i];
	}
	automaton.SetAlfabet(alfabet);

	// Citire stare initiala (q0)
	char stareInitiala;
	in >> stareInitiala;
	automaton.SetStareInitiala(stareInitiala);

	// Citire stari finale (F)
	in >> dim;
	char a;
	for (int i = 0; i < dim; i++) {
		in >> a;
		automaton.AddFinalState(a);
	}

	// Citire functie de tranzitie
	in >> dim;
	std::vector<std::tuple<char, char, std::vector<char>>> tranzitii(dim);
	for (int i = 0; i < dim; i++) {
		char stare1, simbol;
		in >> stare1 >> simbol;
		int nrStari;
		in >> nrStari;
		std::vector<char> stariDestinatie(nrStari);
		for (int j = 0; j < nrStari; j++) {
			in >> stariDestinatie[j];
		}
		tranzitii[i] = std::make_tuple(stare1, simbol, stariDestinatie);
	}
	automaton.SetTranzitionFunction(tranzitii);

	return in;
}