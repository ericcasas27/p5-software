//
// Created by Propietario on 14/1/2025.
//

#include "Prauala.h"

string Prauala::contingut() const{
  string s = sequencia; bool b =false;
  int t= s.size()/2;
  if(t>2){
    char a1 = s[t];
    char a2 = s[t+1];
    s[t]=a1;
    s[t+1]=a2;
  }
  return s;
}