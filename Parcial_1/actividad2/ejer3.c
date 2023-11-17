#include <stdio.h>
#include <stdlib.h>

//Autores: Luis Alberto y León Rivera

//Función para invertir una palabra
void reverse(char *string1){
    //Calcula medida del string
    char *ptr1 = string1;
    int cont = 0;
    while (*ptr1 != '\0'){
        ptr1++;
        cont += 1;
    }
    //Retorna el apuntador a 0
    ptr1 -= cont;
    //Se hace un arreglo temporal que almacena el contenido del string original
    char temp_string[cont];
    char *ptr2 = temp_string;
    for(int i=0;i<cont;i++){
        *ptr2 = *ptr1;
        ptr1++;
        ptr2++;
    }
    //Apuntador hacia final del string temporal y apuntador al inicio del string original; el apuntador al temporal se va reduciendo y va copiando su contenido al arreglo original mientras este crece
    ptr1 -= cont;ptr2--;
    for(int i=cont;i>-1;i--){
        *ptr1 = *ptr2;
        ptr2--;
        ptr1++;
    }
}

int main(){
    char string1[] = "Guadalajara";
    reverse(string1);
    printf("%s\n", string1);  // Imprime arajaladauG

    system("pause");
    return 0;
}