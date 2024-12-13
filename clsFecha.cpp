#include <iostream>
#include "clsFecha.h"
#include <locale.h>
#include <limits>
using namespace std;

void Fecha::cargar() {
    setlocale(LC_ALL, "");

    // Validar día
    do {
        cout << "INGRESE EL DIA: ";
        cin >> dia;

        if (cin.fail() || dia <= 0 || dia > 31) {
            cout << "ERROR: EL DIA DEBE ESTAR ENTRE 1 Y 31." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
            system("cls");
        }
    } while (dia <= 0 || dia > 31);

    // Validar mes
    do {
        cout << "INGRESE EL MES: ";
        cin >> mes;

        if (cin.fail() || mes <= 0 || mes > 12) {
            cout << "ERROR: EL MES DEBE ESTAR ENTRE 1 Y 12." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
            system("cls");
        }
    } while (mes <= 0 || mes > 12);

    // Validar año
    do {
        cout << "INGRESE EL AÑO: ";
        cin >> anio;

        if (cin.fail() || anio <= 0 || anio > 2100) {
            cout << "ERROR: EL AÑO DEBE ESTAR ENTRE 1 Y 2100." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("pause");
            system("cls");
        }
    } while (anio <= 0 || anio > 2100);

    cout << endl << "FECHA INGRESADA CORRECTAMENTE: ";
    mostrar();
    cout<<endl;
    system("pause");
    cout << endl;
}


void Fecha::mostrar()
{
   cout<<dia<<"/"<<mes<<"/"<<anio;
}
void Fecha::setDia(int d)
{
}
void Fecha::setMes(int m)
{
}
void Fecha::setAnio(int a)
{
}
int Fecha::getDia()
{
}
int Fecha::getMes()
{
}
int Fecha::getAnio()
{
}

