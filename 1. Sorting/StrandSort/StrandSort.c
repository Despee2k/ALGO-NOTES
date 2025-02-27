#include "../../include/utils.h"
#include <stdlib.h>
#include <string.h>

int *merger(int strand[], int *strandSize, int sorted[], int *sortedSize) {
    int *merged = malloc(sizeof(int) * (*strandSize + *sortedSize));
    int i = 0, j = 0, k = 0;

    while (i < *strandSize && j < *sortedSize) {
        if (strand[i] <= sorted[j]) {
            merged[k++] = strand[i++];
        } else {
            merged[k++] = sorted[j++];
        }
    }

    while (i < *strandSize) {
        merged[k++] = strand[i++];
    }
    while (j < *sortedSize) {
        merged[k++] = sorted[j++];
    }

    memcpy(sorted, merged, sizeof(int) * k);
    *sortedSize = k;
    
    return sorted;
}

void strandSort(int arr[], int size){
    int *sorted = malloc(sizeof(int) * size);
    int sortedSize = 0;
    
    while(size > 0){
        int *strand = malloc(sizeof(int) * size);
        int i = 0;  // arr counter
        int j = 0;  // strand counter
        int k = 0;  // new arr counter

        strand[j++] = arr[i++];
        
        for(i = 1; i < size; i++){
            if(strand[j - 1] <= arr[i]){
                strand[j++] = arr[i];
            } else {
                arr[k++] = arr[i];
            }
        }
        size = k;

        sorted = merger(strand, &j, sorted, &sortedSize);
        free(strand);
    }
    memcpy(arr, sorted, sizeof(int) * sortedSize);
}

int main(void){
    int arr[10] = {8, 9, 1, 7, 3, 10, 5, 4, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    strandSort(arr, size);
    printer(arr, size);
}