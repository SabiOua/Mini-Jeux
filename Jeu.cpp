// Jeu.cpp
//  projet_c++
//  Created by SabiOua on 14/11/2016.

#include "Jeu.hpp"

//Jeu est comme une classe abstraite.
//Normalement, on n'a pas besoin que de Jeu.hpp vu que l'on ne peut pas l'instancier

Jeu::Jeu(Plateau p,Joueur j):plateau(p),joueur(j){} // à utiliser dans chaque jeu
Jeu::~Jeu(){
	cout << "desctruction jeu" << endl;
}
