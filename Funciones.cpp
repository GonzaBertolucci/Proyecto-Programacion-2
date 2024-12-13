#include <iostream>
#include <windows.h>
#include "rlutil.h"
#include "clsFecha.h"
#include "clsPersona.h"

#include "clsEvaluaciones.h"
#include "clsObras.h"
#include "clsTeatro.h"
#include "clsAlumnos.h"
#include "clsObrasXTeatro.h"
#include "clsAlumnoXObra.h"

#include "clsArchivoEvaluaciones.h"
#include "clsArchivoObras.h"
#include "clsArchivoTeatro.h"
#include "clsArchivoAlumnos.h"
#include "clsArchivoAlumnoXObra.h"
#include "clsArchivoObrasXTeatro.h"

#include "Funciones.h"
using namespace std;
void bloquearRedimension()
{
    // cierve para obtener el manejador de la ventana de la consola
    HWND consoleWindow = GetConsoleWindow();

    // obvtiene los estilos actuales de la ventana
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);

    // Remueve el estilo de redimensionamiento
    style &= ~WS_SIZEBOX;

    // Aplica el nuevo estilo
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}


void cargarCadena(char *pal, int tam)
{
    int i;
    fflush (stdin); ///limpia el buffer de entrada para que la carga se haga sin caracteres que hayan quedado sin usar
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin); ///vuelve a limpiar el buffer para eliminar los caracteres sobrantes
}

void eliminarAlumno()
{
    int legajo;
    Alumnos obj;
    ArchivoAlumno arc;
    AlumnoXObra objAXO;
    ArchivoAlumnoXObra arcAXO;

    cout<<"USTED QUIERE ELIMINAR EL ALUMNO CON EL LEGAJO: "<<endl<<endl;
    cin>>legajo;
    obj=arc.leer(arc.buscarRegistroPorLegajo(legajo));
    if((legajo==obj.getLegajo())&&(obj.getActivo()))
    {
        for(int i=0; i<=arcAXO.cantidadDeRegistros(); i++)
        {
            objAXO=arcAXO.leer(i);

            if((legajo==objAXO.getLegajo())&&(objAXO.getActivo()))
            {
                arcAXO.eliminarRegistro(objAXO,i);
            }
        }
        arc.eliminarRegistro(obj,arc.buscarRegistroPorLegajo(legajo));
        system("cls");
        cout<<"REGISTRO ELIMINADO..."<<endl<<endl;
        system("pause");
        system("cls");


    }
    else
    {
        system("cls");
        cout<<"ESE REGISTRO NO EXISTE..."<<endl;
        system("pause");
        system("cls");
    }

}
void eliminarObra()
{
    int codObra;
    Obras objObra;
    ArchivoObras arcObra;
    AlumnoXObra objAXO;
    ArchivoAlumnoXObra arcAXO;
    ObrasXTeatro objOXT;
    ArchivoObrasXTeatro arcOXT;

    cout<<"USTED QUIERE ELIMINAR LA OBRA CON EL CODIGO: "<<endl<<endl;
    cin>>codObra;
    objObra=arcObra.leer(arcObra.buscarRegistro(codObra));

    if((codObra== objObra.getCodObra())&&(objObra.getActivo()==true))
    {
        for(int i=0; i<=arcAXO.cantidadDeRegistros(); i++)
        {
            objAXO=arcAXO.leer(i);

            if((codObra==objAXO.getCodObra())&&(objAXO.getActivo()))
            {
                arcAXO.eliminarRegistro(objAXO,i);

            }

        }
        for(int i=0; i<=arcOXT.cantidadDeRegistros(); i++)
        {
            objOXT=arcOXT.leer(i);
            if((codObra==objOXT.getCodObra())&&(objOXT.getActivo()))
            {
                arcOXT.eliminarRegistro(objOXT,i);
            }
        }

        arcObra.eliminarRegistro(objObra,arcObra.buscarRegistro(codObra));
        system("cls");
        cout<<"REGISTRO ELIMINADO..."<<endl<<endl;
        system("pause");
        system("cls");


    }
    else
    {
        system("cls");
        cout<<"ESE REGISTRO NO EXISTE..."<<endl;
        system("pause");
        system("cls");
    }

}

void eliminarTeatro()
{
    int codTeatro;
    Obras objObra;
    ArchivoObras arcObra;
    ObrasXTeatro objOXT;
    ArchivoObrasXTeatro arcOXT;
    Teatros objTeatro;
    ArchivoTeatro arcTeatro;

    cout<<"USTED QUIERE ELIMINAR LA OBRA CON EL CODIGO: "<<endl<<endl;
    cin>>codTeatro;
    objTeatro=arcTeatro.leer(arcTeatro.buscarRegistro(codTeatro));

    if((codTeatro == objTeatro.getCodTeatro())&&(objTeatro.getActivo()==true))
    {
        for(int i=0; i<=arcOXT.cantidadDeRegistros(); i++)
        {
            objOXT=arcOXT.leer(i);

            if((codTeatro==objOXT.getCodTeatro())&&(objOXT.getActivo()))
            {
                arcOXT.eliminarRegistro(objOXT,i);

            }

        }


        arcTeatro.eliminarRegistro(objTeatro,arcTeatro.buscarRegistro(codTeatro));
        system("cls");
        cout<<"REGISTRO ELIMINADO..."<<endl<<endl;
        system("pause");
        system("cls");


    }
    else
    {
        system("cls");
        cout<<"ESE REGISTRO NO EXISTE..."<<endl;
        system("pause");
        system("cls");
    }

}

