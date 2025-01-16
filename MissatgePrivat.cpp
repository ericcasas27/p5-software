//
// Created by Propietario on 14/1/2025.
//

#include "MissatgePrivat.h"

MissatgePrivat::MissatgePrivat(string emissor, string receptor, bool notifica, vector<Paraula> seq) {
    usuariEmissor=emissor;
    usuariReceptor=receptor;
    notificarAutomaticament=notifica;
    sequencia=seq;
}
void MissatgePrivat::mostrarMissatge() {
    for (int i=0; i<sequencia.size(); i++) {
        cout << sequencia[i].contingut() << " ";
    }
    cout <<endl;
}
void MissatgePrivat::editarMissatge(vector<Paraula> nouMissatge) {
    sequencia=nouMissatge;
}