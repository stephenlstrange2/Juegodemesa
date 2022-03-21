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

#include "str.h"

#include <stdio.h>

void inicializar(){

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,4);
    int semilla = dist6(rng);
    srand(semilla);
}

void main(){


}