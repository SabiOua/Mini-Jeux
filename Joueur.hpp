// Joueur.hpp
//  projet_c++
//  Created by SabiOua on 14/11/2016.

#ifndef JOUEUR
#define JOUEUR
#include <iostream>
	using namespace std;

class Joueur{
private:
	string nom;
	int score;

public:
	Joueur(string);
	int getScore();
	void setScore(int);
	string getNom();
	virtual ~Joueur();
};
#endif
