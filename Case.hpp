// Case.hpp
//  projet_c++
//  Created by SabiOua on 14/11/2016.

#ifndef CASE
#define CASE
#include <iostream>
	using namespace std;

class Case{
private:
	static int numero;
	int valeur;
	string type;  // pour sokoban mur, bonhomme, caisse

public:
	Case(int);
	Case();
	Case(string);
	int get_numero_case();
	void set_numero_case(int);
	int get_valeur_case();
	void set_valeur_case(int);
	friend ostream& operator<<(Case&,ostream&);
	~Case();
};
#endif
