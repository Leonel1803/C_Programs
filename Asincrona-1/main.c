#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaracón de estructura que guarada datos de lugares en una matriz
typedef struct {
  int ocupado, id, edad, estatus, vacunado, dias, cubrebocas;
} CELDA;

void ops(void *datos);

void inicializar(void *datos) {
  srand(time(NULL));
  CELDA *adatos;
  adatos = datos;
  int randomizer;

  // Asignar ocupados
  for (int i = 0; i < 900; i++) {
    adatos->ocupado = 1;
    adatos++;
  }
  adatos = datos;

  // Asignar no ocupados
  for (int i = 0; i < 360; i++) {
    randomizer = rand() % 900;
    // Se hacen if's para que no se vuelvan a repetir lugares
    adatos += randomizer;
    if (adatos->ocupado != 0) {
      adatos->ocupado = 0;
    } else {
      i--;
    }
    adatos = datos;
  }

  // Asignar ID
  for (int i=0; i < 900; i++) {
      adatos->id = i+1;
      adatos++;
  }
  adatos = datos;

  //Asignar edad
  for (int i=0; i < 900; i++) {
      randomizer = rand() % 91;
      adatos->edad = randomizer;
      adatos++;
  }
  adatos = datos;

  // Asignar estatus   0=sano  1=enfermo  2=recuperado 8=no ocupado
  for (int i=0; i < 900; i++) {
      if (adatos->ocupado == 1){
          adatos->estatus = 0;
      }
      else if (adatos->ocupado == 0){
          adatos->estatus = 8;
      }
      adatos++;
  }
  adatos = datos;

  //VACUNAS Y CUBREBOCAS
  for (int i=0; i<900; i++) {
      adatos->vacunado = 8;
      adatos->cubrebocas = 8;
      adatos++;
  }
  adatos = datos;

  //no vacunadas(0) y sin cubrebocas(0)
  for (int i = 0; i<135; i++){
      randomizer = rand() % 900;
      adatos += randomizer;
      if(adatos->estatus == 0 && ((adatos->vacunado != 0 && adatos->cubrebocas != 0) && (adatos->vacunado == 8 && adatos->cubrebocas == 8))) {
          adatos->cubrebocas = 0;
          adatos->vacunado = 0;
      }
      else {
          i--;
      }
      adatos = datos;
  }

  //no vacunadas(0) y con cubrebocas(1)
  for (int i = 0; i<135; i++){
      randomizer = rand() % 900;
      adatos += randomizer;
      if(adatos->estatus == 0 && ((adatos->vacunado != 0 && adatos->cubrebocas != 1) && (adatos->vacunado == 8 && adatos->cubrebocas == 8))) {
          adatos->cubrebocas = 1;
          adatos->vacunado = 0;
      }
      else{
          i--;
      }
      adatos = datos;
  }


  //vacunadas(1) y sin cubrebocas(0)
  for (int i = 0; i<135; i++) {
      randomizer = rand() % 900;
      adatos += randomizer;
      if (adatos->estatus == 0 &&
          ((adatos->vacunado != 1 && adatos->cubrebocas != 0) && (adatos->vacunado == 8 && adatos->cubrebocas == 8))) {
          adatos->cubrebocas = 0;
          adatos->vacunado = 1;
      } else {
          i--;
      }
      adatos = datos;
  }

  //vacunadas(1) y con cubrebocas(1)
  for (int i = 0; i<135; i++){
      randomizer = rand() % 900;
      adatos += randomizer;
      if(adatos->estatus == 0 && ((adatos->vacunado != 1 && adatos->cubrebocas != 1) && (adatos->vacunado == 8 && adatos->cubrebocas == 8))) {
          adatos->cubrebocas = 1;
          adatos->vacunado = 1;
      }
      else {
          i--;
      }
      adatos = datos;
  }

  //Paciente cero
  randomizer = rand() % 900;
  adatos += randomizer;
  while(adatos->ocupado == 0){
      adatos = datos;
      randomizer = rand() % 900;
      adatos += randomizer;
  }
  adatos->estatus = 1;
  adatos->dias = 0;
}


      /*S mayúscula donde hay persona no vacunada con  el status de sano y sin cubrebocas
        s minúscula donde hay una persona no vacunada con el status de sano y con cubrebocas
        V mayúscula donde hay persona vacunada con  el status de sano y sin cubrebocas
        v minúscula donde hay una persona vacunada con el status de sano y con cubrebocas
        E mayúscula donde hay persona con  el status de enfermo y sin cubrebocas
        e minúscula donde hay una persona con el status de enfermo y con cubrebocas
        r minúscula si su status es recuperado.*/
