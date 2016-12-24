#include "Direccional_y_Simultaneo.h"

void setup() {
  //Etapas iniciales.
  E[0] = 1;
  fe[0] = 1;
  pinMode(I[0], INPUT);
  pinMode(I[1], INPUT);
  pinMode(I[2], INPUT);
  pinMode(O[0], OUTPUT);
  pinMode(O[1], OUTPUT);
  pinMode(O[2], OUTPUT);
}

void loop() {
  //Lectura de entradas.
  for (f = 0; f < 3; f++) {
    if (digitalRead(I[f]) == HIGH) i[f] = 1;
    else i[f] = 0;
  }

  //Transiciones.
  for (g = 0; g < 2; g++) {
    for (f = 5; f >= 0; f--) {
      if (g == 0 || (g && E[f]) == 1) {
        switch (f) {
          case 0 :
            E[f] = etapand (E[f], E[5], i[2], E[3], i[2], E[f + 1], E[f + 2]);
            break;
          case 1 :
            E[f] = etapalin (E[f], E[f - 1], i[0], E[f + 1]);
            break;
          case 2 :
            E[f] = etapa (E[f], E[f - 1], i[2], E[4], i[2], E[f + 1], E[5]);
            break;
          case 3 :
            E[f] = etapalin (E[f], E[f - 1], T[0], E[0]);
            break;
          case 4 :
            E[f] = etapalin (E[f], E[0], i[1], E[2]);
            break;
          case 5 :
            E[f] = etapalin (E[f], E[2], T[0], E[0]);
            break;
          default: //Reset etapas.
            for (h = 0; h < 6; h++) E[h] = 0;
            E[0] = 1;
            fe[0] = 1;
            break;
        }
      }
    }
  }

  //Reset de temporizadores.
  for (f = 0; f < 1; f++) T[f] = 0;

  //Acciones.
  for (f = 0; f < 6; f++) {
    if (E[f] == 1) {
      switch (f) {
        case 0 :

          break;
        case 1 :
          M[0] = 1;
          break;
        case 2 :
          if (fe[f] == 1) pret[0] = pretemp (tempst[0]);
          T[0] = temp (pret[0]);
          break;
        case 3 :
          if (fe[f] == 1) M[0] = 3;
          if (M[0] == 3) pret[1] = pretemp (tempst[1]);
          M[0] = parpadeo(pret[1], tempst[1]);
          break;
        case 4 :
          M[1] = 1;
          break;
        case 5 :
          if (fe[f] == 1) M[2] = 3;
          if (M[2] == 3) pret[2] = pretemp (tempst[1]);
          M[2] = parpadeo(pret[2], tempst[2]);
          break;
      }
    }
  }

  //Acciones momentaneas.
  for (f = 0; f < 3; f++) {
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
  for (f = 0; f < 6; f++) {
    if (E[f] == 1) fe[f] = 0;
    else fe[f] = 1;
  }
}
