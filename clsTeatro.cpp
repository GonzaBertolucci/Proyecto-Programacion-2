#include <iostream>
#include <cstring>
#include "clsTeatro.h"
#include "clsArchivoTeatro.h"
#include "Funciones.h"
#include <limits>

using namespace std;

Teatros::Teatros()
{
    codTeatro=0;
    strcpy(nombreDelTeatro,"vacio");
    strcpy(direccion,"vacio");
}
void Teatros::cargar() {
    ArchivoTeatro archivo;
    Teatros teatroExistente;

    // Validar código del teatro
    do {
        cout << "INGRESE EL CODIGO DEL TEATRO: ";
        cin >> codTeatro;

        if (cin.fail() || codTeatro <= 0) {
            cout << "ERROR: EL CODIGO DEBE SER UN NUMERO POSITIVO." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        teatroExistente = archivo.leer(archivo.buscarRegistro(codTeatro));
        if (codTeatro == teatroExistente.getCodTeatro() && teatroExistente.getActivo()) {
            cout << "ERROR: ESTE CODIGO YA ESTA REGISTRADO." << endl;
        }
    } while (codTeatro <= 0 || (codTeatro == teatroExistente.getCodTeatro() && teatroExistente.getActivo()));

    // Leer el nombre del teatro
    cout << "INGRESE EL NOMBRE DEL TEATRO: ";
    cargarCadena(nombreDelTeatro, 50);

    // Leer la dirección del teatro
    cout << "INGRESE LA DIRECCIÓN DEL TEATRO: ";
    cargarCadena(direccion, 100);

    activo = true; // Marcar el teatro como activo
}


void Teatros::mostrar()
{
    if(activo)
    {
        setlocale(LC_ALL,"");
        cout<<"EL CODIGO DEL TEATRO ES "<<codTeatro;
        cout<<endl<<"EL NOMBRE DEL TEATRO ES: "<<nombreDelTeatro;
        cout<<endl<<"LA DIRECCION ES : "<<direccion<<endl;

    }
    else
    {
        cout<< "ESTE REGISTRO FUE ELIMINADO..."<<endl;
    }
}

bool Teatros::modificarCodTeatro() {
    ArchivoTeatro archivo;
    Teatros teatroExistente;
    int nuevoCodigo;

    do {
        cout << "INTRODUCIR EL NUEVO CODIGO DEL TEATRO: ";
        cin >> nuevoCodigo;

        if (cin.fail() || nuevoCodigo <= 0) {
            cout << "ERROR: EL COIGO DEBE SER UN NUMERO POSITIVO." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        teatroExistente = archivo.leer(archivo.buscarRegistro(nuevoCodigo));
        if (nuevoCodigo == teatroExistente.getCodTeatro() && teatroExistente.getActivo()) {
            cout << "ERROR: ESTE CODIGO YA ESTA REGISTRADO." << endl;
        }
    } while (nuevoCodigo <= 0 || (nuevoCodigo == teatroExistente.getCodTeatro() && teatroExistente.getActivo()));

    codTeatro = nuevoCodigo;
    return true;
}

bool Teatros::modificarNombreDelTeatro()
{
    char nuevoNombre[50];


    cout<<endl<<"INGRESAR EL NUEVO NOMBRE: ";
    cargarCadena(nuevoNombre,50);

    setNombreDelTeatro(nuevoNombre);
    return true;
}
bool Teatros::modificarDireccion()
{
    char nuevaDireccion[50];


    cout<<endl<<"INGRESAR LANUEVA DIRECCION: ";
    cargarCadena(nuevaDireccion,50);

    setDireccion(nuevaDireccion);
    return true;
}

void Teatros::setCodTeatro(int cT)
{
    codTeatro=cT;
}
void Teatros::setNombreDelTeatro(const char *nT)
{
    strcpy(nombreDelTeatro,nT);
}
void Teatros::setDireccion(const char *d)
{
    strcpy(direccion,d);
}


void Teatros::setActivo(bool a)
{
    activo=a;
}
int Teatros::getCodTeatro()
{
    return codTeatro;
}

char Teatros::getNombreDelTeatro()
{
    return *nombreDelTeatro;
}
char Teatros::getDireccion()
{
    return *direccion;
}

bool Teatros::getActivo()
{
    return activo;
}


