// variente2048.cpp
//  projet_c++
//  Created by SabiOua on 14/11/2016.

#include "variente2048.hpp"

variente2048::variente2048(Plateau p, Joueur j):Jeu2048(p,j){}

void variente2048::initialisation(){
	srand(time(0));
	plateau.get_case(rand() % plateau.get_taille(),rand() % plateau.get_taille())->set_valeur_case(1);
	plateau.get_case(rand() % plateau.get_taille(),rand() % plateau.get_taille())->set_valeur_case(1);
	plateau.affichage_plateau();
}

void variente2048::remplissage(){
	srand(time(0));
  	int i=(rand() % plateau.get_taille())+1;
  	int j= (rand() % plateau.get_taille())+1;
  	int val = (rand() % 3)+1;
  	if(plateau_remplie()==false){  // teste si le plateau n'est pas remplis
		while(plateau.get_case(i,j)->get_valeur_case()!=0){
			i = (rand() % plateau.get_taille())+1;
  			j = (rand() % plateau.get_taille())+1;
		}
		while (val %2 == 0)
			val = (rand() % 3)+1;
		plateau.get_case(i,j)->set_valeur_case(val);
	}
}

void variente2048::partie(){
	string direction="";
	int tour=1;
	initialisation();
	while(plateau_remplie()==false){
		cout << "veuillez saisir la direction(bas,droite,gauche,haut)  votre score est: " << joueur.getScore() << endl;
		cin >> direction;
		recherche_paire(direction);
		cout << "test" << endl;
		tour++;
	}
}

void variente2048::explosion(){
	for(int i=0;i<plateau.get_taille();i++){
		for(int j=0;j<plateau.get_taille();j++){
			if(plateau.get_case(i,j)->get_valeur_case()>=15){
				plateau.get_case(i,j)->set_valeur_case(0);
				plateau.get_case(i+1,j)->set_valeur_case(0);
				plateau.get_case(i,j+1)->set_valeur_case(0);
				plateau.get_case(i-1,j-1)->set_valeur_case(0);
				plateau.get_case(i+1,j+1)->set_valeur_case(0);
				plateau.get_case(i-1,j)->set_valeur_case(0);
				plateau.get_case(i,j-1)->set_valeur_case(0);
			}
		}
	}
}

void variente2048::bonus(int tour){
	cout << tour << endl;
	int i=(rand() % plateau.get_taille())+1;
  int j= (rand() % plateau.get_taille())+1;
	if(tour==3){
		while(plateau.get_case(i,j)->get_valeur_case()!=0){
			i = (rand() % plateau.get_taille())+1;
  			j = (rand() % plateau.get_taille())+1;
		}
		plateau.get_case(i,j)->set_valeur_case(-3);
	}
	for(int i=0;i<plateau.get_taille();i++){
		for(int j=0;j<plateau.get_taille();j++){
			if(plateau.get_case(i,j)->get_valeur_case()==-3){
				plateau.get_case(i,j)->set_valeur_case(0);
				joueur.setScore(joueur.getScore()*5);
			}
		}
	}
}

variente2048::~variente2048(){}
