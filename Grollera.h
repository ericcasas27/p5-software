#include "Paraula.h"
#include <iostream>
#include <random>

#ifndef GROLLERA_H
#define GROLLERA_H

// Extretes de: atzucac.cat
const vector<string> paraulesGrolleres = {"carallot", "malparit", "tros de quòniam", "abraçafanals", "botifler", "pixapins", "dròpol", "pallús", "cul d'olla", "poca solta", "banyut", "llepafils", "cagabandúrries", "tòtil", "pastanaga", "curt de gambals", "galifardeu", "estaquirot"};


class Grollera : public Paraula{
public:
    Grollera(string s);
    string contingut() const;
};



#endif //GROLLERA_H
