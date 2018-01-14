// Taquin.cpp
//  projet_c++
//  Created by SabiOua on 14/11/2016.

#include "Taquin.hpp"

Taquin::Taquin(Plateau p , Joueur j1):Jeu(p,j1){}

struct MyException : public exception{
  const char * what () const throw (){
    return "erreur coup en dehors plateau";
  }
};

void Taquin::initialisation(){
	srand(time(0));
	for(int i =0 ; i<plateau.get_taille()*plateau.get_taille()-1;i++){
  		int l=rand() % plateau.get_taille();
  		int c= rand() % plateau.get_taille();
  		while(plateau.get_case(l,c)->get_valeur_case()!=0){
			c = rand() % plateau.get_taille();
  			l = rand() % plateau.get_taille();
		}
		plateau.get_case(l,c)->set_valeur_case(i+1);
	}
	plateau.affichage_plateau();
}

void Taquin::partie(){
	initialisation();
	remplissage();
}

void Taquin::remplissage(){
	int x,y;
	for(int i=0; i< 4 ; i++){
	string direction = "";
	cout << "veuillez saisir la case à deplacer " << endl;
	cin >> x;
	cin >> y;
	cout << "veuillez saisir la direction de deplacement (haut, bas , droite, gauche" << endl;
	cin >> direction;
	if(direction == "haut"){
		mouvement_haut(x,y);
	}
	if(direction == "bas"){
		mouvement_bas(x,y);
	}
	if(direction == "droite"){
		mouvement_droite(x,y);
	}
	if(direction == "gauche"){
		mouvement_gauche(x,y);
	}
	plateau.affichage_plateau();
	}
}

void Taquin::mouvement_haut(int x,int y){
	if( x > plateau.get_taille() || y > plateau.get_taille() || x < 0 || y < 0 ) {
      throw MyException();
   }
	try{
		if(plateau.get_case(x-1,y)->get_valeur_case()==0){
			plateau.get_case(x-1,y)->set_valeur_case(plateau.get_case(x,y)->get_valeur_case());
			plateau.get_case(x,y)->set_valeur_case(0);
		}
		else cout << "deplacement impossible essayez une autre direction " << endl;
	}catch (MyException& e) {
   		cout << e.what() << endl;
	}
}

void Taquin::mouvement_droite(int x,int y){
	if( x > plateau.get_taille() || y > plateau.get_taille() || x < 0 || y < 0 )
      throw MyException();
	try{
		if(plateau.get_case(x,y+1)->get_valeur_case()==0){
			plateau.get_case(x,y+1)->set_valeur_case(plateau.get_case(x,y)->get_valeur_case());
			plateau.get_case(x,y)->set_valeur_case(0);
		}
		else cout << "deplacement impossible essayez une autre direction " << endl;
	}
	catch(MyException& e) {
   		cout << e.what() << endl;
	}
}

void Taquin::mouvement_gauche(int x,int y){
	if( x > plateau.get_taille() || y > plateau.get_taille() || x < 0 || y < 0 ) {
      throw MyException();
   }
	try{
		if(plateau.get_case(x,y-1)->get_valeur_case()==0){
			plateau.get_case(x,y-1)->set_valeur_case(plateau.get_case(x,y)->get_valeur_case());
			plateau.get_case(x,y)->set_valeur_case(0);
		}
	else cout << "deplacement impossible essayez une autre direction " << endl;
	}catch(MyException& e) {
   		cout << e.what() << endl;
	}
}

void Taquin::mouvement_bas(int x,int y){
	if( x > plateau.get_taille() || y > plateau.get_taille() || x < 0 || y < 0 ) {
      throw MyException();
   }
	try{
	if(plateau.get_case(x+1,y)->get_valeur_case()==0){
			plateau.get_case(x+1,y)->set_valeur_case(plateau.get_case(x,y)->get_valeur_case());
			plateau.get_case(x,y)->set_valeur_case(0);
		}
	else cout << "deplacement impossible essayez une autre direction " << endl;
	}catch (MyException& e) {
   		cout << e.what() << endl;
	}
}

bool Taquin::plateau_remplie(){
	int total = plateau.get_taille()*plateau.get_taille()-1;
	int total2 = plateau.get_taille()*plateau.get_taille()-1;
	for(int i=0; i< plateau.get_taille();i++){
		for(int j=0;j<plateau.get_taille();j++){
			if(plateau.get_case(i,j)->get_valeur_case()==(total-total2)+1){
				--total2;
			}
			else return false;
		}
	}
	return true;
}

Taquin::~Taquin(){
	cout << "destruction taquin" << endl;
}
