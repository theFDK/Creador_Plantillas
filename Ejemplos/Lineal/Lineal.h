#include "Arduino.h"

//Temporizadores, comparadores, tiempo.
bool T[2];
unsigned long pret[2] = {0, 0};
unsigned int tempst[2] = {1500, 3000};

//Etapas, flancos, entradas, salidas y variables.
bool E [4];
bool fe [4];
int f;
byte g;
byte h;
const byte I [2] = {2, 7};
bool i [2];
const byte O [2] = {13, 8};
byte M [2] = {0, 0};

//Funciones para la temporizacion.
unsigned long pretemp (unsigned int t) {
  unsigned long tiempo = millis();
  unsigned long ptemp = tiempo + t;
  return ptemp;
}

byte temp (unsigned long pt) {
  unsigned long tiempo = millis();
  if (tiempo >= pt) return 1;
  else return 0;
}

//Funcion para parpadear.
byte parpadeo (unsigned long pretemp, unsigned int temp) {
  unsigned long tiempo = millis();
  if (tiempo >= temp + pretemp) return 3;
  else if (tiempo >= pretemp) return 2;
  else return 1;
}

//Funcion para la transicion.
byte etapa (byte eact, byte eant1, byte tran11, byte esig1) {
  if (eact + (eant1 && tran11) && (!esig1) == 1) return 1;
  else return 0;
}

/*
  //Funcion para temporizar:
  if(fe[f]==1) pret[0] = pretemp (tempst[0]);
  T[0] = temp (pret[0]);

  //Funcion para parpadear:
  if(fe[f]==1) M[0]=3;
  if(M[0]==3) pret[0] = pretemp (tempst[0]);
  M[0] = parpadeo(pret[0], tempst[0]);
*/
