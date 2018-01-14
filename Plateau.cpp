// Plateau.cpp
//  projet_c++
//  Created by SabiOua on 14/11/2016.

#include "Plateau.hpp"

Plateau::Plateau(int t):taille(t){
	plateau = new Case* [taille];
    int i,j;
    for (i = 0; i < taille; i++)
        plateau[i] = new Case[taille]; // elles ont toutes la meme adresse
    for(i=0;i<taille;i++){
        for(j=0;j<taille;j++)
            plateau[i][j].set_valeur_case(0);
    }
}

int Plateau::get_taille(){
	return taille;
}

Case *Plateau::get_case(int x,int y){   // reucpere la case i j plus besoin de numero
	return &plateau[x][y];
}

ostream& operator<< (ostream& out,Plateau& p){
	int i,j;
   for(i=0;i<p.get_taille();i++){
    for (j=0;j<p.get_taille();j++){
        out << p.get_case(i,j)->get_valeur_case() ;
    }
    cout << "" << endl;
   }
    return out;
}

void Plateau::affichage_plateau(){
	int i,j;
    cout << "-----------------------------------" << endl;
    for(i=0;i<this->get_taille();i++) cout << "    " << i ;
        cout << endl;
    for(i=0;i<this->get_taille();i++){
        cout << i << "   "  << endl;
        cout << "    ";
        for(j=0;j<this->get_taille();j++){
            switch(this->get_case(i,j)->get_valeur_case()){
                case 0:
                    cout << "    | ";
                    break;
                case 77:
                    cout << "  M | " ;
                    break;
                case 67:
                    cout << "  C | " ;
                    break;
                case 66:
                    cout << "  B | " ;
                    break;
                case 120:
                    cout << "  x | " ;
                    break;
                case -3:
                    cout << "  BS| " ;
                    break;
                default:
                    cout << this->get_case(i,j)->get_valeur_case() << "   | ";
                    break;
            }
        }
        cout << endl;
    }
}

Plateau::~Plateau(){
    cout << "destruction plateau" << endl;
}
