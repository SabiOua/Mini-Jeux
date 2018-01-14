// Sokoban.cpp
//  projet_c++
//  Created by SabiOua on 14/11/2016.

#include "Sokoban.hpp"

Sokoban::Sokoban(Plateau p, Joueur j):Jeu(p,j){
	tab = new int[plateau.get_taille()];
}

struct MyException : public exception{
  const char * what () const throw (){
    return "erreur coup en dehors plateau";
  }
};

void Sokoban::initialisation(){
	int x,y;
	srand(time(0));
	int nbr_murs = (rand() % plateau.get_taille()) +plateau.get_taille();
	int nbr_croix = rand() % plateau.get_taille();
	for(int i=0; i< nbr_murs;i++)
		plateau.get_case(rand() % plateau.get_taille(),rand() % plateau.get_taille())->set_valeur_case(77);
	for(int i=0; i< nbr_croix;i++){
		x = rand() % plateau.get_taille();
		y = rand() % plateau.get_taille();
		if(plateau.get_case(x,y)->get_valeur_case()==0)
			plateau.get_case(x,y)->set_valeur_case(120);
		else
			i = i -1;
	}
	for(int i=0; i< nbr_croix;i++){
		x = rand() % plateau.get_taille();
		y = rand() % plateau.get_taille();
		if(plateau.get_case(x,y)->get_valeur_case()==0)
			plateau.get_case(x,y)->set_valeur_case(67);
		else
			i = i -1;
	}
	int l=rand() % plateau.get_taille(),c=rand() % plateau.get_taille();
	while(plateau.get_case(l,c)->get_valeur_case()!=0){
		l=rand() % plateau.get_taille();
		c=rand() % plateau.get_taille();
	}
	plateau.get_case(l,c)->set_valeur_case(66);
	plateau.affichage_plateau();
}

void Sokoban::partie(){
	initialisation();
	remplissage();
}

int* Sokoban::recherche_bonhomme(){
	int *tab = new int[2] ;
	for(int i=0;i<plateau.get_taille();i++){
		for(int j=0;j<plateau.get_taille();j++){
			if(plateau.get_case(i,j)->get_valeur_case()==66){
				tab[0]=i;
				tab[1]=j;
			}
		}
	}
	return tab;
}

void Sokoban::remplissage(){
	string direction="";
	while(plateau_remplie()==false){
		int *tab = recherche_bonhomme();
		int x = tab[0];
		int y = tab[1];
		cin >> direction;
		cout << "veuillez saisir la direction(bas,droite,gauche,haut) "  << endl;
		if(direction=="haut"){
			mouvement_haut(x,y);
		}
		if(direction=="bas"){
			mouvement_bas(x,y);
		}
		if(direction=="droite"){

			mouvement_droite(x,y);
		}
		if(direction=="gauche"){
			mouvement_gauche(x,y);
		}
		plateau.affichage_plateau();
	}
}

void Sokoban::mouvement_haut(int x, int y){
	cout << joueur.getNom() << " votre score est: " << joueur.getScore() << endl;
	if( x > plateau.get_taille() || y > plateau.get_taille() || x < 0 || y < 0 ) {
      throw MyException();
   }
   try{
		 if(plateau.get_case(x-1,y)->get_valeur_case()==77) // presence mur
			cout << "deplacement impossible presence mur" << endl;
		 else{
			if(plateau.get_case(x-1,y)->get_valeur_case()==67){
				if(plateau.get_case(x-2,y)->get_valeur_case()==0){
					plateau.get_case(x-2,y)->set_valeur_case(67);
					plateau.get_case(x,y)->set_valeur_case(0);
					plateau.get_case(x-1,y)->set_valeur_case(66);
				}
				else{
					if(plateau.get_case(x-2,y)->get_valeur_case()==120){
						plateau.get_case(x-2,y)->set_valeur_case(67);
						plateau.get_case(x,y)->set_valeur_case(0);
						plateau.get_case(x-1,y)->set_valeur_case(66);
						joueur.setScore(joueur.getScore()+10);
					}
					cout << "deplacement impossible" << endl;
				}
			}
			else{
				plateau.get_case(x,y)->set_valeur_case(plateau.get_case(x-1,y)->get_valeur_case());
				plateau.get_case(x-1,y)->set_valeur_case(66);
			}
		}
	}catch(MyException& e) {
   		cout << e.what() << endl;
	}
}

