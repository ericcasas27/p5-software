#include "Paraula.h"
#include <iostream>

#ifndef TALQUAL_H
#define TALQUAL_H



class TalQual : public Paraula{
public:
    TalQual(string s);
    string contingut() const;

};



#endif //TALQUAL_H
