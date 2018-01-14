// Taquin.hpp
//  projet_c++
//  Created by SabiOua on 14/11/2016.

#ifndef TAQUIN
#define TAQUIN
#include "Plateau.hpp"
#include <iostream>
#include "Joueur.hpp"
#include "Jeu.hpp"
	using namespace std;

class Taquin: public Jeu{
public:
	Taquin(Plateau,Joueur);
	void initialisation();
	void partie();
	bool plateau_remplie();// teste si toutes les cases ont etait misent à la bonne place
	void mouvement_bas(int,int);
	void mouvement_haut(int,int);
	void mouvement_gauche(int,int);
	void mouvement_droite(int,int);   // je voudrais les mettre en commun j'essaierai apres
	void remplissage();
	virtual ~Taquin();
};
#endif