void eliminaralumnoObra()
{
    int legajo,codObra;
    AlumnoXObra obj;
    ArchivoAlumnoXObra arc;


    do
    {
        cout<<"USTED QUIERE ELIMINAR EL ALUMNO CON EL LEGAJO: ";
        cin>>legajo;
        cout<<"DE LA OBRA CON EL CODIGO: ";
        cin>>codObra;

        obj=arc.leer(arc.buscarRegistro(codObra,legajo));



        if((legajo==obj.getLegajo())&&(codObra==obj.getCodObra())&&(obj.getActivo()))
        {

            arc.eliminarRegistro(obj,arc.buscarRegistro(codObra,legajo));

            cout<<"REGISTRO ELIMINADO..."<<endl<<endl;
            system("pause");
            system("cls");
        }

        if((legajo>0)&&(codObra>0)&&(legajo!=obj.getLegajo())&&(codObra!=obj.getCodObra()))
        {
            system("cls");
            cout<<"ESE REGISTRO NO EXISTE..."<<endl;
            system("pause");
            system("cls");
        }
    }
    while(((legajo>0)&&(legajo>0))&&((legajo!=obj.getLegajo())||(codObra!=obj.getCodObra())));
}

void eliminarObraTeatro()
{
    int codObra,codTeatro;
    ObrasXTeatro obj;
    ArchivoObrasXTeatro arc;
    ArchivoObras arcObras;
    Obras objObra;

    do
    {
        int cantidad = arcObras.cantidadDeRegistros();
        cout << "CODIGOS DE OBRAS DISPONIBLES:" << endl;
        for (int i = 0; i < cantidad; i++)
        {
            objObra = arcObras.leer(i);
            if (objObra.getActivo())
            {
                cout << "- CODIGO DE OBRA: " << objObra.getCodObra() << endl;
            }
        }
        cout<<"USTED QUIERE ELIMINAR LA OBRA CON EL CODIGO: ";
        cin>>codObra;
        cout<<endl<<"DEL TEATRO CON EL CODIGO: "<<endl<<endl;
        cin>>codTeatro;

        obj=arc.leer(arc.buscarRegistro(codObra,codTeatro));



        if((codObra==obj.getCodObra())&&(codTeatro==obj.getCodTeatro())&&(obj.getActivo()))
        {

            arc.eliminarRegistro(obj,arc.buscarRegistro(codObra,codTeatro));

            cout<<"REGISTRO ELIMINADO..."<<endl<<endl;
            system("pause");
            system("cls");
        }

        if((codObra>0)&&(codTeatro>0)&&(codObra!=obj.getCodObra())&&(codTeatro!=obj.getCodTeatro()))
        {
            system("cls");
            cout<<"ESE REGISTRO NO EXISTE..."<<endl;
            system("pause");
            system("cls");
        }
    }
    while(((codObra>0)&&(codObra>0))&&((codObra!=obj.getCodObra())||(codTeatro!=obj.getCodTeatro())));
}



