//
// Created by Propietario on 14/1/2025.
//

#include "UsuariRegistrat.h"


UsuariRegistrat::UsuariRegistrat(string nom, string passw, int ide){
    nomUsuari=nom;
    password=passw;
    id=ide;
}

void UsuariRegistrat::establirRelacioUsuari(string nom, TipusRelacio t) {
    relacions[t].push_back(nom);
}

void UsuariRegistrat::bloquejarUsuari(string nom) {
    bloquejats.push_back(nom);
}

bool UsuariRegistrat::comparaContrassenya(string c) {
    return c==password;
}

int UsuariRegistrat::obtID() const {
    return id;
}

string UsuariRegistrat::obtNom() const {
    return nomUsuari;
}
bool UsuariRegistrat::potRebreMissatge(string u) const {
    for(int i =0; i<bloquejats.size(); i++) {
        if(bloquejats[i]==u) return false;
    }
    switch (t) {
        case TipusPrivacitat::AMICS:


            case TipusPrivacitat::TOTHOM:

        case TipusPrivacitat::AMICSICONEGUTS:

        case TipusPrivacitat::AMICSCONEGUTSISALUDATS:

    }
    map <TipusRelacio, vector<string>>::const_iterator iteR = relacions.find(t);
    return
}