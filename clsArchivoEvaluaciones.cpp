#include <iostream>
#include <cstring>
#include "clsArchivoEvaluaciones.h"

ArchivoEvaluaciones::ArchivoEvaluaciones(const char *nombreArchivo) {
    strcpy(_nombreArchivo, nombreArchivo);
}
// Metodo guardar que escribe una nueva evaluacion al final del archivo.
bool ArchivoEvaluaciones::guardar(Evaluaciones evaluacion) {
    FILE *pArchivo = fopen(_nombreArchivo, "ab"); //Abrir el archivo en modo "append binary" para no borrar todo con el 'wb'.
    if (pArchivo == nullptr) {
        return false; //Verifica que el archivo se abrio.
    }
    fwrite(&evaluacion, sizeof(Evaluaciones), 1, pArchivo); //Escribir la evaluación con frwite.
    fclose(pArchivo); //Cerrar el archivo.
    return true;
}
//Metodo leer lo hace desde una posición en el archivo.
Evaluaciones ArchivoEvaluaciones::leer(int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo, "rb"); //Abrir el archivo en modo "read binary".
    Evaluaciones evaluacion;
    if (pArchivo == nullptr) { //Verificar si el archivo existe.
        evaluacion.setCodigoEvaluacion(-2); //valor para indicar error
        return evaluacion;
    }
    fseek(pArchivo, sizeof(Evaluaciones) * posicion, 0); //Mover el puntero a la posición correspondiente.
    fread(&evaluacion, sizeof(Evaluaciones), 1, pArchivo); // Leer.
    fclose(pArchivo); //Cerrar.
    return evaluacion;
}
//Metodo para calcular el total de las evaluaciones en el archivo.
int ArchivoEvaluaciones::cantidadDeRegistros() {
    FILE *pArchivo = fopen(_nombreArchivo, "rb");
    if (pArchivo == nullptr) {
        return -1; //Error si no existe.
    }
    fseek(pArchivo, 0, SEEK_END); //mover el puntero al final del archivo.
    int cantidad = ftell(pArchivo) / sizeof(Evaluaciones); //Calcular la cantidad de registros.
    fclose(pArchivo);
    return cantidad;
}
// metodo modificar, lo que hace es que sobrescribe una evaluación en una posición.
bool ArchivoEvaluaciones::modificar(Evaluaciones nuevaEvaluacion, int posicion) {
    FILE *pArchivo = fopen(_nombreArchivo, "rb+"); //Se abre en modo lectura/escritura cuando se agrega el +.
    if (pArchivo == nullptr) {
        return false;
    }
    fseek(pArchivo, sizeof(Evaluaciones) * posicion, SEEK_SET); //mover al registro deseado.
    fwrite(&nuevaEvaluacion, sizeof(Evaluaciones), 1, pArchivo); //escribir los nuevos datos.
    fclose(pArchivo);
    return true;
}
//metodo modificarPorLegajo, actualiza evaluaciones segun en el legajo.
bool ArchivoEvaluaciones::modificarPorLegajo(int legajo, int nuevoTipo, float nuevaNota) {
    int cantidad = cantidadDeRegistros();
    for (int i = 0; i < cantidad; i++) {
        Evaluaciones evaluacion = leer(i);
        if (evaluacion.estaActivo() && evaluacion.getLegajo() == legajo) { //verificar si coincide el legajo.
            evaluacion.setTipoDeEvaluacion(nuevoTipo);
            evaluacion.setNota(nuevaNota);
            return modificar(evaluacion, i); //actualizar registro.
        }
    }
    return false;
}
//metodo eliminar, se marca si esta activo o no, esto para que no se elimine el archivo por completo y genere errores.
bool ArchivoEvaluaciones::eliminar(int posicion) { //baja logica
    FILE *pArchivo = fopen(_nombreArchivo, "rb+");
    if (pArchivo == nullptr) {
        return false;
    }
    Evaluaciones evaluacion = leer(posicion);
    evaluacion.setActivo(false); //marcar como inactivo.
    fseek(pArchivo, sizeof(Evaluaciones) * posicion, SEEK_SET);
    fwrite(&evaluacion, sizeof(Evaluaciones), 1, pArchivo); //escribir el cambio.
    fclose(pArchivo);
    return true;
}
//metodo para buscarPorCodigo, encuentra una evaluacion activa por su codigo.
int ArchivoEvaluaciones::buscarPorCodigo(int codigoEvaluacion) {
    int cantidad = cantidadDeRegistros();
    for (int i = 0; i < cantidad; i++) {
        Evaluaciones evaluacion = leer(i);
        if (evaluacion.estaActivo() && evaluacion.getCodigoEvaluacion() == codigoEvaluacion) {
            return i; //reeetornar la posicion si se encuentra.
        }
    }
    return -1; //no encontrado.
}
//metodo buscarPorLegajo, encuentra una evaluacion activa por su legajo.
int ArchivoEvaluaciones::buscarPorLegajo(int legajo) {
    int cantidad = cantidadDeRegistros();
    for (int i = 0; i < cantidad; i++) {
        Evaluaciones evaluacion = leer(i);
        if (evaluacion.estaActivo() && evaluacion.getLegajo() == legajo) {
            return i;//retorna la posicion si se encuentra.
        }
    }
    return -1; //No lo enconto.
}