void menuDeAlumnos()
{
    Alumnos obj;
    ArchivoAlumno arc;
    int opc=1;

    while(opc!=0)
    {

        int posicion=arc.cantidadDeRegistros()+1;
        interfazAlumnos();
        cout<<endl;
        rlutil::locate(43, 23);
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:///registra a alumnos a un archivo
        {
            obj.cargar();
            arc.guardar(obj);

            cout<<"REGISTRO GUARDADO..."<<endl<<endl;
            system("pause");
            system("cls");
            break;
        }
        case 2:///modifica archivos
        {

            int cantidad = arc.cantidadDeRegistros();
            cout << "LEGAJOS DISPONIBLES PARA MODIFICAR:" << endl;
            for (int i = 0; i < cantidad; i++)
            {
                obj = arc.leer(i);
                if (obj.getActivo())
                {
                    cout << "- LEGAJO: " << obj.getLegajo() << endl;
                }
            }

            int legajo;
            cout << "INGRESE EL LEGAJO DEL ALUMNO QUE QUIERE MODIFICAR SUS DATOS: ";
            cin >> legajo;
            int pos;
            pos= arc.buscarRegistroPorLegajo(legajo);

            if (pos == -1)
            {
                cout << "ALUMNO NO ENCONTRADO"<<endl;
                system("pause");
                break;
            }

            Alumnos alumno = arc.leer(pos);

            if (!alumno.getActivo())
            {
                cout << "EL ALUMNO FUE REMOVIDO DEL REGISTRO"<<endl;
                system("pause");
                break;
            }

            int campo;
            do
            {
                system("cls");
                rlutil::locate(37,7);
                cout << "________________________________________";
                rlutil::locate(37,8);
                cout << "|---Seleccione el campo a modificar-----|";
                rlutil::locate(37,9);
                cout << "|                                       |";
                rlutil::locate(37,10);
                cout << "|1----------------DNI-------------------|";
                rlutil::locate(37,11);
                cout << "|2-------------- LEGAJO-----------------|";
                rlutil::locate(37,12);
                cout << "|3---------------NOMBRE-----------------|";
                rlutil::locate(37,13);
                cout << "|4--------------APELLIDO----------------|";
                rlutil::locate(37,14);
                cout << "|5---------FECHA DE NACIMIENTO----------|";
                rlutil::locate(37,15);
                cout << "|6------------GRADO ESCOLAR-------------|";
                rlutil::locate(37,16);
                cout << "|7----------NUMERO DE ASISTENCIA--------|";
                rlutil::locate(37,17);
                cout << "|8------------MODIFICAR TODO------------|";
                rlutil::locate(37,18);
                cout << "|0-------------VOLVER ATRAS-------------|";
                rlutil::locate(37,19);
                cout << "|                                       |";
                rlutil::locate(37,20);
                cout << "|         SELECCIONE UNA OPCION:        |";
                rlutil::locate(37,21);
                cout << "|_______________________________________|";
                rlutil::locate(70,20);
                cin >> campo;
                system("cls");

                bool modificado = false;
                switch(campo)
                {
                case 1:
                {
                    modificado = alumno.modificarDni();
                    break;
                }
                case 2:
                {
                    modificado = alumno.modificarLegajo();
                    break;
                }
                case 3:
                {
                    modificado = alumno.modificarNombre();
                    break;
                }
                case 4:
                {
                    modificado = alumno.modificarApellido();
                    break;
                }
                case 5:
                {

                    modificado = alumno.modificarFechaDeNacimiento();
                    break;
                }
                case 6:
                {
                    modificado = alumno.modificarGrado();
                    break;
                }
                case 7:
                {
                    modificado = alumno.modificarAsistencias();
                    break;
                }
                case 8:
                {
                    alumno.cargar();
                    modificado=true;
                    break;
                }
                }

                if ((modificado) && (arc.modificarRegistro(alumno,pos)))
                {
                    cout << "Opcion modificada con EXITO."<<endl;
                    system("pause");
                }
                else if (modificado)
                {
                    cout << "No se pudo modificar el alumno."<<endl;
                    system("pause");
                }
            }
            while(campo!=0);
            break;
        }
        case 3:///elimina registros
        {

            eliminarAlumno();

            break;
        }
        case 4:///lista todos los alumnos
        {
            arc.listarRegistros();
            system("pause");
            system("cls");

            break;
        }
        /*
        case 5:///busca alumnos por legajo
        {
            ArchivoAlumnoXObra arcAXO;
            AlumnoXObra objAXO;
            ArchivoEvaluaciones arcEvaluaciones;
            Evaluaciones objEvaluaciones;
            Obras objObra;
            ArchivoObras arcObras;

            cout<<"¿QUE ALUMNO QUIERE BUSCAR?: ";
            int legajo,info;

            cin>>legajo;
            obj= arc.leer(arc.buscarRegistroPorLegajo(legajo));
            if(legajo==obj.getLegajo())
            {
                obj.mostrar();


                cout<<endl<<endl<<"VER: ";
                cout<<endl<<"1---OBRAS EN LAS QUE ESTA INSCRIPTO---";
                cout<<endl<<"2-------EVALUACIONES REALIZADAS-------";
                cout<<endl<<"0----------------NADA-----------------";
                cin>>info;
                switch(info)
                {
                case 1:
                {
                    for(int i=0; i<=arcAXO.cantidadDeRegistros(); i++)
                    {
                        objAXO=arcAXO.leer(i);
                        if((legajo==objAXO.getLegajo())&&(objAXO.getActivo()))
                        {
                            objObra=arcObras.leer(arcObras.buscarRegistro(objAXO.getCodObra()));
                            cout<<endl;

                            objObra.mostrar();
                        }


                    }
                    break;
                }
                case 2:
                {
                    for(int i=0; i<=arcEvaluaciones.cantidadDeRegistros(); i++)
                    {
                        objEvaluaciones=arcEvaluaciones.leer(i);
                        if((legajo==objEvaluaciones.getLegajo())&&(objEvaluaciones.estaActivo()))
                        {

                            objEvaluaciones.mostrar();
                            cout<<endl;

                        }


                    }
                    break;
                }
                }

            }
            else
            {
                cout<<"EL LEGAJO NO EXISTE"<<endl;
            }
            system("pause");
            break;
        }*/
        case 5:///registra a alumnos en obras
        {
            AlumnoXObra objAlumnoXObras;

            objAlumnoXObras.cargar();

            break;
        }
        case 6:///eliminar a un alumno de una obra
        {

            int cantidad = arc.cantidadDeRegistros();
            cout << "LEGAJOS DISPONIBLES PARA ELIMINAR DE OBRA:" << endl;
            for (int i = 0; i < cantidad; i++)
            {
                obj = arc.leer(i);
                if (obj.getActivo())
                {
                    cout << "- LEGAJO: " << obj.getLegajo() << endl;
                }
            }
            eliminaralumnoObra();
            break;
        }

        }
    }
}

