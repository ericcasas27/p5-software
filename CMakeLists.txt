cmake_minimum_required(VERSION 3.29)
project(p5_software)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(p5_software
    Grollera.cpp
    Grollera.h
    Imatge.cpp
    Imatge.h
    main.cpp
    MissatgePrivat.cpp
    MissatgePrivat.h
    Moderador.cpp
    Moderador.h
    NoMostrades.cpp
    NoMostrades.h
    Paraula.cpp
    Paraula.h
    Prauala.cpp
    Prauala.h
    TalQual.cpp
    TalQual.h
    Text.cpp
    Text.h
    TipusPrivacitat.h
    TipusRelacio.h
    UsuariRegistrat.cpp
    UsuariRegistrat.h
    Video.cpp
    Video.h)