void impmat(void *datos){
    CELDA *aprint;
    aprint = datos;

    for(int i = 0; i<900; i++) {
        if (i % 15 == 0) {
            printf("\n");
        }
        if (aprint->ocupado == 0) {
            printf(" \t");
        } else if (aprint->vacunado == 0 && aprint->estatus == 0 && aprint->cubrebocas == 0) {
            printf("S\t");
        } else if (aprint->vacunado == 0 && aprint->estatus == 0 && aprint->cubrebocas == 1) {
            printf("s\t");
        } else if (aprint->vacunado == 1 && aprint->estatus == 0 && aprint->cubrebocas == 0) {
            printf("V\t");
        } else if (aprint->vacunado == 1 && aprint->estatus == 0 && aprint->cubrebocas == 1) {
            printf("v\t");
        }
        else if (aprint->estatus == 1 && aprint->cubrebocas == 0) {
            printf("\033[1;31mE\033[0m\t");
        }
        else if (aprint->estatus == 1 && aprint->cubrebocas == 1){
            printf("\033[1;31me\033[0m\t");
        }
        if(aprint->estatus == 2){
            printf("r\t");
        }
        aprint++;
    }
    aprint = datos;

    //Imprimir personas enfermas y personas sanas
    int enf = 0; 
    int rec = 0;
    for(int i = 0; i < 900; i++){
        if(aprint->estatus == 1 && aprint->ocupado == 1){ //Si su estatus es enfermo(1) y está ocupado el lugar(1), se le increment 1 a la variable enf (enfermos)
            enf++;
        }
        if(aprint->estatus == 2 && aprint->ocupado == 1){ //Si su estatus es recuperado(2) y está ocupado el lugar(1), se le increment 1 a la variable rec (recuperados)
            rec++;
        }
        aprint++;
    }
    printf("\n\nPersonas enfermas: %d\nPersonas recuperadas: %d\n", enf, rec);
}

void vecis(int a, void *datos, int num){
    srand(time(NULL));
    CELDA *enfermo;
    CELDA *adatos;
    adatos = datos;
    adatos += num;
    enfermo = adatos;
    adatos += a;
    CELDA *veci;
    veci = adatos;
    int randomizer;

    if(((veci->cubrebocas == 0) && (enfermo->cubrebocas == 0)) && veci->vacunado == 0) {
        randomizer = rand() % 20;
        if(randomizer == 0 || randomizer == 1){ //10% probabilidad de no contagio
            veci->estatus = 0;
        }
        else{
            veci->estatus = 1;
            veci->dias = 0;
        }
    }
    else if (((veci->cubrebocas == 1) || (enfermo->cubrebocas == 1)) && veci->vacunado == 0){
        randomizer = rand() % 20;
        if(randomizer == 0 || randomizer == 1 || randomizer == 2 || randomizer == 3){ //20% probablidad contagio
            veci->estatus = 1;
            veci->dias = 0;
        }
    }
    else if(((veci->cubrebocas == 1) && (enfermo->cubrebocas == 1)) && veci->vacunado == 0) {
        randomizer = rand() % 20;
        if(randomizer == 0 || randomizer == 1){ //10% probabilidad de contagio
            veci->estatus = 1;
            veci->dias = 0;
        }
    }
    else if(((veci->cubrebocas == 0) && (enfermo->cubrebocas == 0)) && veci->vacunado == 1) {
        randomizer = rand() % 20;
        if(randomizer == 0 || randomizer == 1 || randomizer == 2 || randomizer == 4 || randomizer == 5 || randomizer == 6 || randomizer == 7 || randomizer == 8){ //45% probabilidad de contagio
            veci->estatus = 1;
            veci->dias = 0;
        }
    }
    else if (((veci->cubrebocas == 1) || (enfermo->cubrebocas == 1)) && veci->vacunado == 1) {
        randomizer = rand() % 20;
        if(randomizer == 0 || randomizer == 1 || randomizer == 2){ //15% probabilidad de contagio
            veci->estatus = 1;
            veci->dias = 0;
        }
    }
    else if(((veci->cubrebocas == 1) && (enfermo->cubrebocas == 1)) && veci->vacunado == 1) {
        randomizer = rand() % 20;
        if(randomizer == 0){ //5% probabilidad de contagio
            veci->estatus = 1;
            veci->dias = 0;
        }
    }
}

