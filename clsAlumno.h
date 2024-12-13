#ifndef CLSALUMNO_H_INCLUDED
#define CLSALUMNO_H_INCLUDED
#include "clsPersona.h"

class Alumno : public Persona
{
protected:
    int legajo;
    int gradoEscolar;
    int asistencias;
public:
    void cargar();
    void mostrar();
    void setLegajo(int l);
    void setGradoEscolar(int gE);
    void setAsistencias(int a);
    int getLegajo();
    int getGradoEscolar();
    int getAsistencias();
};

#endif // CLSALUMNO_H_INCLUDED
