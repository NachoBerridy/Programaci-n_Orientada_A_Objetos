//  Ignacio Berridy 11987
//  Programación Orientada a objetos/ Trabajo Práctico 1 - Ejercicio 1

#include <string>
//Como los atributos son privados los unicos que pueden modificarlos son los metodos de la clase

//Clase con los datos del operario
class Operario
{
    private: 
        string nombre;
        string codigo;
    public:
        Operario();//Constructor
        void setOperario();
        string getNombre();
        string getCodigo();
};

//Metodos getter, para poder obtener y utilizar los datos de un objeto
string Operario::getNombre(){
    return nombre;
};
string Operario::getCodigo(){
    
    return codigo;
};

//Metodo setter, para darle valor a los atributos de un objeto
void Operario::setOperario()
{
    cout << "\nNombre del Operario: ";
    getline(cin,nombre); //Esto pertmite ingresar una cadena con espacios
    cout << "\nCodigo del Operario "<<nombre<<": ";
    getline(cin,codigo);
};

//Clase generalidades de la tarea
class Generalidades
{
    private:
        string descripcion;
        int dia,mes,anio;
        int hora,minuto;
    public:
        Generalidades();//Constructor
        void setGeneralidades();
        string getDescripcion();
        int getDia();
        int getMes();
        int getAnio();
        int getHora();
        int getMinuto();
};

string Generalidades::getDescripcion(){
    return descripcion;
};
int Generalidades::getDia(){
    return dia;
};
int Generalidades::getMes(){
    return mes;
};
int Generalidades::getAnio(){
    return anio;
};
int Generalidades::getHora(){
    return hora;
};
int Generalidades::getMinuto(){
    return minuto;
};

void Generalidades::setGeneralidades(){
    cout << "\nBreve descripcion de la tarea: ";
    getline(cin,descripcion);
    cout << "\nIngrese la fecha (Formato dd/mm/aaaa) ";
    //Año puede ingresarse cualquier año
    cout << "\nAnio: "; cin>>anio;
    //Mes se debe ingrear un mes existente
    cout << "\nMes: "; cin>>mes;
    while (mes<=0 || mes>=13)
    {
        cout<<"\nMes no valido, vuelva a ingresar el mes: "; cin>>mes;
    };
    //Dia, Se debe ingresar el dia hasta que la fecha sea valida
    cout << "\nDia: "; cin>>dia;
    if ((mes-2)==0 && (anio%4==0 &&(anio%100!=0 ||anio%400==0)) )
    {
        while (dia<=0 || dia>=30)
        {
            cout<<"\nDia no valido, vuelva a ingresar el dia: "; cin>>dia;
        };
    }else if ((mes-2)==0  && anio%4!=0)
    {
        while (dia<=0 || dia>=29)
        {
            cout<<"\nDia no valido, vuelva a ingresar el dia: "; cin>>dia;
        };
        
    }else if ((mes-1)==0 || (mes-3)==0 || (mes-5)==0 || (mes-7)==0 || (mes-8)==0 || (mes-10)==0 || (mes-12)==0)
    {
        while (dia<=0 || dia>=32)
        {
            cout<<"\nDia no valido, vuelva a ingresar el dia: "; cin>>dia;
        }; 
    }else
    {
        while (dia<=0 || dia>=31)
        {
            cout<<"\nDia no valido, vuelva a ingresar el dia: "; cin>>dia;
        };
    };
    cout << "\nIngrese hora de inicio (Formato hh/mm de 0 a 23 el horario y de 0 a 59 el minuto) ";
    cout << "\nHora: "; cin>>hora;
    while (hora < 0 || hora > 23)
    {
       cout << "\nHora ingresada no valida, intente nuevamente: "; cin>>hora; 
    };
    cout << "\nMinuto: "; cin>>minuto;
    while (minuto < 0 || minuto > 59)
    {
       cout << "\nMinuto ingresado no valido, intente nuevamente: "; cin>>minuto; 
    };
};

//Clase coordenadas
class Coordenadas{
    private:
        float x,y,z;
    public:
        Coordenadas();
        void setCoordenadas();
        float getX();
        float getY();
        float getZ();

};


float Coordenadas::getX()
{
    return x;
};
float Coordenadas::getY()
{
    return y;
};
float Coordenadas::getZ()
{
    return z;
};

void Coordenadas::setCoordenadas()
{
    cout << "\nCoordenada X: "; cin>>x;
    cout << "\nCoordenada Y: "; cin>>y;
    cout << "\nCoordenada Z: "; cin>>z;
};

//Clase Datos del robot
class Datos_robot{
    private:
        Coordenadas coordenadas;
        float tiempo;
        string estado;
    public:
        Datos_robot();//Constructor
        void setDatos(Coordenadas);
        Coordenadas getCoordenadas();
        float getTiempo();
        string getEstado();

};

Coordenadas Datos_robot::getCoordenadas()
{
    return coordenadas;
};
float Datos_robot::getTiempo()
{
    return tiempo;
};
string Datos_robot::getEstado()
{
    return estado;
};

void Datos_robot::setDatos(Coordenadas _Coordenadas)
{
    coordenadas = _Coordenadas;
    cout << "\nTiempo en segundos en esta coordenada: "; cin>>tiempo;
    
    int a; //Variable Auxiliar
    cout<<"Referencias: (1: Activo / 2: Inactivo / 3: Suspendido)\n Nota: seleccione Suspendido para finalizar el programa\n";
    cout<<"Seleccione el estado del robot: "; cin>>a;
    while((a-1)!=0 && (a-2)!=0 && (a-3)!=0 ) // Comprobación del estado ingresado
    {
        cout<<"\nEstado no valido\nEstado del robot:\n1: Activo\n2: Inactivo\n3: Suspendido\nSeleccione el estado: ";
        cin>>a;
    };
    if (a==1)
    {
        estado = "Activo";
    }
    else if (a==2)
    {
        estado= "Inactivo";
    }
    else if (a==3)
    {
        estado= "Suspendido";
    };
};

Operario::Operario(){};

Generalidades::Generalidades(){};

Coordenadas::Coordenadas(){};

Datos_robot::Datos_robot(){};

class Tarea_robot
{
    private: //Atributos
        Operario operario;
        Generalidades generalidades;
        Datos_robot datos_robot;
    public://Metodos
        Tarea_robot();//Constructor
        void setTarea(Operario,Generalidades,Datos_robot);
        Operario getOperario();
        Generalidades getGeneralidades();
        Datos_robot getDatos();
};

Tarea_robot::Tarea_robot(){};

Operario Tarea_robot::getOperario(){
    return operario;
};
Generalidades Tarea_robot::getGeneralidades(){
    return generalidades;
};
Datos_robot Tarea_robot::getDatos(){
    return datos_robot;
};


void Tarea_robot::setTarea(Operario _operario, Generalidades _generalidades, Datos_robot _datos)
{
    operario=_operario;
    generalidades=_generalidades;
    datos_robot=_datos;
};