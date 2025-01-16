#include <iostream>
#include "Paraula.h"

#ifndef PRAUALA_H
#define PRAUALA_H

using namespace std;

class Prauala : public Paraula {
public:
    Prauala(string s);
    string contingut() const;

};



#endif //PRAUALA_H
