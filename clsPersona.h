#ifndef CLSPERSONA_H_INCLUDED
#define CLSPERSONA_H_INCLUDED

#include "clsFecha.h"

class Persona{
protected:
     int dniPersona;
    char nombre[50];
    char apellido[50];
    Fecha fechaDeNacimiento;

public:
    Persona();
    int cargar();
    void mostrar();
    void setFechaDeNacimiento(Fecha f);
    void setDniPersona(long long int dP);
    void setNombre(const char *n);
    void setApellido(const char *a);
    long long int getDniPersona();
    char getNombre();
    char getApellido();
    Fecha getFechaDeNacimiento();


};

#endif // CLSPERSONA_H_INCLUDED
