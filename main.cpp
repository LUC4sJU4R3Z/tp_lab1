#include <iostream>
#include <ctime> //esto es para la funcion random

using namespace std;
//-------------------------declaracion de funciones------------------------------
void elegir_nombres(string &nombre_j1, string &nombre_j2);
void cartas_aleatoreas (int cantidad_repartida, string numero_cartas[13]); //tira el numero de carta aleatoreamente
void palo_aleatoreo (int cantidad_repartida, string tipo_palo[4]); //tira el tipo aleatoreamente




//-------------------------------main-----------------------------------------
int main()
{
    const int cantidad_repartida = 5; //la cantidad de cartas repartidas

    int opcion; //se usa en el menu para elegir la opcion
    string nombre_j1,nombre_j2;
    string numero_cartas[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    string tipo_palo[4] = {"trebol", "corazon", "pica", "diamante"};

    do {

        cout<<"GLUTCH"<<endl;
        cout<<"--------------"<<endl;
        cout<<"1 - JUGAR"<<endl;
        cout<<"2 - ESTADISTICAS"<<endl;
        cout<<"3 - CREDITOS"<<endl;
        cout<<"----------------"<<endl;
        cout<<"0 - SALIR"<<endl;
        cin>>opcion;

        if(opcion==1) //dentro de este if se va a desarrollar el juego
        {
            elegir_nombres(nombre_j1,nombre_j2);//al pasar por referencia no hace falta asignar por que la funcion ya lo hace
            cout<<"los nombres son "<< nombre_j1 <<" y "<< nombre_j2<<endl;

            cartas_aleatoreas(cantidad_repartida, numero_cartas); palo_aleatoreo(cantidad_repartida, tipo_palo);//las declare para probar
        }

    }while(opcion!=0);

    return 0;
}

//-------------------------------funciones--------------------------------------------------------------


//funcion para elegir los nombres

void elegir_nombres(string &nombre_j1, string &nombre_j2)
{
    char confirmacion;

    do{
        cout<<"CLUTCH"<<endl;
        cout<<"------------------------------------------------------------------------"<<endl;
        cout<<"Antes de comenzar deben registrar sus nombres:"<<endl;
        cout<<endl;
        cout<<"jugador 1 ingrese su nombre: "<<endl;
        cin>>nombre_j1;
        cout<<"jugador 2 ingrese su nombre: "<<endl;
        cin>>nombre_j2;
        cout<<"¿Confirmar nombres? (S/N)"<<endl;
        cin>>confirmacion;

        cout<<"------------------------------------------------------------------------"<<endl;
    }while(confirmacion!='s');
}




//funcion para que tire 5 cartas aleatoreas

void cartas_aleatoreas (int cantidad_repartida, string numero_cartas[13])
{
    srand(time(0));
    for(int x=0;x<cantidad_repartida;x++)
    {
        cout<<numero_cartas [(rand()%13)]<<endl;
    }
}




//funcion para que tire 5 palos aleatoreos

void palo_aleatoreo (int cantidad_repartida, string tipo_palo[4])
{
    srand(time(0));
    for(int x=0;x<cantidad_repartida;x++)
    {
        cout<<tipo_palo[(rand()%4)]<<endl;
    }
}
