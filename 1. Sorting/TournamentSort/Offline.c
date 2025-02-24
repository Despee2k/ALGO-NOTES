#include "../../include/utils.h"
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define INF INT_MAX

int *createHeap(int size, int heapSize){
    int *newArr = calloc(heapSize, sizeof(int));

    int i = 0;
    int j = heapSize - 1;
    while(i < size){
        newArr[j--] = i++;
    } 

    return newArr;
}

void tournamentSort(int arr[], int size){
    int heapSize = 2 * size - 1;
    int *heap = createHeap(size, heapSize);

    int *output = malloc(sizeof(int) * size);

    for(int i = 0; i < size; i++){
        int right = heapSize - 1;
        int left = right - 1;
        while(left > 0){
            if(arr[heap[right]] <= arr[heap[left]]){
                heap[(right - 1) / 2] = heap[right];
            } else {
                heap[(left - 1) / 2] = heap[left];
            }
            right -= 2;
            left -= 2;
        }

        output[i] = arr[heap[0]];
        arr[heap[0]] = INF;
    }

    memcpy(arr, output, sizeof(int) * size);
}

int main(void){
    int arr[10] = {8, 9, 1, 7, 3, 10, 5, 4, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    tournamentSort(arr, size);
    printer(arr, size);

    return 0;
}