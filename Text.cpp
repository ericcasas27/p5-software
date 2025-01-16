//
// Created by Propietario on 14/1/2025.
//

#include "Text.h"

Text::Text(int idT, string cont){
    id= idT;
    contingut = cont;
}

string Text::obtCont(){
    return contingut;
}

int Text::obtId(){
    return id;
}

void Text::modificar(string s){
    contingut = s;
}

