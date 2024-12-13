#include <iostream>
#include <cstring>
#include "clsArchivoAlumnoXObra.h"
#include "clsAlumnoXObra.h"
using namespace std;

ArchivoAlumnoXObra::ArchivoAlumnoXObra(const char *n)
{
    strcpy(nombre,n);
}
bool ArchivoAlumnoXObra::guardar(AlumnoXObra conjunto)
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
AlumnoXObra ArchivoAlumnoXObra::leer(int pos)
{
    AlumnoXObra obj;
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL){
            obj.setLegajo(-2);
            obj.setcCodObra(-2);
        return obj;
    }
    if(pos<0){
     obj.setLegajo(-1);
            obj.setcCodObra(-1);
            fclose(p);
            return obj;
    }
   fseek(p, sizeof(AlumnoXObra) * pos, SEEK_SET); // Se posiciona en el registro indicado
    fread(&obj, sizeof(AlumnoXObra), 1, p);

    fclose(p);

    return obj;
}
int ArchivoAlumnoXObra::cantidadDeRegistros()
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
    return tam/sizeof (AlumnoXObra);
}
int ArchivoAlumnoXObra::buscarRegistroPorLegajo(int legajo){
int cantidad = cantidadDeRegistros();
    for(int i = 0; i < cantidad; i ++){
        AlumnoXObra obj = leer(i);
        if(obj.getActivo() && obj.getLegajo() == legajo){
            return i;
        }
    }
    return -1;

}

 int ArchivoAlumnoXObra::buscarRegistroPorCodObra(int codObra){
 int cantidad = cantidadDeRegistros();
    for(int i = 0; i < cantidad; i ++){
        AlumnoXObra obj = leer(i);
        if(obj.getActivo() && obj.getCodObra() == codObra){
            return i;
        }
    }
    return -1;
 }

 int ArchivoAlumnoXObra::buscarRegistro(int codObra,int legajo){
  int cantidad = cantidadDeRegistros();
    for(int i = 0; i < cantidad; i ++){
        AlumnoXObra obj = leer(i);
        if((obj.getActivo()) && (obj.getCodObra() == codObra)&&(obj.getLegajo()==legajo)){
            return i;
        }
    }
    return -1;
 }

 bool ArchivoAlumnoXObra::eliminarRegistro(AlumnoXObra obj,int pos){

 FILE *p = fopen(nombre, "r+b");
    if (p == NULL) {
        return false;
    }
    fseek(p, sizeof(AlumnoXObra) * pos,0);
    fread(&obj, sizeof(AlumnoXObra), 1, p);

    obj.setActivo(false);

    fseek(p, sizeof(AlumnoXObra) * pos, 0);
    bool ok = fwrite(&obj, sizeof(AlumnoXObra), 1, p);
    fclose(p);

    return ok;


 }