void menuDeEvaluaciones()
{
    ArchivoEvaluaciones archivoEvaluaciones;
    int opcion;

    do
    {
        /**
        system("cls");
        rlutil::locate(40,10);
        cout << "--- Menu de Evaluaciones ---"<<endl;
        cout << "1. Crear nueva evaluacion"<<endl;
        cout << "2. Modificar evaluacion"<<endl;
        cout << "3. Eliminar evaluacion"<<endl;
        cout << "4. Listar evaluaciones"<<endl;
        cout << "0. Volver al menu principal"<<endl;
        cout << "Seleccione una opcion: ";

        system("cls");*/

        interfazEvaluacion();

        cin >> opcion;
        system("cls");
        switch (opcion)
        {
        case 1:
        {
            Evaluaciones nuevaEvaluacion;
            int codigo;

            do
            {
                cout << "INGRESE EL CODIGO DE EVALUACION: ";
                cin >> codigo;
                if (codigo <= 0 )
                {
                    cout << "EL CODIGO DEBE SER MAYOR A 0" << endl;
                    system("pause");
                    system("cls");
                }
            }
            while (codigo <= 0);


            if (archivoEvaluaciones.buscarPorCodigo(codigo) != -1)
            {
                cout << "ESTE CODIGO DE EVALUACION YA EXISTE, NO SE PUEDE DUPLICAR." << endl;
                system("pause");
                system("cls");
            }
            else
            {
                nuevaEvaluacion.setCodigoEvaluacion(codigo);

                // Llamada a cargar y verificación de éxito
                if (nuevaEvaluacion.cargar())    // Solo guardar si cargar fue exitoso
                {
                    if (archivoEvaluaciones.guardar(nuevaEvaluacion))
                    {
                        cout << "EVALUACION GUARDADA CON EXITO." << endl;
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        cout << "ERROR AL GUARDAR LA EVALUACION." << endl;
                        system("pause");
                        system("cls");
                    }
                }
                else
                {
                    cout << "NO SE PUDO GUARDAR LA EVALUACION. LEGAJO INVALIDO." << endl;
                    system("pause");
                    system("cls");
                }
            }
            break;
        }
        case 2:
        {
                ArchivoEvaluaciones arcEvaluaciones;
                Evaluaciones objEvaluacion;
                int cantidad = arcEvaluaciones.cantidadDeRegistros();
                cout << "CODIGOS DE EVALUACION DISPONIBLES PARA MODIFICAR:" << endl;
                for (int i = 0; i < cantidad; i++)
                {
                    objEvaluacion = arcEvaluaciones.leer(i);
                    if (objEvaluacion.estaActivo())
                    {
                        cout << "- CODIGO DE EVALUACION: " << objEvaluacion.getCodigoEvaluacion() << endl;
                    }
                }
            int codigo;
            cout << "INGRESE EL CODIGO DE EVALUACION A MODIFICAR: ";
            cin >> codigo;
            int posicion = archivoEvaluaciones.buscarPorCodigo(codigo);

            if (posicion == -1)
            {
                cout << "NO SE ENCONTRO LA EVALUACION INDICADA."<<endl;
                system("pause");
                system("cls");
                break;
            }

            Evaluaciones evaluacion = archivoEvaluaciones.leer(posicion);

            if (!evaluacion.estaActivo())
            {
                cout << "LA EVALUACION ESTA ELIMINADA."<<endl;
                system("pause");
                system("cls");
                break;
            }
            system("cls");
            int campo;
            rlutil::locate(37,10);
            cout << "_______________________________________";
            rlutil::locate(37,11);
            cout << "|---Seleccione el campo a modificar----|";
            rlutil::locate(37,12);
            cout << "|                                      |";
            rlutil::locate(37,13);
            cout << "|1--------Codigo de Evaluacion---------|";
            rlutil::locate(37,14);
            cout << "|2-------- Tipo de Evaluacion----------|";
            rlutil::locate(37,15);
            cout << "|3---------------Nota------------------|";
            rlutil::locate(37,16);
            cout << "|4----------Modificar todo-------------|";
            rlutil::locate(37,17);
            cout << "|                                      |";
            rlutil::locate(37,18);
            cout << "|       Seleccione una opcion:         |";
            rlutil::locate(37,19);
            cout << "|______________________________________|";
            rlutil::locate(70,18);
            cin >> campo;

            bool modificado = false;
            switch (campo)
            {
            case 1:
                system("cls");
                modificado = evaluacion.modificarCodigoEvaluacion();
                break;
            // case 2:
            //   modificado = evaluacion.modificarLegajo();
            // break;
            case 2:
                system("cls");
                modificado = evaluacion.modificarTipoDeEvaluacion();
                break;
            case 3:
                system("cls");
                modificado = evaluacion.modificarNota();
                break;
            case 4:
                system("cls");
                evaluacion.cargar(); // Llama a cargar() para modificar todos los campos
                modificado = true;
                break;
            default:
                cout << "Opcion no valida."<<endl;
                system("pause");
                system("cls");
            }

            if (modificado && archivoEvaluaciones.modificar(evaluacion, posicion))
            {
                cout << "EVALUACION MODIFICADA CON EXITO."<<endl;
                system("pause");
                system("cls");
            }
            else if (modificado)
            {
                cout << "NO SE PUDO MODIFICAR LA EVALUACION."<<endl;
                system("pause");
                system("cls");
            }
            break;
        }
        case 3:
        {
                ArchivoEvaluaciones arcEvaluaciones;
                Evaluaciones objEvaluacion;
                int cantidad = arcEvaluaciones.cantidadDeRegistros();
                cout << "CODIGOS DE EVALUACION DISPONIBLES PARA ELIMINAR:" << endl;
                for (int i = 0; i < cantidad; i++)
                {
                    objEvaluacion = arcEvaluaciones.leer(i);
                    if (objEvaluacion.estaActivo())
                    {
                        cout << "- CODIGO DE EVALUACION: " << objEvaluacion.getCodigoEvaluacion() << endl;
                    }
                }
            int codigo;
            cout << "INGRESE EL CODIGO DE LA EVALUACION QUE DESEA ELIMINAR: ";
            cin >> codigo;
            int posicion = archivoEvaluaciones.buscarPorCodigo(codigo);

            if (posicion == -1)
            {
                cout << "EVALUACION NO ENCONTRADA / NO EXISTE."<<endl;
                system("pause");
                system("cls");
            }
            else if (archivoEvaluaciones.eliminar(posicion))
            {
                cout << "EVALUACION ELIMINADA."<<endl;
                system("pause");
                system("cls");
            }
            else
            {
                cout << "NO SE PUDO ELIMINAR LA EVALUACION."<<endl;
                system("pause");
                system("cls");
            }
            break;
        }
        case 4:
        {
            cout << "--------------------------"<<endl;
            int cantidad = archivoEvaluaciones.cantidadDeRegistros();
            for (int i = 0; i < cantidad; i++)
            {
                Evaluaciones evaluacion = archivoEvaluaciones.leer(i);
                if (evaluacion.estaActivo())
                {
                    evaluacion.mostrar();
                    cout << "--------------------------"<<endl;
                }
            }
            system("pause");
            system("cls");
            break;
        }
        case 0:
            cout << "VOLVIENDO AL MENU PRINCIPAL..."<<endl;
            system("pause");
            system("cls");
            break;
        default:
            cout << "OPCION NO VALIDA, INTENTE OTRA VEZ."<<endl;
            system("pause");
            system("cls");
        }
    }
    while (opcion != 0);
}

