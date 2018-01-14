// Plateau.hpp
//  projet_c++
//  Created by SabiOua on 14/11/2016.

#ifndef PLATEAU
#define PLATEAU
#include "Case.hpp"
#include <iostream>
	using namespace std;

class Plateau{
private:
	Case **plateau;
	int taille;

public:
	Plateau(int);
	Case *get_case(int,int);
	int get_taille();
	friend ostream& operator<< (ostream&,Plateau&);
  friend ostream& operator<< (ostream&,Plateau*);
	void affichage_plateau();
	~Plateau();
};
#endif
