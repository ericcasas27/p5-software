//
// Created by Propietario on 14/1/2025.
//

#ifndef MODERADOR_H
#define MODERADOR_H
#include "UsuariRegistrat.h"
#include "Text.h"


class Moderador : public UsuariRegistrat{
    Moderador(string nick, string passw, int idM);

    void modificarText(Text *t);
};



#endif //MODERADOR_H