void menuDeObras()
{
    Obras obj;
    ArchivoObras arc;
    int opc=1;

    while(opc!=0)
    {
        int posicion=arc.cantidadDeRegistros()+1;
        system("cls");

        interfazObras();
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
        {
            obj.cargar();
            arc.guardar(obj);

            cout<<"REGISTRO GUARDADO..."<<endl<<endl;
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
                ArchivoObras arcObras;
                Obras objObra;
                int cantidad = arcObras.cantidadDeRegistros();
                cout << "CODIGOS DE OBRAS DISPONIBLES PARA EDITAR:" << endl;
                for (int i = 0; i < cantidad; i++)
                {
                    objObra = arcObras.leer(i);
                    if (objObra.getActivo())
                    {
                        cout << "- CODIGO DE OBRA: " << objObra.getCodObra() << endl;
                    }
                }
            int codigo;
            cout << "INGRESE EL CODIGO DE LA OBRA QUE QUIERE MODIFICAR SUS DATOS: ";
            cin >> codigo;
            int pos;
            pos= arc.buscarRegistro(codigo);

            if (pos == -1)
            {
                cout << "OBRA NO ENCONTRADA"<<endl;
                break;
            }

            Obras obra = arc.leer(pos);

            if (!obra.getActivo())
            {
                cout << "LA OBRA FUE REMOVIDA DEL REGISTRO"<<endl;
                break;
            }

            int campo;
            do
            {

                system("cls");
                int campo;
                rlutil::locate(37,10);
                cout << "_______________________________________";
                rlutil::locate(37,11);
                cout << "|---Seleccione el campo a modificar----|";
                rlutil::locate(37,12);
                cout << "|                                      |";
                rlutil::locate(37,13);
                cout << "|1-----------CODIGO DE OBRA------------|";
                rlutil::locate(37,14);
                cout << "|2---------NOMBRE DE LA OBRA-----------|";
                rlutil::locate(37,15);
                cout << "|3--------------GENERO-----------------|";
                rlutil::locate(37,16);
                cout << "|4---FECHA DE REALIZACION DE LA OBRA---|";
                rlutil::locate(37,17);
                cout << "|5----------MODIFICAR TODO-------------|";
                rlutil::locate(37,18);
                cout << "|0-----------VOLVER ATRAS--------------|";
                rlutil::locate(37,19);
                cout << "|                                      |";
                rlutil::locate(37,20);
                cout << "|       SELECCIONES UNA OPCION:        |";
                rlutil::locate(37,21);
                cout << "|______________________________________|";
                rlutil::locate(70,20);
                cin >> campo;
                system("cls");

                bool modificado = false;
                switch(campo)
                {
                case 1:
                {
                    modificado = obra.modificarCodObra();
                    break;
                }
                case 2:
                {
                    modificado = obra.modificarNombre();
                    break;
                }
                case 3:
                {
                    modificado = obra.modificarGenero();
                    break;
                }
                case 4:
                {
                    modificado = obra.modificarFecha();
                    break;
                }
                case 5:
                {
                    obra.cargar();
                    modificado=true;
                    break;
                }
                }
                if ((modificado) && (arc.modificarRegistro(obra,pos)))
                {
                    cout << "obra modificada con EXITO."<<endl;
                    system("pause");
                }
                else if (modificado)
                {
                    cout << "No se pudo modificar la obra."<<endl;
                    system("pause");
                }
            }
            while(campo!=0);
            break;
        }
        case 3:
        {
                ArchivoObras arcObras;
                Obras objObra;
                int cantidad = arcObras.cantidadDeRegistros();
                cout << "CODIGOS DE OBRAS DISPONIBLES PARA ELIMINAR:" << endl;
                for (int i = 0; i < cantidad; i++)
                {
                    objObra = arcObras.leer(i);
                    if (objObra.getActivo())
                    {
                        cout << "- CODIGO DE OBRA: " << objObra.getCodObra() << endl;
                    }
                }
            eliminarObra();

            break;
        }
        case 4:
        {
            arc.listarRegistros();
            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            ArchivoAlumnoXObra arcAXO;
            ArchivoObrasXTeatro arcOXT;
            ArchivoObras arcObras;
            ArchivoTeatro arcTeatro;
            ArchivoAlumno arcAlumno;

            AlumnoXObra objAXO;
            ObrasXTeatro objOXT;
            Obras objObra;
            Teatros objTeatro;
            Alumnos objAlumno;
                int cantidad = arcObras.cantidadDeRegistros();
                cout << "CODIGOS DE OBRAS DISPONIBLES PARA BUSCAR:" << endl;
                for (int i = 0; i < cantidad; i++)
                {
                    objObra = arcObras.leer(i);
                    if (objObra.getActivo())
                    {
                        cout << "- CODIGO DE OBRA: " << objObra.getCodObra() << endl;
                    }
                }
            cout<<"¿QUE OBRA QUIERE BUSCAR?: ";
            int codObra,info;

            cin>>codObra;
            objObra= arcObras.leer(arcObras.buscarRegistro(codObra));
            if((codObra==objObra.getCodObra())&&(objObra.getActivo()))
            {
                objObra.mostrar();

                cout<<endl<<endl<<"VER: ";
                cout<<endl<<"1---TEATROS EN LOS QUE LA OBRA ESTA REGISTRADA---";
                cout<<endl<<"2--------ALUMNOS QUE PARTICIPAN EN LA OBRA-------";
                cout<<endl<<"0---------------------NADA-----------------------";
                cout<<endl;
                cin>>info;
                system("cls");
                switch(info)
                {
                case 1:
                {
                    cout<<"TEATROS EN LOS QUE LA OBRA ESTA REGISTRADA"<<endl;
                    for(int i=0; i<=arcOXT.cantidadDeRegistros(); i++)
                    {
                        objOXT=arcOXT.leer(i);
                        if((codObra==objOXT.getCodObra())&&(objOXT.getActivo()))
                        {
                            objTeatro=arcTeatro.leer(arcTeatro.buscarRegistro(objOXT.getCodTeatro()));

                            cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
                            objTeatro.mostrar();
                        }


                    }
                    break;
                }
                case 2:
                {
                    cout<<"ALUMNOS QUE PARTICIPAN EN LA OBRA"<<endl;
                    for(int i=0; i<=arcAXO.cantidadDeRegistros(); i++)
                    {
                        objAXO=arcAXO.leer(i);

                        if((codObra==objAXO.getCodObra())&&(objAXO.getActivo()))
                        {
                            cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
                            objAlumno=arcAlumno.leer(arcAlumno.buscarRegistroPorLegajo(objAXO.getLegajo()));
                            objAlumno.mostrar();


                        }


                    }
                    break;
                }
                }
            }
            else
            {
                cout<<"LA OBRA NO EXISTE"<<endl;
            }
            cout<<endl;
            system("pause");
            break;
        }
        case 6:
        {
            ObrasXTeatro objObraXTeatro;
            objObraXTeatro.cargar();
            break;
        }
        case 7:
        {

            eliminarObraTeatro();
            break;
        }



        }
    }
}

