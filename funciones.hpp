
#ifndef __FUNCIONES__
#define __FUNCIONES__

#include <Arduino.h>

#define MUX_A 10
#define MUX_B 9
#define MUX_C 8

#define ENA 11
#define MA1 2
#define MA2 4

#define ENB 3
#define MB1 6
#define MB2 5

void debugQTR();
void boton();
void initMux();
void setMux(byte salida);
void mover(int pot_iz, int pot_der);

enum side{IZ,DER,CENTRO};


#endif
