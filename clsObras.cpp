#include <iostream>
#include <cstring>
#include "clsArchivoObras.h"
#include "clsObras.h"
#include "clsFecha.h"
#include "Funciones.h"
#include <limits>

using namespace std;

Obras::Obras()
{
    codObra=0;
    activo=false;


}

void Obras::cargar() {
    ArchivoObras reg;
    Obras obj;

    // Validar código de obra
    do {
        cout << "INGRESE EL CODIGO DE OBRA: ";
        cin >> codObra;
        if (cin.fail() || codObra <= 0) {
            cout << "ERROR: EL CÓDIGO DEBE SER UN NÚMERO POSITIVO." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        obj = reg.leer(reg.buscarRegistro(codObra));
        if (codObra == obj.getCodObra() && obj.getActivo()) {
            cout << "ERROR: ESTE CÓDIGO YA ESTÁ REGISTRADO." << endl;
        }
    } while (codObra <= 0 || (codObra == obj.getCodObra() && obj.getActivo()));

    // Leer el nombre de la obra (sin validación estricta)
    cout << "INGRESE EL NOMBRE DE LA OBRA: ";
    cargarCadena(nombreDeObra, 59);

    // Leer el género de la obra (sin validación estricta)
    cout << "INGRESE EL GENERO: (COMEDIA / DRAMA / MUSICAL / OPERA)";
    cargarCadena(genero, 29);

    // Validar la fecha de realización
    cout << "INGRESE LA FECHA DE REALIZACION"<<endl;
    fechaDeObra.cargar();

    activo = true; // Marcar la obra como activa
}


void Obras::mostrar()
{

    if(activo)
    {
        cout<<endl<<"EL CODIGO DE OBRA ES: " <<codObra;

        cout<<endl<<"EL NOMBRE DE LA OBRA ES: "<<nombreDeObra;
        cout<<endl<<"EL GENERO ES: "<<genero;
        cout<<endl<<"LA FECHA DE OBRA ES: ";
        fechaDeObra.mostrar();
    }
    else
    {
        cout<<endl<<"ESTE REGISTRO FUE ELIMINADO...";
    }
}

bool Obras::modificarCodObra() {
    ArchivoObras reg;
    Obras obj;
    int nuevoCodigo;

    do {
        cout << "INGRESE EL NUEVO CODIGO DE OBRA: ";
        cin >> nuevoCodigo;

        if (cin.fail() || nuevoCodigo <= 0) {
            cout << "ERROR: EL CODIGO DEBE SER UN NUMERO POSITIVO." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        obj = reg.leer(reg.buscarRegistro(nuevoCodigo));
        if (nuevoCodigo == obj.getCodObra() && obj.getActivo()) {
            cout << "ERROR: ESTE CODIGO YA ESTÁ REGISTRADO." << endl;
        }

    } while (nuevoCodigo <= 0 || (nuevoCodigo == obj.getCodObra() && obj.getActivo()));

    codObra = nuevoCodigo;
    cout << "CODIGO MODIFICADO CON EXITO." << endl;
    return true;
}

bool Obras::modificarNombre()
{
    char nuevoNombre[50];


    cout<<endl<<"INGRESAR EL NUEVO NOMBRE DE LA OBRA: ";
    cargarCadena(nuevoNombre,50);

    setNombreDeObra(nuevoNombre);
    return true;
}
bool Obras::modificarGenero()
{
    char nuevoGenero[30];


    cout<<endl<<"INGRESAR EL NUEVO GENERO DE LA OBRA: ";
    cargarCadena(nuevoGenero,30);

    setGenero(nuevoGenero);
    return true;
}
bool Obras::modificarFecha()
{
    Fecha nuevaFecha;

    nuevaFecha.cargar();
    setFechaDeObra(nuevaFecha);
    return true;
}


void Obras::setCodObra(int cO)
{
    codObra=cO;
}

void Obras::setNombreDeObra(const char* nO)
{
    strcpy(nombreDeObra, nO);
}
void Obras::setGenero(const char* g)
{
    strcpy(genero, g);
}
void Obras::setFechaDeObra(Fecha fO)
{
    fechaDeObra = fO;
}


void Obras::setActivo(bool a)
{
    activo=a;
}
int Obras::getCodObra()
{
    return codObra;
}

char Obras::getNombreDeObra()
{
    return *nombreDeObra;
}
char Obras::getGenero()
{
    return *genero;
}
Fecha Obras::getFechaDeObra()
{
    return fechaDeObra;
}

bool Obras::getActivo()
{
    return activo;
}




