#include <iostream>

#include "Moderador.h"
#include "UsuariRegistrat.h"
#include "TipusPrivacitat.h"
#include "TipusRelacio.h"

using namespace std;

/* DECLARACIÓ DELS MÈTODES */
void carregarTotesLesEstructures(map<string, UsuariRegistrat> &usuarisApp);
void menuOpcions(string nomUsuari, map<string, UsuariRegistrat> &usuarisApp);
string iniciSessio(map<string, UsuariRegistrat> &usuarisApp);
void enviarMissatgePrivat(map<string, UsuariRegistrat>::iterator apuntadorActual, map<string, UsuariRegistrat> &usuarisApp);
void modificarTextPenjat(map<string, UsuariRegistrat>::iterator apuntadorActual, map<string, UsuariRegistrat> &usuarisApp);
void canviRelacio(map<string, UsuariRegistrat>::iterator apuntadorActual, const map<string, UsuariRegistrat> &usuarisApp);
int main() {
    map<string, UsuariRegistrat> usuarisApp;
    carregarTotesLesEstructures(usuarisApp);
    string nomUsuariPrincipal = iniciSessio(usuarisApp);
    int intent =0; bool b=false;
    while (nomUsuariPrincipal=="") {
        intent++;
        cout << "Contrassenya incorrecta. Ho vols tornar a provar? (+_+)" << endl;
        if(intent==3) cout << "Portes 3 intents ja... (｢•-•)｢"<< endl;
        if(intent==4) cout << "Pff... (ᗒᗣᗕ)՞"<< endl;
        if(intent==5) {
            cout << "Em tens fart (⊙︿⊙). No cal que hi tornis ( ◔ ʖ̯ ◔ )." << endl;
            break; b=true;
        }
        nomUsuariPrincipal = iniciSessio(usuarisApp);
    }
    if(!b) {
        cout << "Has iniciat sessió correctament (◕‿◕)" << endl;
        menuOpcions(nomUsuariPrincipal, usuarisApp);
    }

    return 0;
}

/* IMPLEMENTACIÓ DELS MÈTODES */
void carregarTotesLesEstructures(vector<UsuariRegistrat> &usuarisApp) {
    Moderador u1("Jordir", "jordir", 1);
    UsuariRegistrat u2("ElCunyatQueEsVaCremarLesCellesFlamejantLesGambes", "interfeisesSempre", 2);
    UsuariRegistrat u3("MiniCalde", "minimini", 3);
    UsuariRegistrat u4("K-SITAS", "edificis", 4);
    UsuariRegistrat u5("roger", "rogeret", 5);
    UsuariRegistrat u6("Skippy", "sabeunacosa", 6);
    UsuariRegistrat u7("EmaPuntRajoi", "unPlatEsUnPlat", 7);
    UsuariRegistrat u8("BannanaCat", "mew", 8);
    UsuariRegistrat u9("Entrepaneria boomer", "ramenjol", 9);
    UsuariRegistrat u10("Amadeu Ribes", "túctuc", 10);
    UsuariRegistrat u11("Manuels", "TheBestEuropeanTeachers", 11);


    u1.bloquejarUsuari(u2.obtNom()); //a ningú li cau bé el cunyat aquest.
    u3.bloquejarUsuari(u2.obtNom());
    u4.bloquejarUsuari(u2.obtNom());
    u5.bloquejarUsuari(u2.obtNom());

    u1.establirRelacioUsuari(u9.obtNom(), TipusRelacio::SALUDAT);
    u9.establirRelacioUsuari(u1.obtNom(), TipusRelacio::AMIC);

    u3.establirRelacioUsuari(u9.obtNom(), TipusRelacio::AMIC);
    u3.establirRelacioUsuari(u11.obtNom(), TipusRelacio::CONEGUT);

    u4.establirRelacioUsuari(u7.obtNom(), TipusRelacio::AMIC);
    u4.establirRelacioUsuari(u8.obtNom(), TipusRelacio::SALUDAT);

    u5.establirRelacioUsuari(u4.obtNom(), TipusRelacio::CONEGUT);
    u5.establirRelacioUsuari(u9.obtNom(), TipusRelacio::SALUDAT);

    usuarisApp.push_back(u1);
    usuarisApp.push_back(u2);
    usuarisApp.push_back(u3);
    usuarisApp.push_back(u4);
    usuarisApp.push_back(u5);
    usuarisApp.push_back(u6);
    usuarisApp.push_back(u7);
    usuarisApp.push_back(u8);
    usuarisApp.push_back(u9);
    usuarisApp.push_back(u10);
    usuarisApp.push_back(u11);

}
void menuOpcions(string nomUsuari, map<string, UsuariRegistrat> &usuarisApp) {
    map<string, UsuariRegistrat>::iterator apuntadorActual = usuarisApp.find(nomUsuari); //ja s'ha comprovat previament
    bool continuar = true;
    int opcio = 0;
    cout << "\t* Menú: *" << endl <<
                "-->  enviar un missatge privat (1) " << endl <<
                "--> modificar text penjat per un usuari (2) " << endl <<
                "--> canviar la relació amb un usuari (3) "<<endl <<
                " -->  acabar (0)" << endl;
    cin>>opcio;
    while(opcio!=0){
        if(opcio == 1)
            enviarMissatgePrivat(apuntadorActual, usuarisApp);
        else if(opcio == 2)
            modificarTextPenjat(apuntadorActual, usuarisApp);
        else if(opcio == 3)
            canviRelacio(apuntadorActual, usuarisApp);
        else cout << "Aquesta opció és incorrecta. " << endl;
        cout << "\t* Menú: *" << endl <<
                "-->  enviar un missatge privat (1) " << endl <<
                "--> modificar text penjat per un usuari (2) " << endl <<
                "--> canviar la relació amb un usuari (3) "<<endl <<
                " -->  acabar (0)" << endl;
        cin>>opcio;
    }

}

