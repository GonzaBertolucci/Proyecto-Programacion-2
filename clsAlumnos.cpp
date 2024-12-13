#include <iostream>
#include "clsAlumnos.h"
#include "clsArchivoAlumnos.h"
#include "Funciones.h"
#include <limits>
#include <cstring>

using namespace std;

Alumnos::Alumnos()
{
    legajo=-1;
    gradoEscolar=-1;
    asistencias=0;
    activo=false;

}

void Alumnos::cargar() {
    Alumnos obj;
    ArchivoAlumno reg;

    // Llamar al método cargar() de la clase base Persona para validar DNI, nombre, apellido y fecha de nacimiento
    Persona::cargar();

    // Validar el legajo
    do {
        cout << "INGRESE EL LEGAJO DEL ALUMNO: ";
        cin >> legajo;
        if (cin.fail()) {
            cout << "ERROR: EL LEGAJO DEBE SER UN NÚMERO ENTERO POSITIVO." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        obj = reg.leer(reg.buscarRegistroPorLegajo(legajo));

        if (legajo <= 0) {
            cout << "ERROR: EL LEGAJO DEBE SER MAYOR A 0." << endl;
        } else if (legajo == obj.getLegajo() && obj.getActivo()) {
            cout << "ERROR: ESTE LEGAJO YA ESTÁ REGISTRADO." << endl;
        }

    } while (legajo <= 0 || (legajo == obj.getLegajo() && obj.getActivo()));

    // Validar el grado escolar
    do {
        cout << "EN QUE GRADO SE ENCUENTRA EL ALUMNO: ";
        cin >> gradoEscolar;
        if (cin.fail() || gradoEscolar <= 0) {
            cout << "ERROR: EL GRADO ESCOLAR DEBE SER UN NUMERO MAYOR A 0." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (gradoEscolar <= 0);

    // Solicitar y validar las asistencias
    do {
        cout << "INGRESE EL NUMERO DE ASISTENCIAS DEL ALUMNO: ";
        cin >> asistencias;
        if (cin.fail() || asistencias < 0) {
            cout << "ERROR: LAS ASISTENCIAS DEBEN SER UN NUMERO NO NEGATIVO." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (asistencias < 0);

    activo = true; // Marcar al alumno como activo
}

void Alumnos::mostrar()
{
    if(activo)
    {
        Persona::mostrar();
        cout<<endl<<"EL LEGAJO ES: "<<legajo;
        cout<<endl<<"EL GRADO ESCOLAR DEL ALUMNO ES: "<<gradoEscolar<<"º";
        cout<<endl<<"EL ALUMNO TIENE: "<<asistencias<<" ASISTENCIAS";
    }
}


// Método para modificar el DNI del alumno con validación
bool Alumnos::modificarDni() {
    ArchivoAlumno arc;
    Alumnos obj;

    int nuevoDni;
    do {
        cout << "INTRODUCIR EL NUEVO DNI (NUMERO ENTERO): ";
        cin >> nuevoDni;

        // Validar que sea un número positivo
        if (cin.fail() || nuevoDni <= 0) {
            cout << "ERROR: EL DNI DEBE SER UN NUMERO ENTERO POSITIVO." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
            system("cls");
            continue;
        }

        obj = arc.leer(arc.buscarRegistroPorDni(nuevoDni));

        // Verificar si ya existe un registro activo con ese DNI
        if ((nuevoDni == obj.getDniPersona()) && obj.getActivo()) {
            cout << "ERROR: ESTE DNI YA ESTÁ REGISTRADO." << endl;
        } else {
            setDniPersona(nuevoDni);
            return true;
        }
    } while (true);
}

// Metodo para modificar el legajo del alumno con validación
bool Alumnos::modificarLegajo() {
    ArchivoAlumno arc;
    Alumnos obj;

    int nuevoLegajo;
    do {
        cout << "INTRODUCIR EL NUEVO LEGAJO: ";
        cin >> nuevoLegajo;

        //Validar que sea un numero positivo
        if (cin.fail() || nuevoLegajo <= 0) {
            cout << "ERROR: EL LEGAJO DEBE SER UN NUMERO ENTERO POSITIVO." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        obj = arc.leer(arc.buscarRegistroPorLegajo(nuevoLegajo));

        // Verificar si ya existe un registro activo con ese legajo
        if ((nuevoLegajo == obj.getLegajo()) && obj.getActivo()) {
            cout << "ERROR: ESTE LEGAJO YA ESTA REGISTRADO." << endl;
        } else {
            setLegajo(nuevoLegajo);
            return true;
        }
    } while (true);
}

bool Alumnos::modificarNombre() {
    char nuevoNombre[50];
    cout << "INGRESE EL NUEVO NOMBRE: ";
    cargarCadena(nuevoNombre, 50);
    setNombre(nuevoNombre);
    return true;
}

bool Alumnos::modificarApellido() {
    char nuevoApellido[50];
    cout << "INGRESE EL NUEVO APELLIDO: ";
    cargarCadena(nuevoApellido, 50);
    setApellido(nuevoApellido);
    return true;
}

// Método para modificar la fecha de nacimiento con validación
bool Alumnos::modificarFechaDeNacimiento() {
    Fecha nuevaFecha;
    cout << "INGRESE LA NUEVA FECHA DE NACIMIENTO:" << endl;
    nuevaFecha.cargar();
    setFechaDeNacimiento(nuevaFecha);
    return true;
}

// Método para modificar el grado escolar con validación
bool Alumnos::modificarGrado() {
    int nuevoGrado;
    do {
        cout << "INGRESE EL NUEVO GRADO ESCOLAR: ";
        cin >> nuevoGrado;
        if (cin.fail() || nuevoGrado <= 0) {
            cout << "ERROR: EL GRADO ESCOLAR DEBE SER MAYOR A 0." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            setGradoEscolar(nuevoGrado);
            return true;
        }
    } while (true);
}

// Método para modificar las asistencias con validación
bool Alumnos::modificarAsistencias() {
    int nuevasAsistencias;
    do {
        cout << "INGRESE EL NUEVO NUMERO DE ASISTENCIAS: ";
        cin >> nuevasAsistencias;
        if (cin.fail() || nuevasAsistencias < 0) {
            cout << "ERROR: LAS ASISTENCIAS DEBEN SER UN NUMERO NO NEGATIVO." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            setAsistencias(nuevasAsistencias);
            return true;
        }
    } while (true);
}

void Alumnos::setLegajo(int l)
{
    legajo=l;
}
void Alumnos::setGradoEscolar(int gE)
{
    gradoEscolar=gE;
}
void Alumnos::setAsistencias(int a)
{
    asistencias=a;
}
void Alumnos::setActivo(bool act)
{
    activo=act;
}

int Alumnos::getLegajo()
{
    return legajo;
}
int Alumnos::getGradoEscolar()
{
    return gradoEscolar;
}
int Alumnos::getAsistencias()
{
    return asistencias;
}

bool Alumnos::getActivo()
{
    return activo;
}




