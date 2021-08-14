//  Ignacio Berridy 11987
//  Programación Orientada a objetos/ Trabajo Práctico 1 - Ejercicio 2

#include <fstream>
#include <cstdio>
#include <cstdlib>

void generar_MML(Tarea_robot Tareas[100], int contador)
{
    ofstream Tarea_Robot; //Creo el archivo
    Tarea_Robot.open("D:/Nacho/Facultad/Cuadernos Virtuales/POO/Programas/Tarea_Robot.MML"); //Abro el archivo
    //Se comienza a esbribir el archivo
    Tarea_Robot <<"<Tarea>\n";
    Tarea_Robot <<"     <Operador>\n";
    Tarea_Robot <<"         <nombre>"<<Tareas[0].getOperario().getNombre()<<"</nombre>\n";
    Tarea_Robot <<"         <codigo>"<<Tareas[0].getOperario().getCodigo()<<"</codigo>\n";
    Tarea_Robot <<"     </Operador>\n";
    Tarea_Robot <<"     <Generalidades>\n";
    Tarea_Robot <<"         <Descripcion>"<<Tareas[0].getGeneralidades().getDescripcion()<<"</Descripcion>\n";
    Tarea_Robot <<"         <Fecha>"<<Tareas[0].getGeneralidades().getDia()<<"/"<<Tareas[0].getGeneralidades().getMes()<<"/"<<Tareas[0].getGeneralidades().getAnio()<<"</Fecha>\n";
    Tarea_Robot <<"         <Descripcion>"<<Tareas[0].getGeneralidades().getHora()<<":"<<Tareas[0].getGeneralidades().getMinuto()<<"</Hora>\n";
    Tarea_Robot <<"     </Generalidades>\n";
    Tarea_Robot <<"     <Trayectoria>\n";
    for (int i = 0; i <= contador-1; i++)
    {
    Tarea_Robot <<"         <Accion>\n";
    Tarea_Robot <<"             <Coordenada>\n";
    Tarea_Robot <<"                 <x>"<<Tareas[i].getDatos().getCoordenadas().getX()<<"</x>\n";
    Tarea_Robot <<"                 <y>"<<Tareas[i].getDatos().getCoordenadas().getY()<<"</y>\n";
    Tarea_Robot <<"                 <z>"<<Tareas[i].getDatos().getCoordenadas().getZ()<<"</z>\n";
    Tarea_Robot <<"             </Coordenada>\n";
    Tarea_Robot <<"             <Tiempo>"<<Tareas[i].getDatos().getTiempo()<<"</Tiempo>\n";
    Tarea_Robot <<"             <Estado>"<<Tareas[i].getDatos().getEstado()<<"</Estado>\n";
    Tarea_Robot <<"         </Accion>\n";        
    };
    Tarea_Robot <<"     </Trayectoria>\n";
    Tarea_Robot <<"</Tarea>\n";
};