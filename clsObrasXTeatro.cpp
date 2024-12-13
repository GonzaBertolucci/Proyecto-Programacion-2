#include <iostream>
#include "clsArchivoObras.h"
#include "clsArchivoTeatro.h"
#include "clsArchivoObrasXTeatro.h"

#include "clsObras.h"
#include "clsTeatro.h"
#include"clsObrasXTeatro.h"

using namespace std;

ObrasXTeatro::ObrasXTeatro()
{
    codTeatro=0;
    codObra=0;
    activo=true;
}

void ObrasXTeatro::setCodTeatro(int l)
{
    codTeatro=l;
}
void ObrasXTeatro::setcCodObra(int cO)
{
    codObra=cO;
}
void ObrasXTeatro::setActivo(bool a)
{
    activo=a;
}

int ObrasXTeatro::getCodTeatro()
{
    return codTeatro;
}
int ObrasXTeatro::getCodObra()
{
    return codObra;
}
bool ObrasXTeatro::getActivo()
{
    return activo;
}

void ObrasXTeatro::cargar()
{
    Obras objObra;
    ArchivoObras arcObra;
    Teatros objTeatro;
    ArchivoTeatro arcTeatro;

    ArchivoObrasXTeatro arcOXT;
    ObrasXTeatro objOXT;

    int codObra;
    int codTeatro;
    do
    {
        do
        {
            int cantidad = arcObra.cantidadDeRegistros();
            cout << "CODIGOS DE OBRAS DISPONIBLES:" << endl;
            for (int i = 0; i < cantidad; i++)
            {
                objObra = arcObra.leer(i);
                if (objObra.getActivo())
                {
                    cout << "- CODIGO DE OBRA: " << objObra.getCodObra() << endl;
                }
            }
            cout<<"A QUE OBRA QUIERE REGISTRAR EN UN TEATRO: ";
            cin>>codObra;
            objObra=arcObra.leer(arcObra.buscarRegistro(codObra));

            if((codObra>0)&&((codObra!=objObra.getCodObra())||(objObra.getActivo()==false)))
            {
                cout<<"ESTA OBRA NO EXISTE";
            }

        }
        while((codObra>0)&&((codObra!=objObra.getCodObra())||(objObra.getActivo()==false)));

        do
        {
            cout<<"A QUE TEATRO QUIERE REGISTRARLO: ";
            cin>>codTeatro;
            objTeatro=arcTeatro.leer(arcTeatro.buscarRegistro(codTeatro));

            if((codTeatro>0)&&(codTeatro!=objTeatro.getCodTeatro())||(objTeatro.getActivo()==false))
            {
                cout<<"ESTE TEATRO NO EXISTE";
            }

        }
        while((codTeatro>0)&&(codTeatro!=objTeatro.getCodTeatro())||(objTeatro.getActivo()==false));

        objOXT=arcOXT.leer(arcOXT.buscarRegistro(codObra,codTeatro));

        if(((codObra>0)&&(codTeatro>0))&&(codObra==objOXT.getCodObra())&&(codTeatro==objOXT.getCodTeatro())&&(objOXT.getActivo()))
        {
            cout<<"ESTE REGISTRO YA EXISTE";
            system("pause");
        }

    }
    while((codObra>0)&&(codTeatro>0)&&((codObra==objOXT.getCodObra())&&(codTeatro==objOXT.getCodTeatro())&&(objOXT.getActivo())));

    if(((codObra<=0)||(codTeatro<=0))||(codObra==objOXT.getCodObra())&&(codTeatro==objOXT.getCodTeatro())&&(objOXT.getActivo()==true))
    {

    }
    else
    {
        objOXT.setcCodObra(codObra);
        objOXT.setCodTeatro(codTeatro);
        objOXT.setActivo(true);
        arcOXT.guardar(objOXT);
        cout<<"REGISTRO GUARDADO"<<endl;
        system("pause");
    }

}
