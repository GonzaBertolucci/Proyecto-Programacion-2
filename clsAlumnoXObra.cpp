#include <iostream>
#include "rlutil.h"
#include "clsAlumnoXObra.h"
#include "clsArchivoAlumnoXObra.h"


#include "clsArchivoAlumnos.h"
#include "clsObras.h"
#include "clsArchivoObras.h"

using namespace std;

AlumnoXObra::AlumnoXObra()
{
    legajo=0;
    codObra=0;
    activo=false;
}

void AlumnoXObra::setLegajo(int l)
{
    legajo=l;
}
void AlumnoXObra::setcCodObra(int cO)
{
    codObra=cO;
}
void AlumnoXObra::setActivo(bool a)
{
    activo=a;
}

int AlumnoXObra::getLegajo()
{
    return legajo;
}
int AlumnoXObra::getCodObra()
{
    return codObra;
}
bool AlumnoXObra::getActivo()
{
    return activo;
}

void AlumnoXObra::cargar()
{
    Alumnos objAlumno;
    ArchivoAlumno arcAlumno;
    Obras objObra;
    ArchivoObras arcObras;

    ArchivoAlumnoXObra arcAlumnoXObra;
    AlumnoXObra objAlumnoXObra;

    int legajo;
    int codObra;
    do{
    do{
            int cantidad = arcAlumno.cantidadDeRegistros();
            cout << "LEGAJOS DISPONIBLES PARA INSCRIBIR:" << endl;
            for (int i = 0; i < cantidad; i++) {
                objAlumno = arcAlumno.leer(i);
                if (objAlumno.getActivo()) {
                    cout << "- LEGAJO: " << objAlumno.getLegajo() << endl;
                }
            }
            cout<<"A QUE ALUMNO QUIERE REGISTRAR A UNA OBRA: ";
            cin>>legajo;
            objAlumno=arcAlumno.leer(arcAlumno.buscarRegistroPorLegajo(legajo));

        if(((legajo!=objAlumno.getLegajo())&&(!objAlumno.getActivo()))){
            cout<<"ESTE ALUMNO NO EXISTE..."<<endl;
             system("pause");
            system("cls");
        }

    }while(((legajo!=objAlumno.getLegajo())&&(!objAlumno.getActivo())));

       do{

            cout<<"A QUE OBRA QUIERE REGISTRARLO: ";
        cin>>codObra;
     objObra=arcObras.leer(arcObras.buscarRegistro(codObra));

        if(((codObra!=objObra.getCodObra())&&(!objObra.getActivo()))){

            cout<<"ESTA OBRA NO EXISTE"<<endl;
            system("pause");
            system("cls");
        }

    }while(((codObra!=objObra.getCodObra())&&(!objObra.getActivo())));

    objAlumnoXObra=arcAlumnoXObra.leer(arcAlumnoXObra.buscarRegistro(codObra,legajo));

    if(((legajo>0)&&(codObra>0))&&(legajo==objAlumnoXObra.getLegajo())&&(codObra==objAlumnoXObra.getCodObra())&&(objAlumnoXObra.getActivo())){
       cout<<"ESTE REGISTRO YA EXISTE"<<endl;
       cout<<"SELECCIONE OTRO POR FAVOR"<<endl;
       system("pause");
       system("cls");
       }

    }while(((legajo>0)&&(codObra>0))&&((legajo==objAlumnoXObra.getLegajo())&&(codObra==objAlumnoXObra.getCodObra())&&(objAlumnoXObra.getActivo())));

if(((legajo>=0)||(codObra<=0))&&(legajo==objAlumnoXObra.getLegajo())&&(codObra==objAlumnoXObra.getCodObra())&&(objAlumnoXObra.getActivo()==true)){

}
else{
    objAlumnoXObra.setLegajo(legajo);
    objAlumnoXObra.setcCodObra(codObra);
    objAlumnoXObra.setActivo(true);
    arcAlumnoXObra.guardar(objAlumnoXObra);
    cout<<"REGISTRO GUARDADO"<<endl;
       system("pause");
}

   /** do{
    do{
            system("cls");
      rlutil::locate(35,13);
        cout<<"A QUE ALUMNO QUIERE REGISTRAR A UNA OBRA: ";
        rlutil::locate(89,3);
                cout<<"PRESIONE 0 PARA VOLVER ATRAS";
                rlutil::locate(76,13);
        cin>>legajo;

        if(legajo>0){
            objAlumno=arcAlumno.leer(arcAlumno.buscarRegistroPorLegajo(legajo));
            if((legajo!=objAlumno.getLegajo())||(objAlumno.getActivo()==false)){
                    rlutil::locate(45,17);
            cout<<"ESTE REGISTRO NO EXISTE";

            _getch();

            }
        }
    }while((legajo>0)&&((legajo!=objAlumno.getLegajo())||(objAlumno.getActivo()==false)));


if(legajo!=0){
         do{


rlutil::locate(46,15);
        cout<<"A QUE OBRA QUIERE REGISTRARLO: ";
        rlutil::locate(76,15);
        cin>>codObra;
        if(codObra>0){
        objObra=arcObras.leer(arcObras.buscarRegistro(codObra));

       if((codObra!=objObra.getCodObra())||(objObra.getActivo()==false)){
   rlutil::locate(45,17);
            cout<<"ESTE REGISTRO NO EXISTE";

            _getch();
       }
        }
         }while((legajo>0)&&((codObra!=objObra.getCodObra())||(objObra.getActivo()==false)));

}
    objAlumnoXObra=arcAlumnoXObra.leer(arcAlumnoXObra.buscarRegistro(codObra,legajo));

    if((codObra>0)&&(legajo==objAlumnoXObra.getLegajo())&&(codObra==objAlumnoXObra.getCodObra())){
 cout<<"ESTE ALUMNO YA ESTA INSCRIPTO A ESTA OBRA...";
        _getch();
    }

    }while ((legajo>0)&&(codObra>0&&(legajo==objAlumnoXObra.getLegajo())&&(codObra==objAlumnoXObra.getCodObra())));


    if((codObra>0)||(legajo>0)){




        if((legajo==objAlumnoXObra.getLegajo())&&(codObra==objAlumnoXObra.getCodObra())){
       cout<<"ESTE REGISTRO YA EXISTE...";
       }
       else{

         objAlumnoXObra.setLegajo(legajo);
    objAlumnoXObra.setcCodObra(codObra);
    arcAlumnoXObra.guardar(objAlumnoXObra);
     system("cls");
            rlutil::locate(44,10);
    cout<<"ALUMNO REGISTRADO..."<<endl;

    _getch();

       }
    }
*/
}


void AlumnoXObra::mostrarObras()
{

    cout<<"EL LEGAJO ES: "<<legajo<<endl;
    cout<<"EL CODIGO ES: "<<codObra<<endl;

    system("pause");


}
































