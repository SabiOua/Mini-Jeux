// Sokoban.hpp
//  projet_c++
//  Created by SabiOua on 14/11/2016.


#ifndef SOKOBAN
#define SOKOBAN
#include "Jeu.hpp"
#include <iostream>
	using namespace std;

class Sokoban: public Jeu{
private:
		int *tab;
public:
	Sokoban(Plateau,Joueur);
	void partie();
	void initialisation();
	void remplissage();
	bool plateau_remplie();
	void affichage();
	void mouvement_haut(int,int);
	void mouvement_bas(int,int);
	void mouvement_droite(int,int);
	void mouvement_gauche(int,int);
	int* recherche_bonhomme();
	~Sokoban();
};
#endif
