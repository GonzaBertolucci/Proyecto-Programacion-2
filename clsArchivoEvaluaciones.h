#ifndef CLSARCHIVOEVALUACIONES_H_INCLUDED
#define CLSARCHIVOEVALUACIONES_H_INCLUDED

#include "clsEvaluaciones.h"

class ArchivoEvaluaciones {
private:
    char _nombreArchivo[30]; //nombre del archivo

public: //constructor con nombre predeterminado
    ArchivoEvaluaciones(const char *nombreArchivo = "evaluaciones.dat");
    //metodos
    bool guardar(Evaluaciones evaluacion); //guarda una nueva evaluacion al final
    Evaluaciones leer(int posicion); //lee una evaluacion en una posicion en especial
    int cantidadDeRegistros(); //retorna la cantidad total de evaluaciones
    bool modificar(Evaluaciones nuevaEvaluacion, int posicion); //modifica una evaluacikon en x posicion
    bool modificarPorLegajo(int legajo, int nuevoTipo, float nuevaNota); //modifica evaluaciones por legajo
    bool eliminar(int posicion); //marca como eliminada una evaluacion
    int buscarPorCodigo(int codigoEvaluacion); //busca por codigo
    int buscarPorLegajo(int legajo); //busca por legajo asociado
};

#endif // CLSARCHIVOEVALUACIONES_H_INCLUDED
