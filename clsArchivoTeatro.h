
#ifndef CLSARCHIVOTEATRO_H_INCLUDED
#define CLSARCHIVOTEATRO_H_INCLUDED
#include "clsTeatro.h"

class ArchivoTeatro{
private:
    char nombre[30];

public:
    ArchivoTeatro(const char *n="teatro.dat");
    bool guardar(Teatros teatro);
    Teatros leer(int posicion);
    int cantidadDeRegistros();
    bool modificarRegistro(Teatros obj,int pos);
    bool eliminarRegistro(Teatros obj, int pos);
    int buscarRegistro(int codTeatro);
    void listarRegistros();

    };

#endif // CLSARCHIVOTEATRO_H_INCLUDED
