// Jeu2048.hpp
//  projet_c++
//  Created by SabiOua on 14/11/2016.

#ifndef JEU2048
#define JEU2048
#include <iostream>
#include "Jeu.hpp"
	using namespace std;

class Jeu2048: public Jeu{
public:
	Jeu2048(Plateau,Joueur);
	virtual void initialisation();
	virtual void remplissage();  // le numero de tour
	bool plateau_remplie(); // si le plateau est remplis
	virtual void partie();
	void recherche_paire(string);
	virtual ~Jeu2048();
	void mouvement_haut(int,int);
	void mouvement_bas(int,int);
	void mouvement_droite(int,int);
	void mouvement_gauche(int,int);
};
#endif
