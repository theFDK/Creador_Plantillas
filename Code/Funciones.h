  /*----------------------------------------------------------------------|
  | " Copyright 2016 the FDK " el programa se distribuye bajo los términos| 
  | de la General Public License de GNU.                                  |                     
  |----------------------------------------------------------------------*/
  
//advierte duplicidad entre pines de entrada y salida
int advert (int ou[], int in[], int lo, int li, int mod) {
  int f, g, c = 0, entra[64], salidas[64];
  for (f = 0; f < li; f++) {
    for (g = 0; g < lo; g++) {
      if (in[f] == ou[g]) {
        c += 1;
        entra[c - 1] = f;
        salidas[c - 1] = g;
      }
    }
  }
  if (c > 0) {
    if (mod == 1) {
      textcolor(LIGHTRED);
      printf("\n ***************\n * ADVERTENCIA *   %d duplicidad/es en n%cmero de pin entre \n ***************   Entradas:", c, 163);
      for (f = 0; f < c; f++) {
        if (entra[f] < 10) printf(" ");
        printf(" [%d]", entra[f]);
      }
      printf("\n                   Salidas :");
      for (f = 0; f < c; f++) {
        if (salidas[f] < 10) printf(" ");
        printf(" [%d]", salidas[f]);
      }
      printf("\n\n");
      textcolor(WHITE);
    }
    return 1;
  }
  else {
    return 0;
  }
}

//advierte  duplicidad entre pines de entrada o salida
int advio (int io[], int lio, int mod) {
  int f, g, c = 0, dupli[64];
  for (f = 0; f < lio; f++) {
    for (g = 0; g < lio; g++) {
      if (f != g) {
        if (io[f] == io[g]) {
          c += 1;
          dupli[c - 1] = f;
          g = lio;
        }
      }
    }
  }
  if (c > 0) {
    if (mod == 1) {
      textcolor(YELLOW);
      printf("\n * AVISO * Duplicidades en n%cmero de pin: \n           ", 163);
      for (f = 0; f < c; f++) {
        printf("[%d] ", dupli[f]);
      }
      printf("\n\n");
      textcolor(WHITE);
    }
    return 1;
  }
  else {
    return 0;
  }
}

//comprobación caracteres introducidos
int falloca () {
  int f, c, l, n,cifra;
  char pa[6];
  do {
    do {
      c = 0;
      gets(pa);
      l = strlen (pa);
      if ((l == 4) && (pa[0] == 'e') && (pa[1] == 'x') && (pa[2] == 'i') && (pa[3] == 't')) {
        exit(0);
      }
      for (f = 0; f < l; f++) {
        n = int(pa[f]);
        if (n < 48 || n > 57) {
          c += 1;
        }
      }
      if (c > 0) {
        textcolor(DARKGRAY);
        printf("\n Error, ha introducido una letra o s%cmbolo, introduzca un n%cmero: ", 161, 163);
        textcolor(WHITE);
      }
    } while (c != 0);
    cifra = atoi(pa);
    if (cifra > 255 || cifra < 0) {
      textcolor(DARKGRAY);
      printf("\n Error, no puede ser mayor de 255: ");
      textcolor(WHITE);
      c += 1;
    }
  } while (c != 0);
  return cifra;
}

//comprobación tiempo introducido
long fallote () {
  int f, c, l, n;
  long cifra;
  char pa[11];
  do {
    do {
      c = 0;
      gets(pa);
      l = strlen (pa);
      if ((l == 4) && (pa[0] == 'e') && (pa[1] == 'x') && (pa[2] == 'i') && (pa[3] == 't')) {
        exit(0);
      }
      for (f = 0; f < l; f++) {
        n = int(pa[f]);
        if (n < 48 || n > 57) {
          c += 1;
        }
      }
      if (c > 0) {
        textcolor(DARKGRAY);
        printf("\n Error, ha introducido una letra o s%cmbolo, introduzca un n%cmero: ", 161, 163);
        textcolor(WHITE);
      }
    } while (c != 0);
    cifra = atol(pa);
    if (cifra > 2147483647 || cifra < 0) {
      textcolor(DARKGRAY);
      printf("\n Error, no puede ser mayor de 2147483647: ", 160);
      textcolor(WHITE);
      c += 1;
    }
  } while (c != 0);
}

//comprobación nombre introducido
int nombrespa (char nombre[64]) {
  int l, n, c = 0, f;
  l = strlen (nombre);
  if ((l == 4) && (nombre[0] == 'e') && (nombre[1] == 'x') && (nombre[2] == 'i') && (nombre[3] == 't')) {
    exit(0);
  }
  if (l > 58) {
    textcolor(DARKGRAY);
    printf("\n Error, no puede ser mayor de 58 caracteres: ", 160);
    textcolor(WHITE);
    c = 1;
  }
  else {
    for (f = 0; f < l; f++) {
      n = int(nombre[f]);
      if ((n < 48 || n > 57) && (n < 65 || n > 90) && (n < 97 || n > 122) && (n != 95) && (n != 32)) {
        c = 2;
      }
    }
    if (c > 1) {
      textcolor(DARKGRAY);
      printf("\n Error, no puede contener s%cmbolos el nombre: ", 161);
      textcolor(WHITE);
    }
  }
  if (c > 0) {
    return 1;
  }
  else {
    return 0;
  }
}