void Sokoban::mouvement_bas(int x, int y){
	cout << joueur.getNom() << " votre score est: " << joueur.getScore() << endl;
	if( x > plateau.get_taille() || y > plateau.get_taille() || x < 0 || y < 0 ) {
      throw MyException();
   }
	try{
		if(plateau.get_case(x+1,y)->get_valeur_case()==77)
			cout << "deplacement impossible presence mur" << endl;
		else{
			if(plateau.get_case(x+1,y)->get_valeur_case()==67){
				if(plateau.get_case(x+2,y)->get_valeur_case()==0){
					plateau.get_case(x+2,y)->set_valeur_case(67);
					plateau.get_case(x,y)->set_valeur_case(0);
					plateau.get_case(x+1,y)->set_valeur_case(66);
				}
				else{
					if(plateau.get_case(x+2,y)->get_valeur_case()==120){ // ici lors du deplacement sur la croix soucis
						plateau.get_case(x+2,y)->set_valeur_case(67);
						plateau.get_case(x,y)->set_valeur_case(0);
						plateau.get_case(x+1,y)->set_valeur_case(66);
						joueur.setScore(joueur.getScore()+10);
					}
					cout << "deplacement impossible" << endl;
				}
			}
			else{
				plateau.get_case(x,y)->set_valeur_case(plateau.get_case(x+1,y)->get_valeur_case());
				plateau.get_case(x+1,y)->set_valeur_case(66);
			}
	}
}catch(MyException& e) {
   		cout << e.what() << endl;
		}
}

void Sokoban::mouvement_droite(int x, int y){
	cout << joueur.getNom() << " votre score est: " << joueur.getScore() << endl;
	if( x > plateau.get_taille() || y > plateau.get_taille() || x < 0 || y < 0 ) {
      throw MyException();
   }
	try{
		if(plateau.get_case(x,y+1)->get_valeur_case()==77)
			cout << "deplacement impossible presnece mur" << endl;
		else{
			if(plateau.get_case(x,y+1)->get_valeur_case()==67){
				if(plateau.get_case(x,y+2)->get_valeur_case()==0){
					plateau.get_case(x,y+2)->set_valeur_case(67);
					plateau.get_case(x,y)->set_valeur_case(0);
					plateau.get_case(x,y+1)->set_valeur_case(66);
				}
				else{
					if(plateau.get_case(x,y+2)->get_valeur_case()==120){
						plateau.get_case(x,y+2)->set_valeur_case(67);
						plateau.get_case(x,y)->set_valeur_case(0);
						plateau.get_case(x,y+1)->set_valeur_case(66);
						joueur.setScore(joueur.getScore()+10);
					}
					else
						cout << "deplacement impossible" << endl;
				}
			}
			else{
				plateau.get_case(x,y)->set_valeur_case(plateau.get_case(x,y+1)->get_valeur_case());
				plateau.get_case(x,y+1)->set_valeur_case(66);
			}
	}
}catch(MyException& e) {
   		cout << e.what() << endl;
	}
}

void Sokoban::mouvement_gauche(int x, int y){
	cout << joueur.getNom() << " votre score est: " << joueur.getScore() << endl;
	if( x > plateau.get_taille() || y > plateau.get_taille() || x < 0 || y < 0 ) {
      throw MyException();
  }
	try{
		if(plateau.get_case(x,y-1)->get_valeur_case()==77)
			cout << "deplacement impossible prensece mur" << endl;
		else{
			if(plateau.get_case(x,y-1)->get_valeur_case()==67){
				if(plateau.get_case(x,y-2)->get_valeur_case()==0){
					plateau.get_case(x,y-2)->set_valeur_case(67);
					plateau.get_case(x,y)->set_valeur_case(0);
					plateau.get_case(x,y-1)->set_valeur_case(66);
				}
				else{
					if(plateau.get_case(x,y-1)->get_valeur_case()==120){
						plateau.get_case(x,y-2)->set_valeur_case(67);
						plateau.get_case(x,y)->set_valeur_case(0);
						plateau.get_case(x,y-1)->set_valeur_case(66);
						joueur.setScore(joueur.getScore()+10);
					}
					cout << "deplacement impossible" << endl;
				}
			}
			else{
				plateau.get_case(x,y)->set_valeur_case(plateau.get_case(x,y-1)->get_valeur_case());
				plateau.get_case(x,y-1)->set_valeur_case(66);
			}
	}
}catch(MyException& e) {
   		cout << e.what() << endl;
	}
}

bool Sokoban::plateau_remplie(){
	for(int i=0; i< plateau.get_taille();i++){
		for(int j=0; j<plateau.get_taille();j++){
			if(plateau.get_case(i,j)->get_valeur_case() == 120) return false;
		}
	}
	return true;
}

Sokoban::~Sokoban(){
	cout << "destruction sokoban" << endl;
}
