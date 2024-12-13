#include <iostream>
#include <cstring>
#include "clsArchivoAlumnos.h"

ArchivoAlumno::ArchivoAlumno(const char *n)
{
    strcpy(nombre,n);
}
bool ArchivoAlumno::guardar(Alumnos alumno)
{
    FILE *p;
    p=fopen(nombre, "ab");
    if(p==nullptr)
    {
        return false;
    }
    fwrite(&alumno, sizeof alumno, 1, p);
    fclose(p);
    return true;
}
Alumnos ArchivoAlumno::leer(int posicion)
{
    FILE *p;
    Alumnos obj;
    p=fopen(nombre,"rb");
    if(p==nullptr)
    {
        obj.setLegajo(-2);
        return obj;
    }
    if(posicion<0)
    {
        obj.setDniPersona(-1);
        obj.setLegajo(-1);
        fclose(p);
        return obj;
    }


    fseek(p, sizeof obj * posicion, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}
int ArchivoAlumno::cantidadDeRegistros()
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
    return tam/sizeof (Alumnos);
}


bool ArchivoAlumno::modificarRegistro(Alumnos obj, int pos)
{
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL)
    {
        return false;
    }
    fseek(p, pos * sizeof (Alumnos), 0);
    fwrite(&obj, sizeof (Alumnos), 1, p);
    fclose(p);
    return true;
}




bool ArchivoAlumno::eliminarRegistro(Alumnos obj, int pos)
{
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Alumnos) * pos,0);
    fread(&obj, sizeof(Alumnos), 1, p);

    obj.setActivo(false);

    fseek(p, sizeof(Alumnos) * pos, 0);
    bool ok = fwrite(&obj, sizeof(Alumnos), 1, p);
    fclose(p);

    return ok;
}



int ArchivoAlumno::buscarRegistroPorDni(int dni)
{
    int cantidad = cantidadDeRegistros();
    for(int i = 0; i < cantidad; i ++)
    {
        Alumnos Alumnos = leer(i);
        if(Alumnos.getActivo() && Alumnos.getDniPersona() == dni)
        {
            return i;
        }
    }
    return -1;
}

int ArchivoAlumno::buscarRegistroPorLegajo(int legajo)
{
    int cantidad = cantidadDeRegistros();
    for(int i = 0; i < cantidad; i ++)
    {
        Alumnos Alumnos = leer(i);
        if(Alumnos.getActivo() && Alumnos.getLegajo() == legajo)
        {
            return i;
        }
    }
    return -1;
}

void ArchivoAlumno::listarRegistros()
{
    Alumnos obj;
    ArchivoAlumno reg;
    int cant;
    cant = reg.cantidadDeRegistros();
    for(int i=0; i<cant; i++)
    {
        obj = reg.leer(i);
        if(obj.getActivo())
        {
            obj.mostrar();
            std::cout<<std::endl<<"------------------------------------------------------------"<<std::endl<<std::endl;
        }
    }
}


