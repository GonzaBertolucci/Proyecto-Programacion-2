#ifndef CLSTEATRO_H_INCLUDED
#define CLSTEATRO_H_INCLUDED



///#include "clsTeatro.h" no va aca

class Teatros{
protected:
    int codTeatro;
    char nombreDelTeatro[50]; //estaba escrito con espacios (nombre del teatro)
    char direccion[50];
    bool activo;
public:
    Teatros();
    void cargar();
    void mostrar();

    bool modificarCodTeatro();
    bool modificarNombreDelTeatro();
    bool modificarDireccion();

    void setCodTeatro(int cT);
    void setNombreDelTeatro(const char *n);
    void setDireccion(const char *d);
    void setActivo(bool a);

    int getCodTeatro();
    char getNombreDelTeatro();
    char getDireccion();
    bool getActivo();



};

#endif // CLSTEATRO_H_INCLUDED
