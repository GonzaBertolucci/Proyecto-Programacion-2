#include <iostream>
#include "Funciones.h"
#include "clsAlumnos.h"

using namespace std;


int main()
{
        bloquearRedimension();
    int opc=1;

    while(opc!=0)
    {

        interfazPrincipal();

        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
        {
            menuDeAlumnos();

            break;
        }
        case 2:
        {
          menuDeEvaluaciones();
            break;
        }
        case 3:
        {
            menuDeObras();
            break;
        }
        case 4:
        {
            menuDeTeatros();
            break;
        }
        }

    }
}

