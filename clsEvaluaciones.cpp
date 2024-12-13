#include "clsEvaluaciones.h"
#include "clsAlumnos.h"
#include "clsArchivoAlumnos.h"
#include <iostream>
#include <limits>
using namespace std;
//constructor x defecto
Evaluaciones::Evaluaciones() {
    _codigoEvaluacion = 0;
    _legajo = 0;
    _tipoDeEvaluacion = 0;
    _nota = 0.0;
    _activo = true;
}
//con parametros
Evaluaciones::Evaluaciones(int legajo, int tipoDeEvaluacion, float nota) {
    _legajo = legajo;
    _tipoDeEvaluacion = tipoDeEvaluacion;
    _nota = nota;
    _activo = true;
}
//metodo cargar
bool Evaluaciones::cargar() {
    int legajo, tipoDeEvaluacion, posicion;
    float nota;
    Alumnos obj;
    ArchivoAlumno reg; //obj para acceder a los archivos de alumno
    //Lista los legajos disponibles
    int cantidad = reg.cantidadDeRegistros();
    cout<<"LEGAJOS DE ALUMNOS DISPONIBLES: "<<endl;
    for(int i = 0; i < cantidad; i++){
        obj = reg.leer(i);
        if(obj.getActivo()){
            cout<<"- LEGAJO: "<<obj.getLegajo()<<endl;
        }
    }

    do{
        cout << "INGRESE EL LEGAJO DEL ALUMNO: ";
        cin >> _legajo;
        if(cin.fail()){ //verificar que se ingrese el tipo de dato correcto ------------------------------- https://www.geeksforgeeks.org/how-to-use-cin-fail-method-in-cpp/
            cout<<"ERROR. INGRESE UN NUMERO ENTERO." <<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }



    //buscar el legajo en el archivo de alumnos
    posicion = reg.buscarRegistroPorLegajo(_legajo);

    if (posicion == -1) {
        cout << "ESTE ALUMNO NO ESTA REGISTRADO.(LEGAJO NO EXISTENTE)." << endl;
        cout << "VOLVIENDO AL MENU DE EVALUACIONES..." << endl;
        system("Pause");
        return false; //salir de la función si el legajo no es valido
     }
    }while(posicion == -1);

    //validacion tipo de evaluacion
    do {
        cout << "INGRESE EL TIPO DE EVALUACION (1=EVALUACION, 2=TP, 3=ORAL): ";
        cin >> tipoDeEvaluacion;
        if (cin.fail() || tipoDeEvaluacion < 1 || tipoDeEvaluacion > 3) {
            cout << "ERROR. EL TIPO DE EVALUACION TIENE QUE SER 1, 2 O 3" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    } while (tipoDeEvaluacion < 1 || tipoDeEvaluacion > 3);
    setTipoDeEvaluacion(tipoDeEvaluacion);


    do {
        cout << "INGRESE LA NOTA DE LA EVALUACION (1 A 10): ";
        cin >> nota;
        if (cin.fail() || nota < 1 || nota > 10) {
            cout << "ERROR. LA NOTA DEBE ESTAR ENTRE 1 Y 10." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
    } while (nota < 1 || nota > 10);
    setNota(nota);

    setActivo(true);
    return true; //carga exitosa si devuelve true
}


void Evaluaciones::mostrar() {
    if (_activo) {
        cout << "Codigo de Evaluacion: " << _codigoEvaluacion << endl;
        cout << "Legajo: " << _legajo << endl;
        //nombre listar
        /*ArchivoAlumno archivoAlumnos;
        int posicion = archivoAlumnos.buscarRegistroPorLegajo(_legajo);

        if(posicion != 1){
            Alumnos alumno = archivoAlumnos.leer(posicion);

            if(alumno.getLegajo() == _legajo){
                cout<<"Nombre del alumno: "<<alumno.getApellido()<<endl;
            }else{
                cout<<"ERROR"<<endl;
            }*/
        cout << "Tipo de Evaluacion: " << _tipoDeEvaluacion << endl;
        cout << "Nota: " << _nota << endl;
    } else {
        cout << "Este registro está marcado como eliminado." << endl;
    }
}

bool Evaluaciones::modificarCodigoEvaluacion() {
    int nuevoCodigo;

    do {
        cout << "Ingrese el nuevo codigo de evaluacion (mayor a 0): ";
        cin >> nuevoCodigo;
        if (cin.fail() || nuevoCodigo <= 0) {
            cout << "Error: El codigo de evaluacion debe ser mayor a 0." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (nuevoCodigo <= 0);

    setCodigoEvaluacion(nuevoCodigo);
    return true;
}

/*
bool Evaluaciones::modificarLegajo() {
    int nuevoLegajo;
    cout << "Ingrese el nuevo legajo: ";
    cin >> nuevoLegajo;
    setLegajo(nuevoLegajo);
    return true;
}
*/
bool Evaluaciones::modificarTipoDeEvaluacion() {
    int nuevoTipo;
    do {
        cout << "Ingrese el nuevo tipo de evaluacion (1=evaluacion, 2=tp, 3=oral): ";
        cin >> nuevoTipo;
        if (cin.fail() || nuevoTipo < 1 || nuevoTipo > 3) {
            cout << "Error: Tipo de evaluación debe ser 1, 2 o 3." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (nuevoTipo < 1 || nuevoTipo > 3);
    setTipoDeEvaluacion(nuevoTipo);
    return true;
}

bool Evaluaciones::modificarNota() {
    float nuevaNota;
    do {
        cout << "Ingrese la nueva nota (1 a 10): ";
        cin >> nuevaNota;
        if (cin.fail() || nuevaNota < 1 || nuevaNota > 10) {
            cout << "Error: La nota debe estar entre 1 y 10." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (nuevaNota < 1 || nuevaNota > 10);
    setNota(nuevaNota);
    return true;
}


void Evaluaciones::setCodigoEvaluacion(int codigoEvaluacion) {

     _codigoEvaluacion = codigoEvaluacion;

      }

void Evaluaciones::setLegajo(int legajo) {

    _legajo = legajo;

     }

void Evaluaciones::setTipoDeEvaluacion(int tipoDeEvaluacion) {

     _tipoDeEvaluacion = tipoDeEvaluacion;

      }

void Evaluaciones::setNota(float nota) {

    _nota = nota;

    }

void Evaluaciones::setActivo(bool activo) {

     _activo = activo;

     }

int Evaluaciones::getCodigoEvaluacion() {

    return _codigoEvaluacion;

    }

int Evaluaciones::getLegajo() {
    return _legajo;
    }

int Evaluaciones::getTipoDeEvaluacion() {
    return _tipoDeEvaluacion;
    }

float Evaluaciones::getNota() {
    return _nota;
    }

bool Evaluaciones::estaActivo() {
    return _activo;
    }
