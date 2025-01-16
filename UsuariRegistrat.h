#include <iostream>
#include <vector>
#include <map>
#include "TipusPrivacitat.h"
#include "TipusRelacio.h"
#include "MissatgePrivat.h"
#include "Text.h"

#ifndef USUARIREGISTRAT_H
#define USUARIREGISTRAT_H

using namespace std;

class UsuariRegistrat {
public:
    UsuariRegistrat(string nomUsuari, string passw, int id); //Constructor amb paràmetres
    void establirRelacioUsuari(string nom, TipusRelacio t);
    void bloquejarUsuari(string nom);
    bool comparaContrassenya(string c);
    int obtID() const;
    string obtNom()const;
    bool potRebreMissatge(string u) const;
    void penjarText(Text t);
    Text obtText(int idT);
    void actualitzarText(Text t);
    void enviaMissatgePrivat(string u, MissatgePrivat m); //pre: s'ha comprovat q es pugui enviar el missatge
    void repMissatgePrivat(string u, MissatgePrivat m);
protected:
    string nomUsuari;//considerarem que és únic
    int id;
    string password;
    TipusPrivacitat t;
    map <TipusRelacio, vector<string>> relacions;
    vector<string> bloquejats;

     vector<Text> textsPenjats;

    map<string, vector<MissatgePrivat>> missatges; //dins de cada missatge se sap qui l'ha enviat
    bool potComunicarse(string u, TipusRelacio t) const;
};



#endif //USUARIREGISTRAT_H
