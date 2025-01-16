//
// Created by Propietario on 14/1/2025.
//

#include <iostream>

#ifndef PARAULA_H
#define PARAULA_H

using namespace std;

class Paraula {
   public:
        Paraula (string p);
        string contingut() const;
   protected:
     string sequencia;
};



#endif //PARAULA_H
