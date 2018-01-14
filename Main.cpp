// Main.cpp
//  projet_c++
//  Created by SabiOua on 14/11/2016.

#include "Plateau.hpp"
#include <iostream>
#include "Sokoban.hpp"
#include "Jeu2048.hpp"
#include "Joueur.hpp"
#include "Taquin.hpp"
#include "variente2048.hpp"
#include "Robot.hpp"
	using namespace std;

int main(){
	int jeu_choisi;
	Plateau plateau(4);
	Joueur joueur1("moi");
	cout << "Bienvenue, a quel jeu voulez vous jouer ? "<< endl
	<<"1- 2048 " << endl
	<<"2- 2048 (variante) " << endl
	<<"3- taquin " << endl
	<<"4- Sokoban " << endl;
	cout <<"Veuillez entrer des chiffres svp "<<endl;
	do{
		cin >> jeu_choisi;
	  cin.clear();
	  cin.ignore();
	}while(jeu_choisi <= 0 || jeu_choisi >4);
	cout << "Jeu_choisi " << jeu_choisi << endl;

	/*
	if(jeu_choisi==1){
		cout << " vous avez choisi 2048" << endl;
		cout << " à vous de jouer" << endl;
		Jeu2048 jeu(plateau,joueur1);
		jeu.partie();
	}

	if(jeu_choisi==2){
		cout << " vous avez choisi la variante de 2048" << endl;
		cout << " à vous de jouer" << endl;
		variente2048 jeu(plateau,joueur1);
		jeu.partie();
	}

	if(jeu_choisi==3){
		cout << " vous avez choisi le taquin " << endl;
		cout << " à vous de jouer" << endl;
		Taquin jeu(plateau,joueur1);
		jeu.partie();
	}

	if(jeu_choisi==4){
		cout << " vous avez choisi le sokoban " << endl;
		cout << " à vous de jouer" << endl;
		Sokoban jeu(plateau,joueur1);
		jeu.partie();
	}
*/


	Robot robot;
	if(jeu_choisi==1){
		cout << " vous avez chisi le robot" << endl;
		Jeu2048 jeu(plateau,robot);
		robot.typeJeu("2048",plateau);
	}

	if(jeu_choisi==2){
		cout << " vous avez chisi le robot" << endl;
		variente2048 jeu(plateau,robot);
		robot.typeJeu("variente2048",plateau);
	}

	if(jeu_choisi==3){
		cout << " vous avez chisi le robot" << endl;
		Taquin jeu(plateau,robot);
		robot.typeJeu("taquin",plateau);
	}

	if(jeu_choisi==4){
		cout << " vous avez chisi le robot" << endl;
		Sokoban jeu(plateau,robot);
		robot.typeJeu("sokoban",plateau);
				}

	return 0;
}
