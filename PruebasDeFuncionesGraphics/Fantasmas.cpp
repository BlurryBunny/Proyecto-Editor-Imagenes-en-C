#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
//Se define el radio del pacman y del ojo.
#define RadioG 80
#define RadioP 10
//Valor en entero de flechas en codigo ASCII
#define Izq 75
#define Der 77

typedef struct{
            int Px;
            int Py;
            int longitud;
}TFantasma;
