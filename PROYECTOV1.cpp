#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Declaración de funciones
void elegir_nombres(string &nombre_j1, string &nombre_j2);
string numero_aleatoreo(string numero_cartas[5]);
string palo_aleatoreo(string tipo_palo[4]);
void repartir_cartasj1(string &nombre_j1, string corral_j1[][2], const int cantidad_repartida, string numero_cartas[], string tipo_palo[]);
void repartir_cartasj2(string &nombre_j2, string corral_j2[][2], const int cantidad_repartida, string numero_cartas[], string tipo_palo[]);
void empieza_primero(string corral_j1[][2], string corral_j2[][2], string numero_cartas[5], string &nombre_j1, string &nombre_j2, string &INICIA_PARTIDA, string &carta_repetida);

int main()
{
    const int cantidad_repartida = 5; // la cantidad de cartas repartidas

    int opcion; // se usa en el menú para elegir la opción
    string nombre_j1, nombre_j2, INICIA_PARTIDA, carta_repetida; ///VARIABLE "CARTA_REPETIDA" ES OPCIONAL, SE PUEDE BORRAR SI MOLESTA (BORRARLA EN EL SCOPE DE LAS FUNCIONES TMB)
    string numero_cartas[5] = {"A", "K", "Q", "J", "10"};
    string tipo_palo[4] = {"trebol", "corazon", "pica", "diamante"};
    string corral_j1[cantidad_repartida][2], corral_j2[cantidad_repartida][2]; // las 5 cartas que les toquen a cada uno, cada carta tiene número y palo

    srand(time(0));

    do {
        cout << "CLUTCH" << endl;
        cout << "--------------" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADISTICAS" << endl;
        cout << "3 - CREDITOS" << endl;
        cout << "----------------" << endl;
        cout << "0 - SALIR" << endl;
        cin >> opcion;

        if (opcion == 1) // dentro de este if se va a desarrollar el juego
        {
            elegir_nombres(nombre_j1, nombre_j2); // al pasar por referencia no hace falta asignar porque la función ya lo hace
            cout << "Los nombres son " << nombre_j1 << " y " << nombre_j2 << endl;

            cout << "CLUTCH" << endl;
            cout << "------------------------------------------------------------------------" << endl;

            repartir_cartasj1(nombre_j1, corral_j1, cantidad_repartida, numero_cartas, tipo_palo);
            repartir_cartasj2(nombre_j2, corral_j2, cantidad_repartida, numero_cartas, tipo_palo);
            empieza_primero(corral_j1, corral_j2, numero_cartas, nombre_j1, nombre_j2, INICIA_PARTIDA, carta_repetida);
            cout << "carta que hizo jugar primero al jugador: " << carta_repetida << endl; ///ESTE APARTADO ES OPCIONAL, LO HICE PARA VER SI REALMENTE FUNCIONABA LA FUNCION DE ABAJO
            cout << "el jugador " << INICIA_PARTIDA << " sera el primero en tirar los dados" << endl;

        }

    } while (opcion != 0);

    return 0;
}

// Función para elegir los nombres
void elegir_nombres(string &nombre_j1, string &nombre_j2)
{
    char confirmacion;

    do {
        cout << "CLUTCH" << endl;
        cout << "------------------------------------------------------------------------" << endl;
        cout << "Antes de comenzar deben registrar sus nombres:" << endl;
        cout << endl;
        cout << "Jugador 1 ingrese su nombre: " << endl;
        cin >> nombre_j1;
        cout << "Jugador 2 ingrese su nombre: " << endl;
        cin >> nombre_j2;
        cout << "¿Confirmar nombres? (S/N)" << endl;
        cin >> confirmacion;

        cout << "------------------------------------------------------------------------" << endl;
    } while (confirmacion != 's'); 
}

// Función para que tire el número de una carta aleatoriamente
string numero_aleatoreo(string numero_cartas[5])
{
    return numero_cartas[rand() % 5];
}

// Función para que tire el palo de una carta aleatoriamente
string palo_aleatoreo(string tipo_palo[4])
{
    return tipo_palo[rand() % 4];
}


//funcion para repartir las cartas al j1 y guardarlas en su corral
void repartir_cartasj1(string &nombre_j1, string corral_j1[][2], const int cantidad_repartida, string numero_cartas[], string tipo_palo[])
{
    cout << "Cartas repartidas para el jugador " << nombre_j1 << endl;

    for (int x = 0; x < cantidad_repartida; x++)
    {
        corral_j1[x][0] = numero_aleatoreo(numero_cartas); // carga el Número de carta al corral
        corral_j1[x][1] = palo_aleatoreo(tipo_palo);      // carga el Palo al corral
        cout << corral_j1[x][0] << " " << corral_j1[x][1] << endl;//esto es para mostrar
    }
}


//funcion para repartir las cartas al j2 y guardarlas en su corral

void repartir_cartasj2(string &nombre_j2, string corral_j2[][2], const int cantidad_repartida, string numero_cartas[], string tipo_palo[])
{
    cout << "Cartas repartidas para el jugador " << nombre_j2 << endl;

    for (int x = 0; x < cantidad_repartida; x++)
    {
        corral_j2[x][0] = numero_aleatoreo(numero_cartas); // carga el Número de carta al corral
        corral_j2[x][1] = palo_aleatoreo(tipo_palo);      // carga el Palo al corral
        cout << corral_j2[x][0] << " " << corral_j2[x][1] << endl;//esto es para mostrar
    }
}

///FUNCION PARA DECIDIR QUIEN DE LOS JUGADORES EMPIEZA PRIMERO
void empieza_primero(string corral_j1[][2], string corral_j2[][2], string numero_cartas[5], string &nombre_j1, string &nombre_j2, string &INICIA_PARTIDA, string &carta_repetida)
{
    bool BANDERA_PRIMERIZO = false;
    int I = 0, CONT_J1, CONT_J2;

    while(BANDERA_PRIMERIZO != true){
        CONT_J1 = CONT_J2 = 0;

        for(int x = 0 ; x < 5 ; x ++){
            if(corral_j1[x][0] == numero_cartas[I]){
                CONT_J1 ++;
            }
            if(corral_j2[x][0] == numero_cartas[I]){
                CONT_J2 ++;
            }
        }
        if(CONT_J1 > CONT_J2){
            INICIA_PARTIDA = nombre_j1;
            BANDERA_PRIMERIZO = true;
            carta_repetida = numero_cartas[I];
        }else if(CONT_J2 > CONT_J1){
            INICIA_PARTIDA = nombre_j2;
            BANDERA_PRIMERIZO = true;
            carta_repetida = numero_cartas[I];
        }else{
            I ++;
        }
    }
}