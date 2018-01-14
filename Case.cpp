// Case.cpp
//  projet_c++
//  Created by SabiOua on 14/11/2016.

#include "Case.hpp"

int Case::numero =0;

Case::Case(int val):valeur(val){ ++numero; }
Case::Case(){ ++numero; }

int Case::get_numero_case(){
	return numero;
}

int Case::get_valeur_case(){
	return valeur;
}

void Case::set_numero_case(int newNum){
	numero = newNum;
}

void Case::set_valeur_case(int newVal){
	valeur = newVal;
}

ostream& operator<<(Case &c,ostream& out){
    out << c.get_valeur_case() << endl;
    return out ;
}

Case::~Case(){}