//comprobación respuesta si y no
char sino () {
  char letra[6];
  int l, e = 1, f; //e0 error
  do {
    gets(letra);
    l = strlen (letra);
    switch (l) {
      case 1:
        if (letra[0] == 'S' || letra[0] == 's') {
          return 's';
        }
        else if (letra[0] == 'n' || letra[0] == 'N') {
          return 'n';
        }
        else {
          e = 0;
        }
        break;
      case 2:
        if ((letra[0] == 's' || letra[0] == 'S') && (letra[1] == 'i' || letra[1] == 'I')) {
          return 's';
        }
        else if ((letra[0] == 'n' || letra[0] == 'N') && (letra[1] == 'o' || letra[1] == 'O')) {
          return 'n';
        }
        else {
          e = 0;
        }
        break;
      case 4:
        if ((letra[0] == 'e') && (letra[1] == 'x') && (letra[2] == 'i') && (letra[3] == 't')) {
          exit(0);
        }
        else {
          e = 0;
        }
        break;
      default:
        e = 0;
        break;
    }
    if (e == 0) {
      textcolor(DARKGRAY);
      printf("\n Error, tiene que introducir s (si) o n (no): ");
      textcolor(WHITE);
    }
  } while (e == 0);
}

//indicador de la parte finalizada al modificar
void mfin(int modi, char lletra) {
  if (lletra == 's') {
    printf("\n * Modificaci%cn de ", 162);
    textcolor(LIGHTCYAN);
    switch (modi) {
      case 1:
        printf("estructura");
        break;
      case 2:
        printf("temporizadores");
        break;
      case 3:
        printf("etapas");
        break;
      case 4:
        printf("entradas");
        break;
      case 5:
        printf("salidas");
        break;
      case 6:
        printf("nombre");
        break;
      default:
        break;
    }
    textcolor(WHITE);
    printf(" finalizado *\n");
  }
}

//indicador de la parte a modificar
void minicio(int modi, char lletra) {
  int c, f;
  if (lletra == 'n') {
    textcolor(LIGHTCYAN);
    switch (modi) {
      case 1:

        printf("\n\n Estructura");
        c = 10;
        break;
      case 2:
        printf("\n\n Temporizadores");
        c = 14;
        break;
      case 3:
        printf("\n\n Etapas");
        c = 6;
        break;
      case 4:
        printf("\n\n Entradas");
        c = 8;
        break;
      case 5:
        printf("\n\n Salidas");
        c = 7;
        break;
      case 6:
        printf("\n\n Nombre");
        c = 6;
        break;
      default:
        c = 0;
        break;
    }
    textcolor(WHITE);
    if (c != 0) {
      for (f = c; f <= 47; f++) {
        printf("-");
      }
      printf("*\n");
    }
  }
}


//indica el máximo y el mínimo 
void minium (int un) {
  if (un < 1) {
    textcolor(DARKGRAY);
    printf("\n M%cnimo 1: ", 161);
    textcolor(WHITE);
  }
  if (un > 32) {
    textcolor(DARKGRAY);
    printf("\n M%cximo 32: ", 160);
    textcolor(WHITE);
  }
}

//indica el máximo
void maxcin (int cin) {
  if (cin > 64) {
    textcolor(DARKGRAY);
    printf("\n Como m%cximo 64: ", 160);
    textcolor(WHITE);
  }
}

//indica el máximo y el mínimo
void mmetapa (int netapa) {
  if (netapa < 3) {
    textcolor(DARKGRAY);
    printf("\n El m%cnimo es 3: ", 161);
    textcolor(WHITE);
  }
  if (netapa > 128) {
    textcolor(DARKGRAY);
    printf("\n El m%cximo es 128: ", 160);
    textcolor(WHITE);
  }
}

//comprueba si se quiere modificar 
int ffinm () {
  char lletra[6];
  int l;
  gets(lletra);
  l = strlen (lletra);
  if ((l == 4) && (lletra[0] == 'e') && (lletra[1] == 'x') && (lletra[2] == 'i') && (lletra[3] == 't')) {
    exit(0);
  }
  textcolor(WHITE);
  if (lletra[0] == 'm' || lletra[0] == 'M') {
    return 1;
  }
  else {
    return 0;
  }
}

//comprueba errores al indicar las etapas iniciales
int ereti (int E, int maxe, int inietapa[], int tot) {
  int f, c = 0;
  if (E >= maxe) {
    textcolor(DARKGRAY);
    printf("\n El m%cximo es %d: ", 160, maxe - 1);
    textcolor(WHITE);
    return 1;
  }
  else {
    for (f = 1; f <= tot; f++) {
      if ((E == inietapa[f]) && (f != tot)) {
        c += 1;
      }
    }
    if (c > 0) {
      textcolor(DARKGRAY);
      printf("\n Error, duplicidad: ");
      textcolor(WHITE);
      return 1;
    }
    else {
      return 0;
    }
  }
}
