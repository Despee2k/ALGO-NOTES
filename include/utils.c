#include "utils.h"

#include <stdio.h>

void printer(int arr[], int size){
    printf("Array: ");
    for(int i = 0; i < size; i++){
        printf("[%d]", arr[i]);
    }
    printf("\n");
}

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}