void menuDeTeatros()
{

    Teatros obj;
    ArchivoTeatro arc;
    int opc=1;

    while(opc!=0)
    {

        int posicion=arc.cantidadDeRegistros()+1;
        interfazTeatro();
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
        {
            ///registra a teatros a un archivo
            obj.cargar();
            arc.guardar(obj);

            cout<<"REGISTRO GUARDADO..."<<endl<<endl;
            system("pause");
            system("cls");
            break;
        }


        case 2:
        {
            ArchivoTeatro archivoTeatro;
            Teatros objTeatro;

            int cantidad = archivoTeatro.cantidadDeRegistros();
            cout<<"CODIGOS DE TEATROS DISPONIBLES PRA MODIFICAR: "<<endl;
            for(int i = 0; i < cantidad; i++){
                objTeatro = archivoTeatro.leer(i);
                if(objTeatro.getActivo()){
                    cout<<"- CODIGO DE TEATRO: "<<objTeatro.getCodTeatro()<<endl;
                }
            }

            int codigo;
            cout << "INGRESE EL CODIGO DEL TEATRO QUE QUIERE MODIFICAR SUS DATOS: ";
            cin >> codigo;
            int pos;
            pos= arc.buscarRegistro(codigo);

            if (pos == -1)
            {
                cout << "TEATRO NO ENCONTRADO"<<endl;
                break;
            }

            Teatros Teatro = arc.leer(pos);

            if (!Teatro.getActivo())
            {
                cout << "EL TEATRO FUE REMOVIDO DEL REGISTRO"<<endl;
                break;
            }

            int campo;
            do
            {


                system("cls");
                int campo;
                rlutil::locate(37,10);
                cout << "_______________________________________";
                rlutil::locate(37,11);
                cout << "|----SELECCIONAR CAMPO A MODIFICAR-----|";
                rlutil::locate(37,12);
                cout << "|                                      |";
                rlutil::locate(37,13);
                cout << "|1----------CODIGO DE TEATRO-----------|";
                rlutil::locate(37,14);
                cout << "|2---------NOMBRE DEL TEATRO-----------|";
                rlutil::locate(37,15);
                cout << "|3-------------DIRECCION---------------|";
                rlutil::locate(37,16);
                cout << "|4-----------MODIFICAR TODO------------|";
                rlutil::locate(37,17);
                cout << "|0------------VOLVER ATRAS-------------|";
                rlutil::locate(37,18);
                cout << "|                                      |";
                rlutil::locate(37,19);
                cout << "|       SELECCIONES UNA OPCION:        |";
                rlutil::locate(37,20);
                cout << "|______________________________________|";
                rlutil::locate(70,19);
                cin >> campo;
                system("cls");

                bool modificado = false;
                switch(campo)
                {
                case 1:
                {
                    modificado = Teatro.modificarCodTeatro();
                    break;
                }
                case 2:
                {
                    modificado = Teatro.modificarNombreDelTeatro();
                    break;
                }
                case 3:
                {
                    modificado = Teatro.modificarDireccion();
                    break;
                }
                case 4:
                {
                    Teatro.cargar();
                    modificado=true;
                    break;
                }
                }
                if ((modificado) && (arc.modificarRegistro(Teatro,pos)))
                {
                    cout << "teatro modificado con EXITO."<<endl;
                    system("pause");
                }
                else if (modificado)
                {
                    cout << "No se pudo modificar el teatro."<<endl;
                    system("pause");
                }

                system("pause");
            }
            while(campo>0);


            break;
        }
        case 3:
        {
                ArchivoTeatro archivoTeatro;
                Teatros objTeatro;

                int cantidad = archivoTeatro.cantidadDeRegistros();
                cout<<"CODIGOS DE TEATROS DISPONIBLES PRA MODIFICAR: "<<endl;
                for(int i = 0; i < cantidad; i++)
                {
                    objTeatro = archivoTeatro.leer(i);
                    if(objTeatro.getActivo())
                    {
                        cout<<"- CODIGO DE TEATRO: "<<objTeatro.getCodTeatro()<<endl;
                    }
                }
            eliminarTeatro();

            break;
        }
        case 4:
        {
            arc.listarRegistros();
            system("pause");
            system("cls");
            break;
        }
        case 5:///busca teatro  por codteatro
        {

            ObrasXTeatro objOXT;
            ArchivoObrasXTeatro arcOXT;
            Teatros objTeatro;
            ArchivoTeatro arcTeatro;
            Obras objObra;
            ArchivoObras arcObra;

            int cantidad = arcTeatro.cantidadDeRegistros();
            cout<<"CODIGOS DE TEATROS DISPONIBLES PRA MODIFICAR: "<<endl;
            for(int i = 0; i < cantidad; i++){
                objTeatro = arcTeatro.leer(i);
                if(objTeatro.getActivo()){
                    cout<<"- CODIGO DE TEATRO: "<<objTeatro.getCodTeatro()<<endl;
                }
            }


                cout << "¿QUE TEATRO QUIERE BUSCAR?: ";
                int codTeatro;

                cin >> codTeatro;
                int posTeatro = arcTeatro.buscarRegistro(codTeatro);
                if (posTeatro == -1)
                {
                    cout << "EL TEATRO NO EXISTE" << endl;
                    return;
                }

                objTeatro = arcTeatro.leer(posTeatro);

                if (!objTeatro.getActivo())
                {
                    cout << "EL TEATRO FUE ELIMINADO" << endl;
                    return;
                }

                objTeatro.mostrar();
                cout << endl; // Salto de línea después de mostrar el teatro

                for (int i = 0; i < arcOXT.cantidadDeRegistros(); i++)
                {
                    objOXT = arcOXT.leer(i);
                    if (codTeatro == objOXT.getCodTeatro() && objOXT.getActivo())
                    {
                        objObra = arcObra.leer(arcObra.buscarRegistro(objOXT.getCodObra()));

                        if (objObra.getActivo())
                        {
                            cout << endl;
                            cout << "________________________________________________________________________________________________________________________" << endl;
                            objObra.mostrar();
                            cout << endl; // Salto de línea después de mostrar la obra
                        }
                    }
                }
            system("pause");
            break;
        }


        }
    }
}

