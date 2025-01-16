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
            return potComunicarse(u, TipusRelacio::AMIC);
            break;
        case TipusPrivacitat::TOTHOM:
            return true;
            break;
        case TipusPrivacitat::AMICSICONEGUTS:
            return potComunicarse(u,TipusRelacio::AMIC) || potComunicarse(u, TipusRelacio::CONEGUT);
            break;
        case TipusPrivacitat::AMICSCONEGUTSISALUDATS:
            return potComunicarse(u,TipusRelacio::AMIC) || potComunicarse(u, TipusRelacio::CONEGUT) || potComunicarse(u, TipusRelacio::SALUDAT);
            break;
    }

    return false;
}

void UsuariRegistrat::penjarText(Text t){

    textsPenjats.push_back(t);

    
}

Text UsuariRegistrat::obtText(int idT){

    for(int i=0; i<textsPenjats.size(); i++){
        if( textsPenjats[i].obtId() == idT ) return textsPenjats[i];
    }
    Text ttt;
    return ttt;

}

void UsuariRegistrat::actualitzarText(Text t){
    for(int i=0; i<textsPenjats.size(); i++){
        if(textsPenjats[i].obtId() == t.obtId()) textsPenjats[i] = t;
    }
}


void UsuariRegistrat::enviaMissatgePrivat(string u, MissatgePrivat m) {
    map<string, vector<MissatgePrivat>>::iterator chat = missatges.find(u);

    if(chat != missatges.end()){

        chat->second.push_back(m);
    }
    else{
        cout << "Iniciar Chat Nou"<<endl;

        vector<MissatgePrivat> vMP;
        vMP.push_back(m);

        missatges.insert(make_pair(u,vMP));

    }
     
}
void UsuariRegistrat::repMissatgePrivat(string u, MissatgePrivat m) {
    map<string, vector<MissatgePrivat>>::iterator chat = missatges.find(u);

    if(chat != missatges.end()){

        chat->second.push_back(m);
    }
    else{
       
        vector<MissatgePrivat> vMP;
        vMP.push_back(m);

        missatges.insert(make_pair(u,vMP));
    
    }
}

bool UsuariRegistrat::potComunicarse(string u, TipusRelacio t) const{
    map<TipusRelacio, vector<string>>::const_iterator iteR = relacions.find(t);

    for(int i=0; i<iteR->second.size(); i++) {
        if(iteR->second[i]==u) return true;
    }
    return false;
}

bool UsuariRegistrat::existeixText(int idTxt){
   
    for(Text text : textsPenjats){
        if(text.obtId() == idTxt) return true;
    }
    
    return false;
}

 bool UsuariRegistrat::usrBloquejat(string usr){

    for(int i=0; i<bloquejats.size(); i++) {
        if(bloquejats[i] == usr) return true;
    
    }
    return false;
 }

void UsuariRegistrat::modificarText(Text &t){
    cerr << "Entra el nou text:" <<endl;
    cout <<"Text original: "<< t.obtCont() <<endl;
    string s; cin>>s;
    t.modificar(s);cout << t.obtCont()<<endl;
    t.modificar(s);
    cout << t.obtCont()<<endl<<endl;
}