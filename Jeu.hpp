// Jeu.hpp
//  projet_c++
//  Created by SabiOua on 14/11/2016.

#ifndef JEU
#define JEU
#include <iostream>
#include "Plateau.hpp"
#include "Joueur.hpp"
	using namespace std;

class Jeu{
protected:
	Plateau plateau;
	Joueur joueur;

public:
		Jeu(Plateau,Joueur);
		virtual void initialisation() =0;
		virtual void partie()=0;
		virtual bool plateau_remplie()=0;
		virtual void remplissage() = 0;
		virtual void mouvement_bas(int,int)=0;
		virtual void mouvement_haut(int,int)=0;
		virtual void mouvement_droite(int,int)=0;
		virtual void mouvement_gauche(int,int)=0;
		virtual ~Jeu();
};
#endif
