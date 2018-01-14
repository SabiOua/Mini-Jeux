// Joueur.cpp
//  projet_c++
//  Created by SabiOua on 14/11/2016.

#include "Joueur.hpp"

Joueur::Joueur(string nom):nom(nom),score(0){};

int Joueur::getScore(){
	return score;
}

void Joueur::setScore(int newScore){
	score = newScore;
}

string Joueur::getNom(){
	return nom;
}

Joueur::~Joueur(){
	cout << "destruction joueur" << endl;
}
