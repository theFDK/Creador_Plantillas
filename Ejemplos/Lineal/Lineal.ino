#include "Lineal.h"

void setup() {
  //Etapas iniciales.
  E[0] = 1;
  fe[0] = 1;
  pinMode(I[0], INPUT);
  pinMode(I[1], INPUT);
  pinMode(O[0], OUTPUT);
  pinMode(O[1], OUTPUT);
}

void loop() {
  //Lectura de entradas.
  for (f = 0; f < 2; f++) {
    if (digitalRead(I[f]) == HIGH) i[f] = 1;
    else i[f] = 0;
  }

  //Transiciones.
  for (g = 0; g < 2; g++) {
    for (f = 3; f >= 0; f--) {
      if (g == 0 || (g && E[f]) == 1) {
        switch (f) {
          case 0 :
            E[f] = etapa (E[f], E[3], T[1], E[f + 1]);
            break;
          case 1 :
            E[f] = etapa (E[f], E[f - 1], i[0], E[f + 1]);
            break;
          case 2 :
            E[f] = etapa (E[f], E[f - 1], T[0], E[f + 1]);
            break;
          case 3 :
            E[f] = etapa (E[f], E[f - 1], i[1], E[0]);
            break;
          default: //Reset etapas.
            for (h = 0; h < 4; h++) E[h] = 0;
            E[0] = 1;
            fe[0] = 1;
            break;
        }
      }
    }
  }

  //Reset de temporizadores.
  for (f = 0; f < 2; f++) T[f] = 0;

  //Acciones.
  for (f = 0; f < 4; f++) {
    if (E[f] == 1) {
      switch (f) {
        case 0 :
          digitalWrite(O[0], LOW);
          digitalWrite(O[1], LOW);
          break;
        case 1 :
          digitalWrite(O[0], HIGH);
          if (fe[f] == 1) pret[0] = pretemp (tempst[0]);
          T[0] = temp (pret[0]);
          break;
        case 2 :
          digitalWrite(O[0], LOW);
          digitalWrite(O[1], HIGH);
          break;
        case 3 :
          digitalWrite(O[0], HIGH);
          if (fe[f] == 1) pret[1] = pretemp (tempst[1]);
          T[1] = temp (pret[1]);
          break;
      }
    }
  }

  //Acciones momentaneas.
  for (f = 0; f < 2; f++) {
    if (M[f] == 1) {
      digitalWrite(O[f], HIGH);
      M[f] = 2;
    }
    else if (M[f] == 2) {
      digitalWrite(O[f], LOW);
      M[f] = 0;
    }
  }

  //Flancos de las etapas.
  for (f = 0; f < 4; f++) {
    if (E[f] == 1) fe[f] = 0;
    else fe[f] = 1;
  }
}
