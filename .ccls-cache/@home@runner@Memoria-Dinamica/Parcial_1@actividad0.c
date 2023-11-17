#include <stdio.h>

int main(void) {
 int exa1, exa2,exa3,exa4, exa5,exa6;
	printf("Examenes sincronos.");
	printf("\n Examen 1: ");
	scanf("%i",&exa1);
	printf("\n Examen 2: ");
	scanf("%i",&exa2);
	printf("\n Examen 3: ");
	scanf("%i",&exa3);
	printf("Examenes asincronos.");
	printf("\n Examen 1: ");
	scanf("%i",&exa4);
	printf("\n Examen 2: ");
	scanf("%i",&exa5);
	printf("\n Examen 3: ");
	scanf("%i",&exa6);

	int promedio = (exa1 + exa2 + exa3 + exa4 + exa5 + exa6)/6;
	int promedio2 = (exa1 + exa2 +exa3)/3;
	int regla1, regla2, regla3;
	if (promedio >= 6){regla1 =1; } else  {regla1=0;}
	if (promedio2 >= 6){regla2 =1; } else {regla2=0;}
	if (exa1>=6 && exa2>=6){regla3 =1;} else if (exa1>=6 && exa3>=6){regla3=1;}   else if (exa2>=6 && exa3>=6){regla3=1;} else {regla1=0;}

  int opc1= regla1 +regla2;
  int opc2=regla1 + regla3;

  if (opc1==2 && opc2==2){printf("El alumno Aprobado");}
  else {printf("El alumno Reprobado");}
  
  
  return 0;
}