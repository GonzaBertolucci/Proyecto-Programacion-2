#ifndef CLSOBRASXTEATRO_H_INCLUDED
#define CLSOBRASXTEATRO_H_INCLUDED

class ObrasXTeatro{
private:
    int  codTeatro,codObra;
    bool activo;
public:
    ObrasXTeatro();

    void setCodTeatro(int l);
    void setcCodObra(int cO);
    void setActivo(bool a);

    int getCodTeatro();
    int getCodObra();
    bool getActivo();

    void cargar();
};
#endif // CLSOBRASXTEATRO_H_INCLUDED
