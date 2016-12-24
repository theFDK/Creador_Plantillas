  /*----------------------------------------------------------------------|
  | " Copyright 2016 the FDK " el programa se distribuye bajo los términos| 
  | de la General Public License de GNU.                                  |
  | Fecha: 24/12/2016  Versión: 2.2.2                                     |
  |                                                                       |
  | Creador_Plantillas is free software: you can redistribute it and/or   |
  | modify it under the terms of the GNU General Public License as        | 
  | published by the Free Software Foundation, either version 3 of the    | 
  | License, or(at your option) any later version.                        |
  |                                                                       |
  | This program is distributed in the hope that it will be useful,       |
  | but WITHOUT ANY WARRANTY; without even the implied warranty of        |
  | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         |
  | GNU General Public License for more details.                          |
  |                                                                       |
  | You should have received a copy of the GNU General Public License     |
  | along with this program.  If not, see <http://www.gnu.org/licenses/>. |
  |                                                                       |
  |-----------------------------------------------------------------------|
  | Descripción: Creador_Plantillas es un programa que genera plantillas  |
  | de sketch de Arduino, para que trabaje siguiendo un grafcet.          |
  |----------------------------------------------------------------------*/

#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <direct.h>
#include "Funciones.h"
#include "Cplantilla.h"
#define si 's'
#define no 'n'


