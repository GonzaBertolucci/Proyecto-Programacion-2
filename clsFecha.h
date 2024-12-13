#ifndef CSLFECHA_H_INCLUDED
#define CSLFECHA_H_INCLUDED

class Fecha{
private:
    int dia;
    int mes;
    int anio;
public:
    void cargar();
    void mostrar();
    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);
    int getDia();
    int getMes();
    int getAnio();
};

#endif // CSLFECHA_H_INCLUDED
