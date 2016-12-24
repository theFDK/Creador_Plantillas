  /*----------------------------------------------------------------------|
  | " Copyright 2016 the FDK " el programa se distribuye bajo los términos| 
  | de la General Public License de GNU.                                  |                     
  |----------------------------------------------------------------------*/

void creaplantilla (int petapa, int pancho, int pnega, char letrasim, int netapa, int initot, int inietapa[64], int ntemp, long tempo[64], int nentrada, int entrad[64], int nsalida, int salidas[64], char nombrep[64],int longtemp) {
  int g, f, h, lon, lonruta, lonombre, numero, cnombre = 0;
  char nomcifra[64], *nom2 = "plantilla.ino", nomli[64], *nomli2 = "plantilla.h", nomdire[512], *nomc = "plantilla", nomdirec[512], nomino[512], nomlienc[512];
  FILE*txp;
  FILE*hlib;
#define si 's'

  // Ruta carpeta
  getcwd(nomdire, 511);
  //cambio /
  lonruta = strlen(nomdire);
  for (f = 0; f < lonruta; f++) {
    numero = int(nomdire[f]);
    if (numero == 92) {
      nomdirec[f] = '/';
    }
    else {
      nomdirec[f] = nomdire[f];
    }
  }
  // Carpeta nombre
  if (nombrep[0] == '0' && (nombrep[1] == '\0')) {
    lon = strlen (nomc);
    lonombre = lon + lonruta;
    nomdirec[lonruta] = '/';
    for (f = lonruta + 1; f <= lonombre; f++) {
      nomdirec[f] = nomc[cnombre];
      cnombre += 1;
    }
  }
  else {
    numero = int(nombrep[0]);
    if (numero >= 48 && numero <= 57) {
      nomcifra[0] = '_';
      lon = strlen (nombrep);
      for (f = 0; f <= lon; f++) {
        nomcifra[f + 1] = nombrep[f];
      }
      nomcifra[lon + 1] = '\0';
      strcpy(nombrep, nomcifra);
    }
    lon = strlen (nombrep);
    lonombre = lon + lonruta;
    nomdirec[lonruta] = '/';
    for (f = lonruta + 1; f <= lonombre; f++) {
      nomdirec[f] = nombrep[cnombre];
      cnombre += 1;
    }
  }
  nomdirec[lonombre + 1] = '\0';
  mkdir (nomdirec);
  //Nombre archivos
  if (nombrep[0] == '0' && (nombrep[1] == '\0')) {
    strcpy(nombrep, nom2);
    strcpy(nomli, nomli2);
  }
  else {
    strcpy(nomli, nombrep);
    lon = strlen (nombrep);
    nomli[lon] = '.';
    nomli[lon + 1] = 'h';
    nomli[lon + 2] = '\0';
    nombrep[lon] = '.';
    nombrep[lon + 1] = 'i';
    nombrep[lon + 2] = 'n';
    nombrep[lon + 3] = 'o';
    nombrep[lon + 4] = '\0';
  }
  //Nombre ino
  strcpy(nomino, nomdirec);
  lon = strlen (nombrep);
  lonruta = strlen (nomino);
  lonombre = lon + lonruta;
  nomino[lonruta] = '/';
  cnombre = 0;
  for (f = lonruta + 1; f <= lonombre; f++) {
    nomino[f] = nombrep[cnombre];
    cnombre += 1;
  }
  nomino[lonombre + 1] = '\0';
  //Nombre libreria
  strcpy(nomlienc, nomdirec);
  lon = strlen (nomli);
  lonruta = strlen (nomlienc);
  lonombre = lon + lonruta;
  nomlienc[lonruta] = '/';
  cnombre = 0;
  for (f = lonruta + 1; f <= lonombre; f++) {
    nomlienc[f] = nomli[cnombre];
    cnombre += 1;
  }
  nomlienc[lonombre + 1] = '\0';

  //////Inicio///////
  hlib = fopen("%s", nomlienc);
  hlib = fopen(nomlienc, "w");
  fprintf(hlib, "#include \"Arduino.h\"\n");
  
  if (ntemp > 0) {
    fprintf(hlib, "\n//Temporizadores, comparadores, tiempo.\nbool T[%d];", ntemp);
    fprintf(hlib, "\nunsigned long pret[%d]={", ntemp);
    for (f = 0; f < ntemp; f++) {
      fprintf(hlib, "0", tempo[f]);
      if (f + 1 < ntemp) {
        fprintf(hlib, ",");
      }
    }
    fprintf(hlib, "};\n");
   if (longtemp == 1) {
    fprintf(hlib, "unsigned long tempst[%d]={", ntemp);
  }
  else {
    fprintf(hlib, "unsigned int tempst[%d]={", ntemp);
  }
  for (f = 0; f < ntemp; f++) {
    fprintf(hlib, "%d", tempo[f]);
    if (f + 1 < ntemp) {
      fprintf(hlib, ",");
    }
  }
  fprintf(hlib, "};\n");}

  // ETAPAS DEFINIDIR
  fprintf(hlib, "\n//Etapas, flancos, entradas, salidas y variables.\nbool E [%d];", netapa);
  fprintf(hlib, "\nbool fe [%d];\nint f;\nbyte g;\nbyte h;", netapa);

  // ENTRADAS
  if (nentrada > 0) {
    fprintf(hlib, "\nconst byte I [%d]={", nentrada);
    for (f = 0; f < nentrada; f++) {
      fprintf(hlib, "%d", entrad[f]);
      if (f + 1 < nentrada) {
        fprintf(hlib, ",");
      }
    }
    fprintf(hlib, "};\nbool i [%d];", nentrada);
  }

  // Salidas
  if (nsalida > 0) {
    fprintf(hlib, "\nconst byte O [%d]={", nsalida);
    for (f = 0; f < nsalida; f++) {
      fprintf(hlib, "%d", salidas[f]);
      if (f + 1 < nsalida) {
        fprintf(hlib, ",");
      }
    }
    fprintf(hlib, "};");
  }

  //Momentaneo
  if (nsalida > 0) {
    fprintf(hlib, "\nbyte M [%d]={", nsalida);
    for (f = 0; f < nsalida; f++) {
      fprintf(hlib, "0");
      if (f + 1 < nsalida) {
        fprintf(hlib, ",");
      }
    }
    fprintf(hlib, "};\n");
  }
  
    // TEMPORIZADORES
  //long o int
  for (f = 0; f < ntemp; f++) {
    if (tempo[f] > 65535) {
      longtemp = 1;
    }
  }
  fprintf(hlib, "\n//Funciones para la temporizacion.\nunsigned long pretemp (");
  if (longtemp == 1) {
    fprintf(hlib, "unsigned long");
  }
  else {
    fprintf(hlib, "unsigned int");
  }
  fprintf(hlib, " t){\nunsigned long tiempo = millis();\nunsigned long ptemp = tiempo + t;\nreturn ptemp;}\n");

  fprintf(hlib, "\nbyte temp (unsigned long pt){\nunsigned long tiempo = millis();\nif(tiempo >= pt) return 1;\nelse return 0;}\n");
  
    //parpa
  fprintf(hlib, "\n//Funcion para parpadear.\nbyte parpadeo (unsigned long pretemp, ");
  if (longtemp == 1) {
    fprintf(hlib, "unsigned long");
  }
  else {
    fprintf(hlib, "unsigned int");
  }
  fprintf(hlib, " temp){\nunsigned long tiempo = millis();");
  fprintf(hlib, "\nif(tiempo>=temp+pretemp) return 3;\nelse if(tiempo>=pretemp) return 2;\nelse return 1;}\n");

  //Transición
  fprintf(hlib, "\n//Funcion para la transicion.\nbyte etapa (byte eact");
  for (g = 1; g <= petapa; g++) {
    fprintf(hlib, ",byte eant%d", g);
    for (f = 1; f < pancho; f++) {
      fprintf(hlib, ",byte tran%d%d", g, f);
    }
  }
  for (f = 1; f <= pnega; f++) {
    fprintf(hlib, ",byte esig%d", f);
  }
  fprintf(hlib, "){\n");
  //Creación 2
  fprintf(hlib, "if(eact+");
  for (g = 1; g <= petapa; g++) {
    fprintf(hlib, "(eant%d", g);
    for (f = 1; f < pancho; f++) {
      fprintf(hlib, "&&tran%d%d", g, f);
    }
    fprintf(hlib, ")");
    if (g != petapa) {
      fprintf(hlib, "+");
    }
  }
  for (f = 1; f <= pnega; f++) {
    fprintf(hlib, "&&(!esig%d)", f);
  }
  fprintf(hlib, "==1) return 1;\nelse return 0;}\n");
  //Creación AND
  if (letrasim == si) {
    fprintf(hlib, "\n//Funcion para la transicion Simultanea.\nbyte etapand (byte eact");
    for (g = 1; g <= petapa; g++) {
      fprintf(hlib, ",byte eant%d", g);
      for (f = 1; f < pancho; f++) {
        fprintf(hlib, ",byte tran%d%d", g, f);
      }
    }
    for (f = 1; f <= pnega; f++) {
      fprintf(hlib, ",byte esig%d", f);
    }
    fprintf(hlib, "){\n");
    //2
    fprintf(hlib, "if(eact+(");
    for (g = 1; g <= petapa; g++) {
      fprintf(hlib, "(eant%d", g);
      for (f = 1; f < pancho; f++) {
        fprintf(hlib, "&&tran%d%d", g, f);
      }
      fprintf(hlib, ")");
      if (g != petapa) {
        fprintf(hlib, "&&");
      }
    }
    fprintf(hlib, ")");
    for (f = 1; f <= pnega; f++) {
      fprintf(hlib, "&&(!esig%d)", f);
    }
    fprintf(hlib, "==1) return 1;\nelse return 0;}\n");
  }
  // Lineal
  if (petapa > 1 || pnega > 1) {
    fprintf(hlib, "\n//Funcion para la transicion lineal.\nbyte etapalin (byte eact,byte eant1");
    for (f = 1; f < pancho; f++) {
      fprintf(hlib, ",byte tran1%d", f);
    }
    fprintf(hlib, ",byte esig1){\nif(eact+(eant1");
    for (f = 1; f < pancho; f++) {
      fprintf(hlib, "&&tran1%d", f);
    }
    fprintf(hlib, ")&&(!esig1)==1) return 1;\nelse return 0;}\n");

    fprintf(hlib, "\n//Transicion Lineal\n");
    fprintf(hlib, "//E[f] = etapalin (E[f],E[f-1]");
    if (pancho > 1) {
      fprintf(hlib, ",1");
    }//1 condición
    for (g = 2; g < pancho; g++) {
      fprintf(hlib, ",1");
    }//+condiciones
    fprintf(hlib, ",E[f+1]);\n");
  }
  
  //Temporizar
  fprintf(hlib, "\n/*\n//Funcion para temporizar:\nif(fe[f]==1) pret[0] = pretemp (tempst[0]);\nT[0] = temp (pret[0]);\n");

  //Parpadeo
  fprintf(hlib, "\n//Funcion para parpadear:\nif(fe[f]==1) M[0]=3;");
  fprintf(hlib, "\nif(M[0]==3) pret[0] = pretemp (tempst[0]);\nM[0] = parpadeo(pret[0], tempst[0]);\n*/");

  fclose(hlib);
  
  /***//////// SETUP////////***/
  txp = fopen("%s", nomino);
  txp = fopen(nomino, "w");
  fprintf(txp, "#include \"%s\"", nomli);
  fprintf(txp, "\n\nvoid setup() {\n//Etapas iniciales.");
  for (f = 0; f < initot; f++) {
    fprintf(txp, "\nE[%d]=1;\nfe[%d]=1;", inietapa[f], inietapa[f]);
  }
  for (f = 0; f < nentrada; f++) {
    fprintf(txp, "\npinMode(I[%d], INPUT);", f);
  }
  for (f = 0; f < nsalida; f++) {
    fprintf(txp, "\npinMode(O[%d], OUTPUT);", f);
  }
  fprintf(txp, "\n}");

  //LOOP ENTRADAS
  fprintf(txp, "\n\nvoid loop(){\n");
  if (nentrada > 0) {
    fprintf(txp, "//Lectura de entradas.\nfor(f=0;f<%d;f++){", nentrada);
    fprintf(txp, "\nif (digitalRead(I[f]) == HIGH) i[f] = 1;\nelse i[f] = 0;}\n");
  }

  // ETAPAS TRANS
  fprintf(txp, "\n//Transiciones.\nfor(g=0;g<2;g++){\nfor(f=%d;f>=0;f--){\nif(g==0||(g&&E[f])==1){\nswitch(f){", netapa - 1);
  fprintf(txp, "\ncase 0 :\nE[f] = etapa (E[f],E[%d]", netapa - 1);
  for (f = 0; f < netapa; f++) {
    if (f != 0) {
      fprintf(txp, "\ncase %d :\nE[f] = etapa (E[f],E[f-1]", f);
    }
    if (pancho > 1) {
      fprintf(txp, ",1");
    }//1 condición
    for (g = 2; g < pancho; g++) {
      fprintf(txp, ",1");
    }//+condiciones
    for (g = 2; g <= petapa; g++) {
      if (f == 0) {
        fprintf(txp, ",E[%d]", netapa - g);
      }
      else {
        fprintf(txp, ",E[f-%d]", g);
      }//+Etapa anterior
      for (h = 1; h < pancho; h++) {
        fprintf(txp, ",0");
      }//++condiciones
    }
    for (g = 1; g <= pnega; g++) {
      if (f == netapa - 1) {
        fprintf(txp, ",E[%d]", g - 1);
      }
      else {
        fprintf(txp, ",E[f+%d]", g);
      } //+Etapa seguiente
    }
    fprintf(txp, ");\nbreak;");
  }
  fprintf(txp, "\ndefault: //Reset etapas.\nfor(h=0;h<%d;h++) E[h]=0;\n", netapa);
  for (f = 0; f < initot; f++) {
    fprintf(txp, "E[%d]=1;\nfe[%d]=1;\n", inietapa[f], inietapa[f]);
  }
  fprintf(txp, "break;}\n}\n}\n}\n");
  //RESET TEMP
  if (ntemp > 0) {
    fprintf(txp, "\n//Reset de temporizadores.\nfor(f=0;f<%d;f++) T[f]=0;\n", ntemp);
  }
  //SALIDAS
  fprintf(txp, "\n//Acciones.\nfor(f=0;f<%d;f++){\nif (E[f]==1){\nswitch(f){", netapa);
  for (f = 0; f < netapa; f++) {
    fprintf(txp, "\ncase %d :\n\nbreak;", f);
  }
  fprintf(txp, "}\n}\n}\n");
  //Acciones momentaneas
  if (nsalida > 0) {
    fprintf(txp, "\n//Acciones momentaneas.\nfor(f=0;f<%d;f++){\nif (M[f] == 1){\ndigitalWrite(O[f],HIGH);\nM[f]=2;}", nsalida);
    fprintf(txp, "\nelse if(M[f]==2){\ndigitalWrite(O[f],LOW);\nM[f]=0;}\n}\n");
  }
  //FLANCOS
  fprintf(txp, "\n//Flancos de las etapas.\nfor(f=0;f<%d;f++){", netapa);
  fprintf(txp, "\nif(E[f]==1) fe[f]=0;\nelse fe[f]=1;}\n}");

  fclose(txp);
}