void interfazPrincipal()
{

    system("cls");
    rlutil::setColor(rlutil::GREEN );
    rlutil::locate(40,7);
    cout<<" ______________________________________ ";
    rlutil::locate(40,8);
    cout<<"|         REGISTRO ESCOLAR PARA        |";
    rlutil::locate(40,9);
    cout<<"|            CLASES DE TEATRO          |";
    rlutil::locate(40,10);
    cout<<"|______________________________________|";
    rlutil::locate(40,11);
    cout<<"|                                      |";
    rlutil::locate(40,12);
    cout<<"|1-----------MENU DE ALUMNOS-----------|";
    rlutil::locate(40,13);
    cout<<"|                                      |";
    rlutil::locate(40,14);
    cout<<"|2---------MENU DE EVELUACIONES--------|";
    rlutil::locate(40,15);
    cout<<"|                                      |";
    rlutil::locate(40,16);
    cout<<"|3------------MENU DE OBRAS------------|";
    rlutil::locate(40,17);
    cout<<"|                                      |";
    rlutil::locate(40,18);
    cout<<"|4-----------MENU DE TEATROS-----------|";
    rlutil::locate(40,19);
    cout<<"|                                      |";
    rlutil::locate(40,20);
    cout<<"|0--------------PARA SALIR-------------|";
    rlutil::locate(40,21);
    cout<<"|______________________________________|";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(40, 23); // Ubicar debajo del menú
    cout << "> "; // Marcador para la entrada

}

void interfazAlumnos()
{
    system("cls");
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(40, 4);
    cout << "______________________________________";
    rlutil::locate(40, 5);
    cout << "|          MENU DE ALUMNOS           |";
    rlutil::locate(40, 6);
    cout << "|____________________________________|";
    rlutil::locate(40, 7);
    cout << "|                                    |";
    rlutil::locate(40, 8);
    cout << "|1---------REGISTRAR ALUMNO----------|";
    rlutil::locate(40, 9);
    cout << "|                                    |";
    rlutil::locate(40, 10);
    cout << "|2---------MODIFICAR DATOS-----------|";
    rlutil::locate(40, 11);
    cout << "|                                    |";
    rlutil::locate(40, 12);
    cout << "|3--ELIMINAR REGISTRO DE UN ALUMNO---|";
    rlutil::locate(40, 13);
    cout << "|                                    |";
    rlutil::locate(40, 14);
    cout << "|4----------LISTAR ALUMNOS-----------|";
    rlutil::locate(40, 15);
    cout << "|                                    |";
    rlutil::locate(40, 16);
    cout << "|5--INSCRIBIR A UN ALUMNO A UNA OBRA-|";
    rlutil::locate(40, 17);
    cout << "|                                    |";
    rlutil::locate(40, 18);
    cout << "|6--ELIMINAR A UN ALUMNO DE UNA OBRA-|";
    rlutil::locate(40, 19);
    cout << "|                                    |";
    rlutil::locate(40, 20);
    cout << "|0---------VOLVER PARA ATRAS---------|";
    rlutil::locate(40, 21);
    cout << "|____________________________________|";

    // Posicionar entrada de datos
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(40, 23); // Ubicar debajo del menú
    cout << "> "; // Marcador para la entrada
}


void interfazEvaluacion()
{

    system("cls");
    rlutil::locate(38,10);
    cout<<" _____________________________________________";
    rlutil::locate(38,11);
    cout<<"|               MENU DE EVALUACIONES          |";
    rlutil::locate(38,12);
    cout<<"|_____________________________________________|";
    rlutil::locate(38,13);
    cout<<"|1-----------REGISTRAR UNA EVALUACION---------|";
    rlutil::locate(38,14);
    cout<<"|                                             |";
    rlutil::locate(38,15);
    cout<<"|2-------------MODIFICAR EVALUACION-----------|";
    rlutil::locate(38,16);
    cout<<"|                                             |";
    rlutil::locate(38,17);
    cout<<"|3------------ELIMINAR EVALUACION-------------|";
    rlutil::locate(38,18);
    cout<<"|                                             |";
    rlutil::locate(38,19);
    cout<<"|4--------------LISTAR EVALUACION-------------|";
    rlutil::locate(38,20);
    cout<<"|                                             |";
    rlutil::locate(38,21);
    cout<<"|0--------------VOLVER PARA ATRAS-------------|";
    rlutil::locate(38,22);
    cout<<"|_____________________________________________|";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(40, 23); // Ubicar debajo del menú
    cout << "> "; // Marcador para la entrada

}

