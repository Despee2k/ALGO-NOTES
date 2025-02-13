#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void printer(int arr[]){
    for(int i = 0; i < MAX; i++){
        printf("[%d]", arr[i]);
    }
    printf("\n");
}

void countingSort(int arr[]){
    int maxVal = 0;

    for(int i = 0; i < MAX; i++){
        if(maxVal < arr[i]) maxVal = arr[i];
    }

    int newMax = maxVal + 1;

    int *newArr = calloc(newMax, sizeof(int));
    for(int i = 0; i < MAX; i++){
        newArr[arr[i]]++;
    }

    int maxAgain = MAX + 1;
    for(int i = 1; i < maxAgain; i++){
        newArr[i] = newArr[i] + newArr[i-1];
    }

    int outputArr[MAX];
    for(int i = MAX - 1; i >= 0; i--){
        outputArr[--(newArr[arr[i]])] = arr[i];
    }

    memcpy(arr, outputArr, sizeof(outputArr));
    free(newArr);
}

int main(void){
    int arr[MAX] = {8, 9, 1, 7, 3, 10, 5, 4, 2, 6};
    countingSort(arr);
    printer(arr);

    return 0;
}