#ifndef CLSARCHIVOALUMNO_H_INCLUDED
#define CLSARCHIVOALUMNO_H_INCLUDED
#include "clsAlumnos.h"

class ArchivoAlumno{
private:
    char nombre[30];

public:
    ArchivoAlumno(const char *n="alumnos.dat");
    bool guardar(Alumnos alumno);
    Alumnos leer(int posicion);
    int cantidadDeRegistros();
    bool modificarRegistro(Alumnos obj,int posicion);
    bool eliminarRegistro(Alumnos obj,int posicion);
    int buscarRegistroPorDni(int dni);
    int buscarRegistroPorLegajo(int legajo);
    void listarRegistros();


    };

#endif // CLSARCHIVOALUMNO_H_INCLUDED
