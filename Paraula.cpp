//
// Created by Propietario on 14/1/2025.
//

#include "Paraula.h"

Paraula::Paraula(string p){ //ctor genèric
  sequencia= p;
}

string Paraula::contingut() const{
  return sequencia;
}