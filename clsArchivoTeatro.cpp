#include<iostream>
#include<cstring>
#include "clsArchivoTeatro.h"


ArchivoTeatro::ArchivoTeatro(const char *n)
{
    strcpy(nombre, n);
}
bool ArchivoTeatro::guardar(Teatros Teatro)
{
    FILE *p;
    p= fopen(nombre, "ab");
    if(p==NULL)
    {
        return false;
    }
    fwrite(&Teatro,sizeof Teatro, 1, p);
    fclose(p);
    return true;
}
Teatros ArchivoTeatro::leer(int posicion)
{
    FILE *p;
    Teatros obj;
    p= fopen(nombre, "rb");
    if(p==NULL)
    {

        obj.setCodTeatro(-2);
        return obj;

    }
    if(posicion<0){
      obj.setCodTeatro(-1);
      return obj;
    }

    fseek(p, sizeof obj*posicion, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}
int ArchivoTeatro::cantidadDeRegistros()
{
    FILE *p;
    p= fopen(nombre, "rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p, 0, 2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof (Teatros);
}
bool ArchivoTeatro::modificarRegistro(Teatros obj,int pos)
{
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL)
    {
        return false;
    }
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}
bool ArchivoTeatro::eliminarRegistro(Teatros obj,int pos)
{
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Teatros) * pos,0);
    fread(&obj, sizeof(Teatros), 1, p);

    obj.setActivo(false);

    fseek(p, sizeof(Teatros) * pos, 0);
    bool ok = fwrite(&obj, sizeof(Teatros), 1, p);
    fclose(p);

    return ok;
}
int ArchivoTeatro::buscarRegistro(int codTeatro)
{
    ArchivoTeatro reg;
    Teatros Teatro;

    int cantidad = reg.cantidadDeRegistros();
    for(int i = 0; i < cantidad; i ++){
        Teatro = reg.leer(i);
        if(Teatro.getActivo() && Teatro.getCodTeatro() == codTeatro){
            return i;
        }
    }
    return -1;
}
void ArchivoTeatro::listarRegistros()
{
Teatros obj;
ArchivoTeatro reg;
    int cant;
    cant = reg.cantidadDeRegistros();
    for(int i=0; i<cant; i++){
        obj = reg.leer(i);
        if(obj.getActivo()){
            obj.mostrar();
            std::cout<<std::endl<<"------------------------------------------------------------"<<std::endl<<std::endl;
        }
    }
}
