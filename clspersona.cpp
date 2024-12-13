#include <iostream>
#include <cstring>
#include <locale.h>
#include "clsPersona.h"
#include "Funciones.h"
#include "clsArchivoAlumnos.h"

using namespace std;

Persona::Persona(){
dniPersona=0;
strcpy(nombre,"vacio");
strcpy(apellido,"vacio");
}

int Persona::cargar()
{
    Alumnos obj;
    ArchivoAlumno reg;
    bool validacionExitosa = false;

    while (!validacionExitosa) {
        cout << " INGRESE EL DNI DEL ALUMNO: ";
        cin >> dniPersona;

        // Validar si hay errores en la entrada
        if (cin.fail()) {
            cin.clear(); // Restablece el estado de la entrada
            cin.ignore(1000, '\n'); // Limpia hasta 1000 caracteres o hasta un salto de línea
            cout << "POR FAVOR INGRESE UN NUMERO VALIDO PARA EL DNI." << endl;
            system("pause");
            system("cls");
            continue; // Vuelve a pedir el DNI
        }

        obj = reg.leer(reg.buscarRegistroPorDni(dniPersona));

        if (dniPersona <= 0) {
            system("cls");
            cout << "EL DNI DEBE SER MAYOR A 0." << endl;
            system("pause");
            system("cls");
        } else if (dniPersona == obj.getDniPersona() && obj.getActivo()) {
            system("cls");
            cout << "ESTE DNI YA ESTA REGISTRADO." << endl;
            system("pause");
            system("cls");
        } else {
            // Si todo está correcto, salir del ciclo
            validacionExitosa = true;
        }


    }

    // Continuar con la carga del resto de los datos
    cout << endl << "INGRESE EL/LOS NOMBRE/S DEL ALUMNO: ";
    cargarCadena(nombre, 50);

    cout << endl << "INGRESE EL APELLIDO DEL ALUMNO: ";
    cargarCadena(apellido, 50);

    cout << endl << "INGRESE LA FECHA DE NACIMIENTO DEL ALUMNO";
    cout<<endl;

    fechaDeNacimiento.cargar();

    return 0;


}
void Persona::mostrar()
{
    setlocale(LC_ALL,"");
    cout<<"EL DNI DEL ALUMNO ES: "<<dniPersona;
    cout<<endl<<"EL NOMBRE COMPLETO DEL ALUMNO ES: "<<nombre<<" "<<apellido;
    cout<<endl<<"EL ALUMNO NACIO EL AÑO: ";
    fechaDeNacimiento.mostrar();
}
  void Persona::setFechaDeNacimiento(Fecha f){
      fechaDeNacimiento=f;
  }
void Persona::setDniPersona(long long int dP){
    dniPersona=dP;
}
void Persona::setNombre(const char *n)
{
    strcpy(nombre,n);
}
void Persona::setApellido(const char *a)
{
    strcpy(apellido,a);
}

long long int Persona::getDniPersona(){
    return dniPersona;
}
char Persona::getNombre()
{
    return *nombre;
}
char Persona::getApellido()
{
    return *apellido;
}
Fecha Persona::getFechaDeNacimiento()
{
    return fechaDeNacimiento;
}
