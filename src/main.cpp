/*
Primero llamamos a las librerias y headers de cajon
*/
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>
#include <cstdio>
#include <ctime>
#include <random>
using namespace std;
string eformat = "                                                             ";
#include "str.h"

#include <stdio.h>


specsJugadores jugador;
int buffer;
void inicializar(){

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,4);
    int semilla = dist6(rng);
    srand(semilla);
}

void pintarMenu(){
    int flag = 1;
    do
    {
        system("clear");
        std::cout << eformat << "MENU\n\n"<< eformat <<"1.Iniciar Juego\n"<<eformat<<"2.Salir\n";
        std::cin >> buffer;
        if(buffer==1){
            system("clear");
            std::cout << eformat << "Elige a tu jugador\n\n"<< eformat <<"1.Brandon Jaspers\n"<<eformat<<"2.Zoe Ingstrom\n"<< eformat <<"3.Father Rhinohardt\n"<<eformat<<"4.Salir al menu anterior\n";
            std::cin >> buffer;
            switch (buffer)
            {
            case 1:
                std::cout << "Brandon Jaspers\n";
                jugador.tirarDados(6);
                flag = 0;
                break;
            
            case 2:
                std::cout << "Zoe Ingstrom";
                flag = 0;
                /* code */
                break;
            case 3:
                std::cout << "Father Rhinohardt";
                flag = 0;
                /* code */
                break;
            default:
            std::cout << "Respuesta no valida.\n";
                break;
            }
        }
    } while (flag);
}

int main(){
    inicializar();
    pintarMenu();
    return 0;

}