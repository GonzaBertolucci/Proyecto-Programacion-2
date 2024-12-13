#ifndef CLSARCHIVOOBRASXTEATRO_H_INCLUDED
#define CLSARCHIVOOBRASXTEATRO_H_INCLUDED
#include "clsObrasXTeatro.h"

class ArchivoObrasXTeatro{
private:
    char nombre[30];
public:
    ArchivoObrasXTeatro(const char *n="obrasXteatro.dat");
    bool guardar(ObrasXTeatro conjunto);
    ObrasXTeatro leer(int pos);
    int cantidadDeRegistros();
    int buscarRegistroPorCodTeatro(int codTeatro);
    int buscarRegistroPorCodObra(int codObra);
    int buscarRegistro(int codObra,int codTeatro);
    bool eliminarRegistro(ObrasXTeatro obj,int pos);
};


#endif // CLSARCHIVOOBRASXTEATRO_H_INCLUDED
