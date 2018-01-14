//variente2048.hpp
//  projet_c++
//  Created by SabiOua on 14/11/2016.

#ifndef VARIENTE2048
#define VARIENTE2048
#include "Jeu2048.hpp"
#include <iostream>
	using namespace std;

class variente2048: public Jeu2048{
public:
	variente2048(Plateau,Joueur);
	void initialisation();
	void remplissage();
	void partie();
	void explosion();
	void bonus(int);
	virtual ~variente2048();
};
#endif
