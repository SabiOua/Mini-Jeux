// Jeu2048.cpp
//  projet_c++
//  Created by SabiOua on 14/11/2016.

#include "Jeu2048.hpp"

Jeu2048::Jeu2048(Plateau p,Joueur j1):Jeu(p,j1){}

void Jeu2048::initialisation(){ //initialise le tableau au debut du jeu
	srand(time(0));
	plateau.get_case(rand() % plateau.get_taille(),rand() % plateau.get_taille())->set_valeur_case(2);
	plateau.get_case(rand() % plateau.get_taille(),rand() % plateau.get_taille())->set_valeur_case(2);
	plateau.affichage_plateau();
}

void Jeu2048::remplissage(){   // tour => tour du joueur
	srand(time(0));
  	int i=rand() % plateau.get_taille();
  	int j= rand() % plateau.get_taille();
  	int val = (rand() % 4)+1;
  	if(plateau_remplie()==false){  // teste si le plateau n'est pas remplis
		while(plateau.get_case(i,j)->get_valeur_case()!=0){
			i = rand() % plateau.get_taille();
  			j = rand() % plateau.get_taille();
		}
		while (val %2 != 0)
			val = (rand() % 4)+1;
		plateau.get_case(i,j)->set_valeur_case(val);
	}
}

bool Jeu2048::plateau_remplie(){
	int i,j;
	for(i=0;i<plateau.get_taille();i++){
		for(j=0;j<plateau.get_taille();j++)
			if (plateau.get_case(i,j)->get_valeur_case()==0) return false;
	}
	return true;
}

// on a chercher toutes les combinaisons sur les memes colonnes, il me reste s'il y en a pas
void Jeu2048::partie(){
	initialisation();
	string direction="";
	// tant que la plateau n'est pas remplit et qu'on a pas atteint 2048 Joueur->score
	while(plateau_remplie()==false){
		if(joueur.getScore()==2048) cout << "toutes mes felicitations vous avez atteint 2048 ^-^" << endl;
		cout << "veuillez saisir la direction(bas,droite,gauche,haut) " << joueur.getNom() << "votre score est: " << joueur.getScore() << endl;
		cin >> direction;
		recherche_paire(direction);
	}
}

void Jeu2048::recherche_paire(string direction){
	if(direction=="haut")
		mouvement_haut(plateau.get_taille()-1,plateau.get_taille());
	if(direction == "bas")
		mouvement_bas(0,plateau.get_taille());
	if(direction=="droite")
		mouvement_droite(0,plateau.get_taille());
	if(direction=="gauche")
		mouvement_gauche(plateau.get_taille()-1,plateau.get_taille());
	remplissage();
	plateau.affichage_plateau();
}

void Jeu2048::mouvement_haut(int ligne,int colonne){ // la colonne bouge
	for(ligne=plateau.get_taille()-1;ligne>=1;ligne--){
		for(int i=0;i<colonne;i++){
			if(plateau.get_case(ligne,i)->get_valeur_case()!=0){
				if(plateau.get_case(ligne,i)->get_valeur_case()==plateau.get_case(ligne-1,i)->get_valeur_case()){
					plateau.get_case(ligne-1,i)->set_valeur_case(plateau.get_case(ligne,i)->get_valeur_case()+plateau.get_case(ligne,i)->get_valeur_case());
					plateau.get_case(ligne,i)->set_valeur_case(0);
					joueur.setScore(joueur.getScore()+20);
				}
				else{
					if(plateau.get_case(ligne-1,i)->get_valeur_case()!=0) continue;
					else{
						plateau.get_case(ligne-1,i)->set_valeur_case(plateau.get_case(ligne,i)->get_valeur_case());
						plateau.get_case(ligne,i)->set_valeur_case(0);
					}
				}
			}
		}
	}
}

void Jeu2048::mouvement_bas(int ligne,int colonne){ // la colonne bouge
	if(ligne<plateau.get_taille()-1){
		for(int i=0;i<colonne;i++){
			if(plateau.get_case(ligne,i)->get_valeur_case()!=0){
				if(plateau.get_case(ligne,i)->get_valeur_case()==plateau.get_case(ligne+1,i)->get_valeur_case()){
					plateau.get_case(ligne+1,i)->set_valeur_case(plateau.get_case(ligne,i)->get_valeur_case()+plateau.get_case(ligne,i)->get_valeur_case());
					plateau.get_case(ligne,i)->set_valeur_case(0);
					joueur.setScore(joueur.getScore()+20);
				}
				else{
					if(plateau.get_case(ligne+1,i)->get_valeur_case()!=0) continue;
					else{
						plateau.get_case(ligne+1,i)->set_valeur_case(plateau.get_case(ligne,i)->get_valeur_case());
						plateau.get_case(ligne,i)->set_valeur_case(0);
					}
				}
			}
		}
		mouvement_bas(ligne+1,colonne);
	}
}

void Jeu2048::mouvement_droite(int colonne,int ligne){ // la colonne bouge
	if(colonne<plateau.get_taille()-1){
		for(int i=0;i<ligne;i++){
			if(plateau.get_case(i,colonne)->get_valeur_case()!=0){
				if(plateau.get_case(i,colonne)->get_valeur_case()==plateau.get_case(i,colonne+1)->get_valeur_case()){
					plateau.get_case(i,colonne+1)->set_valeur_case(plateau.get_case(i,colonne)->get_valeur_case()+plateau.get_case(i,colonne)->get_valeur_case());
					plateau.get_case(i,colonne)->set_valeur_case(0);
					joueur.setScore(joueur.getScore()+20);
				}
				else{
					if(plateau.get_case(i,colonne+1)->get_valeur_case()!=0) continue;
					else{
						plateau.get_case(i,colonne+1)->set_valeur_case(plateau.get_case(i,colonne)->get_valeur_case());
						plateau.get_case(i,colonne)->set_valeur_case(0);
					}
				}
			}
		}
		mouvement_droite(colonne+1,ligne);
	}
}

void Jeu2048::mouvement_gauche(int colonne,int ligne){ // la colonne bouge
	for(colonne=plateau.get_taille()-1;colonne>=1;colonne--){
		for(int i=0;i<ligne;i++){
			if(plateau.get_case(i,colonne)->get_valeur_case()!=0){
				if(plateau.get_case(i,colonne)->get_valeur_case()==plateau.get_case(i,colonne-1)->get_valeur_case()){
					plateau.get_case(i,colonne-1)->set_valeur_case(plateau.get_case(i,colonne)->get_valeur_case()+plateau.get_case(i,colonne)->get_valeur_case());
					plateau.get_case(i,colonne)->set_valeur_case(0);
					joueur.setScore(joueur.getScore()+20);
				}
				else{
					if(plateau.get_case(i,colonne-1)->get_valeur_case()!=0) continue;
					else{
						plateau.get_case(i,colonne-1)->set_valeur_case(plateau.get_case(i,colonne)->get_valeur_case());
						plateau.get_case(i,colonne)->set_valeur_case(0);
					}
				}
			}
		}
	}
}

Jeu2048::~Jeu2048(){
	cout << "destruction jeu 2048" << endl;
}
