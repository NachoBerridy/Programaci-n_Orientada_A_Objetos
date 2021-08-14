//  Ignacio Berridy 11987
//  Programación Orientada a objetos/ Trabajo Práctico 1

#include <iostream>
using namespace std;
#include "Ejercicio_1.hpp"
#include "Ejercicio_2.hpp"

int main(){
    //Creacion de los objetos (Instanciación de las clases)
    Operario Op_1;
    Generalidades Ge_1;
    Coordenadas Cord;
    Datos_robot Datos;
    Tarea_robot Tareas[100];
    int variableAuxiliar = 1;
    int contador = 0;
    //Ingreso de datos 
    Op_1.setOperario(); //Ingreso por teclado de los atributos del operario
    Ge_1.setGeneralidades(); //Ingreso por teclado de los atributos de las generalidades de la tarea
    while (variableAuxiliar == 1)
    {
        contador = contador+1;
        Cord.setCoordenadas();
        Datos.setDatos(Cord); //Ingreso por teclado de la trayectoria del robot
        Tarea_robot Tarea;
        Tarea.setTarea(Op_1,Ge_1,Datos);
        Tareas[contador-1] = Tarea; //Se juntan los datos anteriores en la clase Tarea_robot
        if (Tareas[contador-1].getDatos().getEstado()=="Suspendido")
        {
            variableAuxiliar = 2;
        };
    };

    cout<<"El contador es igual a: "<<contador;
    
    generar_MML(Tareas,contador);
    return 0;
}