//
// Created by Propietario on 14/1/2025.
//

#include <iostream>


#ifndef TEXT_H
#define TEXT_H

using namespace std;

class Text {
    public:
        Text();
        Text(int idT,string cont);

        string obtCont();
        int obtId();

        void modificar(string s);
        bool buit()const;
    protected:

        string contingut;
        int id;
};



#endif //TEXT_H
