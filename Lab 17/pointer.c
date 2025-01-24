#include<stdio.h>
void main(){
    int numA = 100;

    int *ptr = &numA;

    printf("Value of numA: %d\n", numA);

    printf("Value of numA: %d\n", *ptr);

    int arr[] = {10, 20, 30, 40, 50};

    int *ptrA  = &arr;

    int i;
    for(i = 0; i < 5; i++){
        printf("Value of arr[%d]: %d\n", i, *(ptrA + i));
    }

    int numB = 1000;

    int *ptrB = &numB;

    int **ptrB1 = &ptrB; 
}