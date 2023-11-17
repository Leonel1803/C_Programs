#include <stdio.h>
#include <stdlib.h>

// Declaracón de estructura que guarada datos de lugares en una matriz
typedef struct {
  int ocupado, id, edad, estatus, vacunado, dias, cubrebocas;
} CELDA;

void inicializar(void *datos) {
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
      if((adatos->vacunado != 0 && adatos->cubrebocas != 0) && (adatos->vacunado == 8 && adatos->cubrebocas == 8)) {
          adatos->cubrebocas = 0;
          adatos->vacunado = 0;
      }
      else {
          i--;
      }
  }
  adatos = datos;

  //no vacunadas(0) y con cubrebocas(1)
  for (int i = 0; i<135; i++){
      randomizer = rand() % 900;
      adatos += randomizer;
      if((adatos->vacunado != 0 && adatos->cubrebocas != 1) && (adatos->vacunado == 8 && adatos->cubrebocas == 8)) {
          adatos->cubrebocas = 1;
          adatos->vacunado = 0;
      }
      else{
          i--;
      }
  }
  adatos = datos;

  //vacunadas(1) y sin cubrebocas(0)
  for (int i = 0; i<135; i++){
      randomizer = rand() % 900;
      adatos += randomizer;
      if((adatos->vacunado != 1 && adatos->cubrebocas != 0) && (adatos->vacunado == 8 && adatos->cubrebocas == 8)) {
          adatos->cubrebocas = 0;
          adatos->vacunado = 1;
        }
      else {
          i--;
      }
  }
  adatos = datos;

  //vacunadas(1) y con cubrebocas(1)
  for (int i = 0; i<135; i++){
      randomizer = rand() % 900;
      adatos += randomizer;
      if((adatos->vacunado != 1 && adatos->cubrebocas != 1) && (adatos->vacunado == 8 && adatos->cubrebocas == 8)) {
          adatos->cubrebocas = 1;
          adatos->vacunado = 1;
      }
      else {
          i--;
      }
  }
  adatos = datos;

}

int main() {
  // Declaración de matriz
  CELDA datos[30][30];

  inicializar(datos);
  for (int i = 0; i < 30; i++) {
    for (int j = 0; j < 30; j++) {
      printf("Ocupado: %d, ID:%d, Eststus: %d, Cubrebocas: %d, Vacunado: %d\n",datos[i][j].ocupado,datos[i][j].id,datos[i][j].estatus,datos[i][j].cubrebocas, datos[i][j].vacunado);
    }
    printf("\n\n\n");
  }

  return 0;
}