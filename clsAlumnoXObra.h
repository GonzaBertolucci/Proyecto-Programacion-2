#ifndef CLSALUMNOXOBRA_H_INCLUDED
#define CLSALUMNOXOBRA_H_INCLUDED

class AlumnoXObra{
private:
    int legajo,codObra;
    bool activo;
public:
    AlumnoXObra();

    void setLegajo(int l);
    void setcCodObra(int cO);
    void setActivo(bool a);

    int getLegajo();
    int getCodObra();
    bool getActivo();

     void cargar();
     void mostrarObras();
};


#endif // CLSALUMNOXOBRA_H_INCLUDED