void interfazObras()
{
    rlutil::locate(38,7);
    cout<<" ____________________________________________";
    rlutil::locate(38,8);
    cout<<"|                MENU DE OBRAS               |";
    rlutil::locate(38,9);
    cout<<"|____________________________________________|";
    rlutil::locate(38,10);
    cout<<"|1-------------REGISTRAR UNA OBRA------------|";
    rlutil::locate(38,11);
    cout<<"|                                            |";
    rlutil::locate(38,12);
    cout<<"|2----------EDITAR DATOS DE UNA OBRA---------|";
    rlutil::locate(38,13);
    cout<<"|                                            |";
    rlutil::locate(38,14);
    cout<<"|3-------ELIMINAR REGISTRO DE UNA OBRA-------|";
    rlutil::locate(38,15);
    cout<<"|                                            |";
    rlutil::locate(38,16);
    cout<<"|4------------LISTAR TODAS LAS OBRAS---------|";
    rlutil::locate(38,17);
    cout<<"|                                            |";
    rlutil::locate(38,18);
    cout<<"|5------BUSCAR OBRAS POR CODIGO DE OBRA------|";
    rlutil::locate(38,19);
    cout<<"|                                            |";
    rlutil::locate(38,20);
    cout<<"|6---------REGISTRAR OBRA A UN TEATRO--------|";
    rlutil::locate(38,21);
    cout<<"|                                            |";
    rlutil::locate(38,22);
    cout<<"|7---------ELIMINAR OBRA DE UN TEATRO--------|";
    rlutil::locate(38,23);
    cout<<"|                                            |";
    rlutil::locate(38,24);
    cout<<"|0--------------VOLVER PARA ATRAS------------|";
    rlutil::locate(38,25);
    cout<<"|____________________________________________|";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(39, 27); // Ubicar debajo del menú
    cout << "> "; // Marcador para la entrada
}
void interfazTeatro()
{
    system("cls");
    rlutil::locate(38,7);
    cout<<" ____________________________________________";
    rlutil::locate(38,8);
    cout<<"|                MENU DE TEATRO              |";
    rlutil::locate(38,9);
    cout<<"|____________________________________________|";
    rlutil::locate(38,10);
    cout<<"|1-------------REGISTRAR UN TEATRO-----------|";
    rlutil::locate(38,11);
    cout<<"|                                            |";
    rlutil::locate(38,12);
    cout<<"|2---------------MODIFICAR DATOS-------------|";
    rlutil::locate(38,13);
    cout<<"|                                            |";
    rlutil::locate(38,14);
    cout<<"|3-----ELIMINAR EL REGISTRO DE UN TEATRO-----|";
    rlutil::locate(38,15);
    cout<<"|                                            |";
    rlutil::locate(38,16);
    cout<<"|4--------------LISTAR TEATROS---------------|";
    rlutil::locate(38,17);
    cout<<"|                                            |";
    rlutil::locate(38,18);
    cout<<"|5------BUSCAR INFORMACION DE UN TEATRO------|";
    rlutil::locate(38,19);
    cout<<"|                                            |";
    rlutil::locate(38,20);
    cout<<"|0--------------VOLVER PARA ATRAS------------|";
    rlutil::locate(38,21);
    cout<<"|____________________________________________|";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(40, 23); // Ubicar debajo del menú
    cout << "> "; // Marcador para la entrada
}
void interfazDeModificaciones()
{
    system("cls");
    rlutil::setColor(rlutil::GREEN );
    rlutil::locate(22,7);
    cout<<" ___________________________________________________________________________ ";
    rlutil::locate(22,8);
    cout<<"|                                   MENU DE                                 |";
    rlutil::locate(22,9);
    cout<<"|                                MODIFICACIONES                             |";
    rlutil::locate(22,10);
    cout<<"|___________________________________________________________________________|";
    rlutil::locate(22,11);
    cout<<"|                                      |                                    |";
    rlutil::locate(22,12);
    cout<<"|1---AGREGAR ALUMNO NUEVOA MODIFICAR---|5--MODIFICAR LA FECHA DENACIMIENTO--|";
    rlutil::locate(22,13);
    cout<<"|                                      |                                    |";
    rlutil::locate(22,14);
    cout<<"|2----------MODIFICAR EL DNI-----------|6--------ODIFICAR EL LEGAJO---------|";
    rlutil::locate(22,15);
    cout<<"|                                      |                                    |";
    rlutil::locate(22,16);
    cout<<"|3---------MODIFICAR EL NOMBRE---------|7------MODIFICAR GRADO ESCOLAR------|";
    rlutil::locate(22,17);
    cout<<"|                                      |                                    |";
    rlutil::locate(22,18);
    cout<<"|4--------MODIFICAR EL APELLIDO--------|8-------MODIFICAR ASISTENCIAS-------|";
    rlutil::locate(22,19);
    cout<<"|                                      |                                    |";
    rlutil::locate(22,20);
    cout<<"|______________________________________|____________________________________|";
    rlutil::locate(22,21);
    cout<<"|0---------------------------------PARA SALIR-------------------------------|";
    rlutil::locate(22,22);
    cout<<"|___________________________________________________________________________|";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(40, 23); // Ubicar debajo del menú
    cout << "> "; // Marcador para la entrada


}



















