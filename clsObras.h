#ifndef CLSOBRAS_H_INCLUDED
#define CLSOBRAS_H_INCLUDED
#include"clsFecha.h"

class Obras
{
private:
    int codObra;
    char nombreDeObra[50];
    char genero[30];
    Fecha fechaDeObra;
    bool activo;
public:
    Obras();
    void cargar();
    void mostrar();

    bool modificarCodObra();
    bool modificarNombre();
    bool modificarGenero();
    bool modificarFecha();

    void setCodObra(int cO);
    void setNombreDeObra(const char *nO);
    void setGenero(const char *g);
    void setFechaDeObra(Fecha fO);
    void setActivo(bool a);

    int getCodObra();
    char getNombreDeObra();
    char getGenero();
    Fecha getFechaDeObra();
    bool getActivo();
};


#endif // CLSOBRAS_H_INCLUDED
