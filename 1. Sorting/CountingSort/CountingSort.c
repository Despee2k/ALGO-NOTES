#include "../../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void countingSort(int arr[], int size){
    // look for largest number in the array to use as index
    int largest = 0;
    for(int i = 0; i < size; i++){
        if(largest < arr[i]) largest = arr[i];
    }
    printf("%d\n", largest);
    
    int *newArr = calloc((largest + 1), sizeof(int));

    // increment each index based on how many times it appears in the original array
    for(int i = 0; i < size; i++){
        newArr[arr[i]]++;
    }

    // add previous counts
    int sizePlusOne = size + 1;
    for(int i = 1; i < sizePlusOne; i++){
        newArr[i] = newArr[i] + newArr[i-1];
    }

    // corresponding values represent the places in the count array
    int *outputArr = malloc(size * sizeof(int));
    for(int i = size - 1; i >= 0; i--){
        outputArr[--(newArr[arr[i]])] = arr[i];
    }

    memcpy(arr, outputArr, size * sizeof(int));
    free(newArr);
    free(outputArr);
}

int main(void){
    int arr[] = {8, 9, 1, 7, 3, 10, 5, 4, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, size);
    printer(arr, size);

    return 0;
}