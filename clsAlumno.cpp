#include <iostream>
#include "clsAlumno.h"

using namespace std;

void Alumno::cargar()
{
    Persona::cargar();
    cout<<"INGRESE EL LEGAJO DEL ALUMNO: ";
    cin>>legajo;
    cout<<endl<<" INGRESE EL GRADO ESCOLAR: ";
    cin>>gradoEscolar;
    cout<<endl<<"INGRESE LAS ASISTENCIAS DEL ALUMNO: ";
    cin>>asistencias;
}
void Alumno::mostrar()
{
    Persona::mostrar();
    cout<<endl<<"EL LEGAJO ES: "<<legajo;
    cout<<endl<<"EL GRADO ESCOLAR DEL ALUMNO ES: "<<gradoEscolar<<"º";
    cout<<endl<<"EL ALUMNO TUVO "<<asistencias<<" ASISTENCIAS";
}
void Alumno::setLegajo(int l)
{
    legajo=l;
}
void Alumno::setGradoEscolar(int gE)
{
    gradoEscolar=gE;
}
void Alumno::setAsistencias(int a)
{
    asistencias=a;
}
int Alumno::getLegajo()
{
    return legajo;
}
int Alumno::getGradoEscolar()
{
    return gradoEscolar;
}
int Alumno::getAsistencias()
{
    return asistencias;
}
