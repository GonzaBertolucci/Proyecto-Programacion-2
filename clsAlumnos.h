#ifndef CLSALUMNO_H_INCLUDED
#define CLSALUMNO_H_INCLUDED
#include "clsPersona.h"

class Alumnos : public Persona
{
protected:
    int legajo;
    int gradoEscolar;
    int asistencias;

    bool activo;
public:
    Alumnos();
    void cargar();
    void mostrar();

    bool modificarDni();
    bool modificarLegajo();
    bool modificarNombre();
    bool modificarApellido();
    bool modificarFechaDeNacimiento();
    bool modificarGrado();
    bool modificarAsistencias();

    void setLegajo(int l);
    void setGradoEscolar(int gE);
    void setAsistencias(int a);
    void setActivo(bool act);
    void setParticipacion(bool p);

    int getLegajo();
    int getGradoEscolar();
    int getAsistencias();
    bool getActivo();
};

#endif // CLSALUMNO_H_INCLUDED