int main() {

  char letra, letrasim, nombrep[64], cogeletra[8];
  int f, g, mod = 0, n = -1, lon, error, nomer, finmod, modi, adv, adve, advs, petapa, pancho, pnega, netapa, initot, inietapa[64], nentrada, entrad[64], nsalida, salidas[64], ntemp = 0, longtemp = 0;
  FILE*gua;
  unsigned int nombre;
  long tempo[64];
  textcolor(WHITE);
  printf("\n Bienvenido al Creador_Plantillas.      Versi%cn 2.2.2 \n Dise%cado por: the FDK.\n\n", 162, 164);

  gua = fopen("guardado.txt", "r");
  if (gua == NULL) {
    printf("\n No se encontr%c el fichero: guardado.txt\n Se crear%c uno nuevo.", 162,160);
    letra = no;
  }
  else {
  fseek( gua, 0, SEEK_END ); 
  if (ftell( gua ) == 0 ){
  printf("\n Error de lectura en el fichero: guardado.txt\n Se crear%c uno nuevo.", 160);
    letra = no;
  }
   else{
   rewind(gua);
    // Lectura
    inietapa[0] = 0;
    initot = 0;
    fscanf(gua, "%d", &petapa);
    fscanf(gua, "%d", &pancho);
    fscanf(gua, "%d", &pnega);
    fscanf(gua, "%s", cogeletra);
    fscanf(gua, "%d", &netapa);
    fscanf(gua, "%d", &ntemp);
    for (f = 0; f < ntemp; f++) {
      fscanf(gua, "%d", &tempo[f]);
    }
    fscanf(gua, "%d", &nentrada);
    for (f = 0; f < nentrada; f++) {
      fscanf(gua, "%d", &entrad[f]);
    }
    fscanf(gua, "%d", &nsalida);
    for (f = 0; f < nsalida; f++) {
      fscanf(gua, "%d", &salidas[f]);
    }
    fscanf(gua, "%s", nombrep);
    fscanf(gua, "%d", &initot);
    for (f = 0; f < initot; f++) {
      fscanf(gua, "%d", &inietapa[f]);
    }
    fclose(gua);
    if (cogeletra[0] == si) {
      letrasim = si;
    }
    else {
      letrasim = no;
    }
    //max
    if (petapa > 32) {
      petapa = 32;
    }
    else if (petapa < 1) {
      petapa = 1;
    }
    if (pancho > 32) {
      pancho = 32;
    }
    else if (pancho < 1) {
      pancho = 1;
    }
    if (pnega > 32) {
      pnega = 32;
    }
    else if (pnega < 1) {
      pnega = 1;
    }
    if (netapa > 128) {
      netapa = 128;
    }
    else if (netapa < 3) {
      netapa = 3;
    }
    if (initot > 64) {
      initot = 64;
    }
    else if (initot < 1) {
      initot = 1;
    }
    nomer = nombrespa(nombrep);
    if (nomer > 0) {
      nombrep[0] = '0';
      nombrep[1] = '\0';
        if ((nombrep[0] != '0') && (nombrep[1] != '\0')) {
        lon = strlen (nombrep);
          for (f = 0; f < lon; f++) {
          nombre = int(nombrep[f]);
            if (nombre == 32) {
            nombrep[f] = '_';}
           }
        }
     }
    //Consulta
    printf("\n Utilizar configuraci%cn anterior?", 162);
    printf("\n \" %s \"\n (s) (n): ", nombrep);
    letra = sino();
    if (letra == si) {
      n = 6;
    }
  }
}


  //Bucle mod
  do {
    do {
      //nueva
      if (letra == no) {
        if (n == -1) {
          modi = 6;
        }
        else if (n == 0) {
          modi = 1;
        }
        else if (n == 1) {
          modi = 2;
        }
        else if (n == 2) {
          modi = 3;
        }
        else if (n == 3) {
          modi = 4;
        }
        else if (n == 4) {
          modi = 5;
        }
        else if (n == 5) {
          if ((adv || adve || advs) != 0) {
            letra = si;
            n = 7;
          }
          else {
            modi = 0;
          }
        }
        else if (n == 6) {
          modi = 0;
        }
        if (n < 5) {
          n += 1;
        }
      }

      // Inicio MOD
      if (letra == si) {
        printf("\n\n Modificar?-------------------------------------* ");
        printf("\n  Nada   (0)  Estructura (1)  Temporizadores (2)");
        printf("\n  Etapas (3)  Entradas   (4)  Salidas        (5)");
        printf("\n  Nombre (6)");
        printf("\n *----------------------------------------------*");
        printf("\n  ( ): ");
        do {
          modi = falloca();
          if (modi < 0 || modi > 6) {
            textcolor(DARKGRAY);
            printf("\n Tiene que introducir de 0 a 6: ");
            textcolor(WHITE);
          }
        } while (modi < 0 || modi > 6);
      }

      // MOD
      switch (modi) {
        case 0:
          if (finmod == 1) {
            n = 6;
          }
          if (letrasim != no && letrasim != si) {
            letrasim = no;
          }
          nombre = int(nombrep[0]);
          if (nombre < 48 || nombre > 122 || (nombre > 57 && nombre < 65) || (nombre > 90 && nombre < 95) || nombre == 96) {
            nombrep[0] = '0';
            nombrep[1] = '\0';
          }
          //Guardar
          gua = fopen("guardado.txt", "w");
          fprintf(gua, "%d", petapa);
          fprintf(gua, "\n%d", pancho);
          fprintf(gua, "\n%d", pnega);
          fprintf(gua, "\n%c", letrasim);
          fprintf(gua, "\n%d", netapa);
          fprintf(gua, "\n%d", ntemp);
          for (f = 0; f < ntemp; f++) {
            fprintf(gua, "\n%d", tempo[f]);
          }
          fprintf(gua, "\n%d", nentrada);
          for (f = 0; f < nentrada; f++) {
            fprintf(gua, "\n%d", entrad[f]);
          }
          fprintf(gua, "\n%d", nsalida);
          for (f = 0; f < nsalida; f++) {
            fprintf(gua, "\n%d", salidas[f]);
          }
          fprintf(gua, "\n%s", nombrep);
          fprintf(gua, "\n%d", initot);
          for (f = 0; f < initot; f++) {
            fprintf(gua, "\n%d", inietapa[f]);
          }
          fclose(gua);
          break;
        // Estructura
        case 1:
          minicio(modi, letra);
          printf("\n N%cmero m%cximo de etapas anteriores (entradas) a una: ", 163, 160);
          do {
            petapa = falloca();
            minium(petapa);
          } while (petapa < 1 || petapa > 32);
          printf("\n N%cmero m%cximo de condiciones de la transici%cn: ", 163, 160, 162);
          do {
            pancho = falloca();
            minium(pancho);
          } while (pancho < 1 || pancho > 32);
          printf("\n N%cmero m%cximo de etapas posteriores (salidas) a una: ", 163, 160);
          do {
            pnega = falloca();
            minium(pnega);
          } while (pnega < 1 || pnega > 32);
          printf("\n Hay secuencias simult%cneas? (s) (n): ", 160);
          if (petapa * pnega == 1) {
            printf("n\n");
            letrasim = no;
          }
          else {
            letrasim = sino();
          }
          mfin(modi, letra);
          break;
        // TEMP
        case 2:
          minicio(modi, letra);
          printf("\n Cuantos temporizadores hay?: ");
          do {
            ntemp = falloca();
            maxcin(ntemp);
          } while (ntemp > 64);
          if (ntemp > 0) {
            printf("\n Dime el tiempo de temporizaci%cn (1000 = 1 segundo) del temporizador: ", 162);
            for (f = 0; f < ntemp; f++) {
              printf("\n T[%d]: ", f);
              do {
                tempo[f] = fallote();
                if (tempo[f] == 0) {
                  textcolor(DARKGRAY);
                  printf("\n No puede ser 0: ");
                  textcolor(WHITE);
                }
              } while (tempo[f] == 0);
              if(tempo[f] > 65535) longtemp = 1;
            }
          }
          mfin(modi, letra);
          break;
        // ETAPAS
        case 3:
          minicio(modi, letra);
          printf("\n Cuantas etapas tiene?: ");
          do {
            netapa = falloca();
            mmetapa(netapa);
          } while (netapa < 3 || netapa > 128);
          printf("\n Dime las etapas iniciales.\n (Pulse intro, sin introducir n%cmero, para continuar)", 163);
          inietapa[0] = 0;
          initot = 1;
          printf("\n Etapa: 0\n");
          for (f = 1; f < (netapa - 2); f++) {
            printf("\n Etapa: ");
            do {
              inietapa[f] = falloca();
              error = ereti (inietapa[f], netapa, inietapa, initot);
            } while (error == 1);
            if (inietapa[f] == 0) f = netapa;
            else initot++;
            if (initot >= 64) f = netapa;
          }
          mfin(modi, letra);
          break;
        // Entradas
        case 4:
          minicio(modi, letra);
          printf("\n Cuantas entradas de pin usa?: ");
          do {
            nentrada = falloca();
            maxcin(nentrada);
          } while (nentrada > 64);
          if (nentrada > 0) {
            printf("\n Dime el n%cmero de pin de las entradas: ", 163);
            for (f = 0; f < nentrada; f++) {
              printf("\n I[%d]: ", f);
              entrad[f] = falloca();
            }
          }
          mfin(modi, letra);
          break;
        // Salidas
        case 5:
          minicio(modi, letra);
          printf("\n Cuantas salidas de pin usa?: ");
          do {
            nsalida = falloca();
            maxcin(nsalida);
          } while (nsalida > 64);
          if (nsalida > 0) {
            printf("\n Dime el n%cmero de pin de las salidas: ", 163);
            for (f = 0; f < nsalida; f++) {
              printf("\n O[%d]: ", f);
              salidas[f] = falloca();
            }
          }
          mfin(modi, letra);
          break;
        // NOMBRE
        case 6:
          minicio(modi, letra);
          printf("\n Dime el nombre del archivo (Predeterminado: 0): ");
          do {
            gets(nombrep);
            nomer = nombrespa(nombrep);
          } while (nomer != 0);
          nombre = int(nombrep[0]);
          if (nombre == 0) {
            nombrep[0] = '0';
            nombrep[1] = '\0';
          }
          if ((nombrep[0] != '0') && (nombrep[1] != '\0')) {
            lon = strlen (nombrep);
            for (f = 0; f < lon; f++) {
              nombre = int(nombrep[f]);
              if (nombre == 32) {
                nombrep[f] = '_';
              }
            }
          }
          mfin(modi, letra);
          break;
      }
      // Comprobación error
      if (n == 4) {
        mod = 1;
        adve = advio (entrad, nentrada, mod);
      }

      if (n > 4) {
        if (modi == 0) {
          mod = 0;
        }
        else {
          mod = 1;
        }
        if (modi == 4 || modi == 0) {
          adve = advio (entrad, nentrada, mod);
          adv = advert(salidas, entrad, nsalida, nentrada, mod);
        }
        if (modi == 5 || modi == 0) {
          advs = advio (salidas, nsalida, mod);
          adv = advert(salidas, entrad, nsalida, nentrada, mod);
        }
        if (n == 7 && (adv || adve || advs) == 0) {
          letra = no;
          n = 6;
        }
      }

    } while (modi != 0);

    //FINAL
    if ((adv || adve || advs) == 0) {
      textcolor(LIGHTGREEN);
    }
    printf("\n *** Plantilla finalizada ***   Pulse intro para salir.");
    if (n == 5) {
      printf(" Y generar plantilla.\n                                O (m) para modificar: ");
      finmod = ffinm();
      if (finmod == 1) {
        letra = si;
      }
    }
    else {
      finmod = 0;
    }
  } while (finmod != 0);
  ///Creación Plantilla
  creaplantilla (petapa, pancho, pnega, letrasim, netapa, initot, inietapa, ntemp, tempo, nentrada, entrad, nsalida, salidas, nombrep, longtemp);
  if (n == 6) {
    getch();
  }
  return 0;
}
