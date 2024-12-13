#include <iostream>
#include <cstring>
#include "clsArchivoObrasXTeatro.h"
#include "clsObrasXTeatro.h"

using namespace std;

ArchivoObrasXTeatro::ArchivoObrasXTeatro(const char *n)
{
    strcpy(nombre,n);
}
bool ArchivoObrasXTeatro::guardar(ObrasXTeatro conjunto)
{
    FILE *p;
     p=fopen(nombre,"ab");
     if(p==NULL){
        return false;
     }
     fwrite(&conjunto,sizeof conjunto,1,p);
     fclose(p);
     return true;
}
ObrasXTeatro ArchivoObrasXTeatro::leer(int pos)
{
     ObrasXTeatro obj;
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL){
            obj.setcCodObra(-2);
            obj.setCodTeatro(-2);
        return obj;
    }
    if(pos<0){
     obj.setcCodObra(-1);
            obj.setCodTeatro(-1);

            fclose(p);
            return obj;
    }
   fseek(p, sizeof(ObrasXTeatro) * pos, SEEK_SET); // Se posiciona en el registro indicado
    fread(&obj, sizeof(ObrasXTeatro), 1, p);

    fclose(p);

    return obj;
}

int ArchivoObrasXTeatro::cantidadDeRegistros()
{
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL)
    {
        return -1;
    }
    fseek(p, 0, 2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof (ObrasXTeatro);
}
int ArchivoObrasXTeatro::buscarRegistroPorCodTeatro(int codTeatro)
{
    int cantidad = cantidadDeRegistros();
    for(int i = 0; i < cantidad; i ++){
        ObrasXTeatro obj = leer(i);
        if(obj.getActivo() && obj.getCodTeatro() == codTeatro){
            return i;
        }
    }
    return -1;

}
int ArchivoObrasXTeatro::buscarRegistroPorCodObra(int codObra)
{
    int cantidad = cantidadDeRegistros();
    for(int i = 0; i < cantidad; i ++){
        ObrasXTeatro obj = leer(i);
        if(obj.getActivo() && obj.getCodObra() == codObra){
            return i;
        }
    }
    return -1;
}
int ArchivoObrasXTeatro::buscarRegistro(int codObra,int codTeatro)
{
   int cantidad = cantidadDeRegistros();
    for(int i = 0; i < cantidad; i ++){
        ObrasXTeatro obj = leer(i);
        if((obj.getActivo()) && (obj.getCodObra() == codObra)&&(obj.getCodTeatro()==codTeatro)){
            return i;
        }
    }
    return -1;
}
bool ArchivoObrasXTeatro::eliminarRegistro(ObrasXTeatro obj,int pos)
{

 FILE *p = fopen(nombre, "r+b");
    if (p == NULL) {
        return false;
    }
    fseek(p, sizeof(ObrasXTeatro) * pos,0);
    fread(&obj, sizeof(ObrasXTeatro), 1, p);

    obj.setActivo(false);

    fseek(p, sizeof(ObrasXTeatro) * pos, 0);
    bool ok = fwrite(&obj, sizeof(ObrasXTeatro), 1, p);
    fclose(p);

    return ok;
}
