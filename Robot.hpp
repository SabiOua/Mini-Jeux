// Robot.hpp
//  projet_c++
//  Created SabiOua on 14/11/2016.


#ifndef ROBOT
#define ROBOT
#include <iostream>
#include "Jeu2048.hpp"
#include "variente2048.hpp"
#include "Sokoban.hpp"
#include "Taquin.hpp"
	using namespace std;

class Robot: public Joueur{
public:
	void typeJeu(string,Plateau);
	Robot();
	int* recherche_case_vide(Plateau);
	virtual ~Robot();
};
#endif
