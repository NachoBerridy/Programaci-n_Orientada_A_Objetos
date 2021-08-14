#include <iostream>
using namespace std;

class Fecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        Fecha();
        void setFecha_manual();
        void setFecha(int,int,int);
};

void Fecha::setFecha_manual(){
    cout<<"Ingrese el anio: ";
    cin>>anio;
    int mes = 0;
    cout<<"Ingrese el mes: ";
    cin>>mes;

    while (mes<=0 || mes>=13){
        cout<<"\nMes no valido, vuelva a ingresar el mes: ";
        cin>>mes;
    };
    cout<<"Ingrese el dia: ";
    cin>>dia;
    if ((mes==2 ||mes==02) && (anio%4==0 &&(anio%100!=0 ||anio%400==0)) )
    {
        while (dia<=0 || dia>=30)
        {
            cout<<"\nDia no valido, vuelva a ingresar el dia: ";
            cin>>dia;
        };
    }else if ((mes==2 ||mes==02) && anio%4!=0)
    {
        while (dia<=0 || dia>=29)
        {
            cout<<"\nDia no valido, vuelva a ingresar el dia: ";
            cin>>dia;
        };
            
    }else if (mes-1==0 || mes-3==0 || mes-5==0 || mes-7==0 || mes-8==0 || mes-10==0 || mes-12==0)
    {
        while (dia<=0 || dia>=32){

            cout<<"\nDia no valido, vuelva a ingresar el dia: ";
            cin>>dia;
        }; 
    }else{
        while (dia<=0 || dia>=31)
        {
            cout<<"\nDia no valido, vuelva a ingresar el dia: ";
            cin>>dia;
        };
    };
};

void Fecha::setFecha(int _dia, int _mes, int _anio){

    dia=_dia;
    anio= _anio;

    if (mes<=0 || mes>=13){
        mes= _mes;
    }else{
        cout<<"Fceha no Valida\n";
        return;
    };
    cout<<"Ingrese el dia: ";
    cin>>dia;
    if ((mes==2 ||mes==02) && (anio%4==0 &&(anio%100!=0 ||anio%400==0)) &&(dia<=0 || dia>=30) )
    {
        dia=_dia;

    }else if ((mes==2 ||mes==02) && anio%4!=0 && dia<=0 || dia>=29)
    {
        dia=_dia;
   
    }else if ((mes-1==0 || mes-3==0 || mes-5==0 || mes-7==0 || mes-8==0 || mes-10==0 || mes-12==0) && (dia<=0 || dia>=32))
    {
        dia=_dia; 
    }else if (dia<=0 || dia>=31){
        dia=_dia;
    }else{
        cout<<"Fceha no Valida\n";
        return;
    };

};


