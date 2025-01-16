//
// Created by Propietario on 14/1/2025.
//

#include "Grollera.h"

string contingut()const{
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distrib(0, paraulesGrolleres.size()+1);
  int randomNumber = distrib(gen);
  return paraulesGrolleres[randomNumber];
}