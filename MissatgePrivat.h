//
// Created by Propietario on 14/1/2025.
//
#include <iostream>
#include <vector>
#include "Paraula.h"
#ifndef MISSATGEPRIVAT_H
#define MISSATGEPRIVAT_H


using namespace std;

class MissatgePrivat {
public:
    MissatgePrivat(string emissor, string receptor, bool notifica, vector<Paraula> seq);
    void mostrarMissatge();
    void editarMissatge(vector<Paraula> nouMissatge);
private:
    string usuariEmissor;
    string usuariReceptor;
    bool notificarAutomaticament;
    vector<Paraula> sequencia;

};



#endif //MISSATGEPRIVAT_H