string iniciSessio(map<string, UsuariRegistrat> &usuarisApp) {
    cout << " Si us plau, introdueixi el seu nom d'usuari (◕ᗜ◕)" << endl;
    string nomUsuari; cin >> nomUsuari;
    cout << " Si us plau, introdueixi la seva contrassenya ( ͡°ᴥ͡°)" << endl;
    string passw; cin>> passw;
    map<string, UsuariRegistrat>::iterator iteU = usuarisApp.find(nomUsuari);
    if(iteU==usuarisApp.end()) return "";
    else return nomUsuari;
}

void enviarMissatgePrivat(map<string, UsuariRegistrat>::iterator apuntadorActual, map<string, UsuariRegistrat> &usuarisApp) { //

}

void modificarTextPenjat(map<string, UsuariRegistrat>::iterator apuntadorActual, map<string, UsuariRegistrat> &usuarisApp) { //(♥͜♥)

}

void canviRelacio(map<string, UsuariRegistrat>::iterator apuntadorActual, const map<string, UsuariRegistrat> &usuarisApp) {
    cout << "**********************" << endl;
    cout << "* CANVIAR LA RELACIÓ *"<< endl;
    cout << "*       ┏(-_-)┛      * "<< endl;
    cout << "**********************" << endl;
    cout << "Entra el nom de l'usuari que vols canviar la relació: " << endl;
    string nick; cin>> nick;
    map<string, UsuariRegistrat>::const_iterator iteAltra = usuarisApp.find(nick);

    if(iteAltra==usuarisApp.end()) {
        cout << "No s'ha trobat aquest usuari" << endl;
    }
    else {
        cout << "Tria la nova relació amb l'usuari " << iteAltra->second.obtNom() << endl;
        cout << "Tria entre: AMIC, CONEGUT O SALUDAT" << endl;
        string relacio; cin>> relacio;
        TipusRelacio t; bool b=true;
        if (relacio=="SALUDAT") {
            t=TipusRelacio::SALUDAT;
        }
        else if (relacio=="CONEGUT") {
            t=TipusRelacio::CONEGUT;
        }
        else if (relacio=="AMIC") {
            t=TipusRelacio::AMIC;
        }
        else {
            cout << "Aquesta relació no existeix " << endl;
            b=false;
        }
        if(b) {
            apuntadorActual->second.establirRelacioUsuari(iteAltra->second.obtNom(), t);
            cout << "Ara ja sou " << relacio << endl;
        }

    }
}
