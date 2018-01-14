// Robot.cpp
//  projet_c++
//  Created by SabiOua on 14/11/2016.

#include "Robot.hpp"

Robot::Robot():Joueur("robot"){}

void Robot::typeJeu(string nom,Plateau p){
	srand(time(0));
	if( nom == "2048"){
		Jeu2048 jeu(p,*this);
		jeu.initialisation();
		for(int i=0;i<4;i++){
			switch((rand()%4)+1){
				case 1:
					jeu.recherche_paire("haut");
					break;
				case 2:
					jeu.recherche_paire("droite");
					break;
				case 3:
					jeu.recherche_paire("bas");
					break;
				case 4:
					jeu.recherche_paire("gauche");
					break;
				default:
					continue;
			}
		}
	}
	if( nom == "variente2048"){
		variente2048 jeu(p,*this);
		jeu.initialisation();
		cout << "here" << endl;
		for(int i=0;i<4;i++){
			switch((rand()%4)+1){
				case 1:
					jeu.recherche_paire("haut");
					break;
				case 2:
					jeu.recherche_paire("droite");
					break;
				case 3:
					jeu.recherche_paire("bas");
					break;
				case 4:
					jeu.recherche_paire("gauche");
					break;
				default:
					continue;
			}
		}
	}
	if(nom == "sokoban"){
		Sokoban sokoban(p,*this);
		sokoban.initialisation();
		p.affichage_plateau();
		int *tab = sokoban.recherche_bonhomme();
		for(int i=0;i<4;i++){
			switch((rand()%4)+1){
				case 1:
					sokoban.mouvement_droite(tab[0],tab[1]);//tab[1]-1
					tab=sokoban.recherche_bonhomme();
					break;
				case 2:
					sokoban.mouvement_gauche(tab[0],tab[1]+1);//tab[1]+1
					tab=sokoban.recherche_bonhomme();
					break;
				case 3:
					sokoban.mouvement_haut(tab[0],tab[1]);//tab[0]+1
					tab=sokoban.recherche_bonhomme();
					break;
				case 4:
					sokoban.mouvement_bas(tab[0],tab[1]);//tab[0]-1
					tab=sokoban.recherche_bonhomme();
					break;
				default:
					continue;
			}
		p.affichage_plateau();
		}
	}
	if(nom=="taquin"){//on met un nombre aleatoire pour les mouvements
			Taquin taquin(p,*this);
			taquin.initialisation();
			int *tab=recherche_case_vide(p);
			for(int i=0;i<4;i++){
				switch((rand()%4)+1){
					case 1:
						taquin.mouvement_droite(tab[0],tab[1]-1);
						tab[1]=tab[1]-1;
						break;
						case 2:
						taquin.mouvement_gauche(tab[0],tab[1]+1);
						tab[1]=tab[1]+1;
						break;
						case 3:
						taquin.mouvement_haut(tab[0]+1,tab[1]);
						tab[0]=tab[0]+1;
						break;
						case 4:
						taquin.mouvement_bas(tab[0]-1,tab[1]);
						tab[0]=tab[0]-1;
						break;
						default:
						continue;
				}
				p.affichage_plateau();
			}
	}
}

int* Robot::recherche_case_vide(Plateau plateau){
	int *tab = new int[2];
	for(int i=0;i<plateau.get_taille();i++){
		for(int j=0;j<plateau.get_taille();j++){
			if(plateau.get_case(i,j)->get_valeur_case()==0){
				tab[0]=i;
				tab[1]=j;
			}
		}
	}
	return tab;
}

Robot::~Robot(){
	cout << "destruction robot" << endl;
}
