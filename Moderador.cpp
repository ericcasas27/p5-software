//
// Created by Propietario on 14/1/2025.
//

#include "Moderador.h"
#include "string.h"

Moderador::Moderador(string nick, string passw, int idM) : UsuariRegistrat(nomUsuari, passw, id){

    nomUsuari=nick;
    password=passw;
    id=id;

};


void Moderador::modificarText(Text &t){

    string s = t.obtCont() + "(Modificat)";
    cout << t.obtCont()<<endl;
    t.modificar(s);
    cout << t.obtCont()<<endl<<endl;
}