#include<iostream>
#include<cstring>
#include "clsArchivoObras.h"
#include "clsArchivoAlumnoXObra.h"


ArchivoObras::ArchivoObras(const char *n)
{
    strcpy(nombre, n);
}
bool ArchivoObras::guardar(Obras obra)
{
    FILE *p;
    p= fopen(nombre, "ab");
    if(p==NULL)
    {
        return false;
    }
    fwrite(&obra,sizeof obra, 1, p);
    fclose(p);
    return true;
}
Obras ArchivoObras::leer(int posicion)
{
    FILE *p;
    Obras obj;
    p= fopen(nombre, "rb");
    if(p==NULL)
    {

        obj.setCodObra(-2);
        return obj;

    }
    if(posicion<0){
      obj.setCodObra(-1);
      return obj;
    }

    fseek(p, sizeof obj*posicion, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}
int ArchivoObras::cantidadDeRegistros()
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
    return tam/sizeof (Obras);
}
bool ArchivoObras::modificarRegistro(Obras obj,int pos)
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
bool ArchivoObras::eliminarRegistro(Obras obj,int pos)
{
    FILE *p = fopen(nombre, "rb+");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Obras) * pos,0);
    fread(&obj, sizeof(Obras), 1, p);

    obj.setActivo(false);

    fseek(p, sizeof(Obras) * pos, 0);
    bool ok = fwrite(&obj, sizeof(Obras), 1, p);
    fclose(p);

    return ok;
}
int ArchivoObras::buscarRegistro(int codObra)
{
    ArchivoObras reg;
    Obras obra;

    int cantidad = reg.cantidadDeRegistros();
    for(int i = 0; i < cantidad; i ++){
        obra = reg.leer(i);
        if(obra.getActivo() && obra.getCodObra() == codObra){
            return i;
        }
    }
    return -1;
}


void ArchivoObras::listarRegistros() {
    Obras obj;
    ArchivoAlumnoXObra archivoAlumnoXObra;
    AlumnoXObra alumnoObra;

    int cant = cantidadDeRegistros();
    for (int i = 0; i < cant; i++) {
        obj = leer(i);
        if (obj.getActivo()) {
            obj.mostrar();
            std::cout<<"\n";
            // Mostrar legajos de los alumnos inscritos
            std::cout << "ALUMNOS INSCRIPTOS:\n";
            bool tieneAlumnos = false;
            int cantidadAlumnos = archivoAlumnoXObra.cantidadDeRegistros();
            for (int j = 0; j < cantidadAlumnos; j++) {
                alumnoObra = archivoAlumnoXObra.leer(j);
                if (alumnoObra.getCodObra() == obj.getCodObra() && alumnoObra.getActivo()) {
                    std::cout << "LEGAJO: " << alumnoObra.getLegajo() << "\n";
                    tieneAlumnos = true;
                }
            }

            if (!tieneAlumnos) {
                std::cout << "NO HAY ALUMNOS INSCRIPTOS EN ESTA OBRA.\n";
            }

            std::cout << "------------------------------------------------------------\n";
        }
    }
}

/**int ArchivoObras::buscarPorNombre(const char* nombre) {
    ArchivoObras reg;
    Obras obra;

    for (int i = 0; i < cantidadDeObras; ++i) {
        obra = reg.leer(i);
        // Compara las cadenas
        if (strcmp(nombre, obra.getNombreDeObra()) == 0) {
            return i; // Devuelve la posición si coincide
        }
    }

    // Si no se encuentra ninguna coincidencia, devuelve -1
    return -1;
}
*/

