#ifndef CLSARCHIVOALUMNOXOBRA_H_INCLUDED
#define CLSARCHIVOALUMNOXOBRA_H_INCLUDED
#include "clsAlumnoXObra.h"

class ArchivoAlumnoXObra{
private:
    char nombre[30];
public:
    ArchivoAlumnoXObra(const char *n="alumnosXobra.dat");
    bool guardar(AlumnoXObra conjunto);
    AlumnoXObra leer(int pos);
    int cantidadDeRegistros();
    int buscarRegistroPorLegajo(int legajo);
    int buscarRegistroPorCodObra(int codObra);
    int buscarRegistro(int codObra,int legajo);
    bool eliminarRegistro(AlumnoXObra obj,int pos);

};

#endif // CLSARCHIVOALUMNOXOBRA_H_INCLUDED
