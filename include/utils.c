#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

void printer(int arr[]){
    printf("Array: ");
    for(int i = 0; i < MAX; i++){
        printf("[%d]", arr[i]);
    }
    printf("\n");
}

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}