#ifndef CLS_EVALUACIONES_H_INCLUDED
#define CLS_EVALUACIONES_H_INCLUDED

class Evaluaciones {
private:
    int _codigoEvaluacion;
    int _legajo;
    int _tipoDeEvaluacion;
    float _nota;
    bool _activo;

public:
    Evaluaciones(); //constructor x defecto
    Evaluaciones(int legajo, int tipoDeEvaluacion, float nota); //constructor con parametros

    bool cargar();
    void mostrar();

    bool modificarCodigoEvaluacion(); //modifica el cod de evaluacion
    bool modificarLegajo(); //modificar el legajo
    bool modificarTipoDeEvaluacion(); //modificar el tipo de evaluacion
    bool modificarNota(); //modificar la nota
    //sets
    void setCodigoEvaluacion(int codigoEvaluacion);
    void setLegajo(int legajo);
    void setTipoDeEvaluacion(int tipoDeEvaluacion);
    void setNota(float nota);
    void setActivo(bool activo);
    //gets
    int getCodigoEvaluacion();
    int getLegajo();
    int getTipoDeEvaluacion();
    float getNota();
    bool estaActivo();
};

#endif // CLS_EVALUACIONES_H_INCLUDED

