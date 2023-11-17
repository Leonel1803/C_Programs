#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    STACK s1 = stack_create(); //Crear un stack
    int *num;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    for(int i = 0; i < 7; i++){
        stack_push(s1, &arr[i]);
    }

    while(!stack_empty(s1)){
        num = stack_pop(s1);
        printf("%d\n", *num);
    }

    stack_destroy(s1);

    return 0;
}