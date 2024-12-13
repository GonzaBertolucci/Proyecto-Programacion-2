#ifndef CLSARCHIVOOBRAS_H_INCLUDED
#define CLSARCHIVOOBRAS_H_INCLUDED
#include "clsObras.h"

class ArchivoObras{
private:
    char nombre[30];
    Obras obra[100];  // almacenar las obras
    int cantidadDeObras;  // Cantidad de obras
public:
    ArchivoObras(const char *n="obras.dat");
    bool guardar(Obras obra);
    Obras leer(int posicion);
    int cantidadDeRegistros();
    bool modificarRegistro(Obras obj,int pos);
    bool eliminarRegistro(Obras obj,int pos);
     int buscarRegistro(int codObra);
    void listarRegistros();
    void listarObrasConAlumnos();
//    int buscarPorNombre(const char *nombre);

};

#endif // CLSARCHIVOOBRAS_H_INCLUDED