void ops(void *datos){
    CELDA *adatos;
    adatos = datos;
    int dir_enf;
    int recorrer_fila = 0;
    //procesooooo operaciones
    for(int i = 0; i<900; i++){
        if(i % 15 == 0){ //Guarda cuantas veces se ha cambiado de fila
            recorrer_fila++;
        }
        if(adatos->estatus == 1){
            adatos->dias += 1;
            dir_enf = i;
            //Aquí esta el enfermo
            if((adatos->dias != 0 && i % 15 != 0) && (i % ((recorrer_fila*15)+14) != 0)) { //Si no está en la columna extrema izquierda ni derecha
                if ((adatos - 16)->estatus == 0) {
                    vecis(-16, datos, dir_enf);
                } else if ((adatos - 15)->estatus == 0) {
                    vecis(-15, datos, dir_enf);
                } else if ((adatos - 14)->estatus == 0) {
                    vecis(-14, datos, dir_enf);
                } else if ((adatos + 16)->estatus == 0) {
                    vecis(16, datos, dir_enf);
                } else if ((adatos + 15)->estatus == 0) {
                    vecis(15, datos, dir_enf);
                } else if ((adatos + 14)->estatus == 0) {
                    vecis(14, datos, dir_enf);
                } else if ((adatos - 1)->estatus == 0) {
                    vecis(-1, datos, dir_enf);
                } else if ((adatos + 1)->estatus == 0) {
                    vecis(1, datos, dir_enf);
                }
            }
            else if(adatos->dias != 0 && i % 15 == 0){ //Columnas extremas izquierda
                if ((adatos - 15)->estatus == 0) {
                    vecis(-15, datos, dir_enf);
                } else if ((adatos - 14)->estatus == 0) {
                    vecis(-14, datos, dir_enf);
                } else if ((adatos + 16)->estatus == 0) {
                    vecis(16, datos, dir_enf);
                } else if ((adatos + 15)->estatus == 0) {
                    vecis(15, datos, dir_enf);
                } else if ((adatos + 1)->estatus == 0) {
                    vecis(1, datos, dir_enf);
                }
            }
            else if((adatos->dias != 0) && (i % ((recorrer_fila*15)+14) == 0)){ //Columnas extremas derecha
                if ((adatos - 16)->estatus == 0) {
                    vecis(-16, datos, dir_enf);
                } else if ((adatos - 15)->estatus == 0) {
                    vecis(-15, datos, dir_enf);
                } else if ((adatos + 15)->estatus == 0) {
                    vecis(15, datos, dir_enf);
                } else if ((adatos + 14)->estatus == 0) {
                    vecis(14, datos, dir_enf);
                } else if ((adatos - 1)->estatus == 0) {
                    vecis(-1, datos, dir_enf);
                }
            }

            //Quitar contagio
            if(adatos->dias == 7){
                adatos->estatus = 2;
            }
        }
        adatos++;
    }
    adatos = datos;
}

int main() {
  // Declaración de matriz
  CELDA datos[30][30];
  int vuelta;
  int dia = 1;

  inicializar(datos);
  impmat(datos);
  do{
      printf("DIA %d\n\nQuieres volver a hacer una iteración?\n1)Si\nOtro)No\nResponde: ", dia);
      scanf("%d", &vuelta);
      ops(datos);
      impmat(datos);
      dia++;
  }while(vuelta == 1);


  return 0;
}