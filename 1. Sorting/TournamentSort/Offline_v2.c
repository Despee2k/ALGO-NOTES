#include "../../include/utils.h"
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define INF INT_MAX

int *createHeap(int arr[], int size, int heapSize){
    int *heap = malloc(sizeof(int) * heapSize);
    
    int i = 0;              // arr counter
    int j = heapSize - 1;   // heap counter
    while(i < size){
        heap[j--] = arr[i++]; 
    }
    while(j >= 0){
        heap[j--] = INF;
    }

    return heap;
}

void tournamentSort(int arr[], int size){
    int heapSize = 2 * size - 1;
    int *heap = createHeap(arr, size, heapSize);
      
    for(int i = 0; i < size && arr[i] != INF; i++){
        int RC = heapSize - 1;
        int LC = RC - 1;

        while(RC > 0){
            // extra condition for when the number of elements is odd
            // this ensures that index versus value does not occur
            if(RC == size - 1 && size % 2 != 0){
                heap[(RC - 1) / 2] = (heap[RC] < heap[heap[LC]]) ? RC : heap[LC];
            }
            else if(RC >= (size * 2 - 1) - size){
                heap[(RC - 1 ) / 2] = (heap[RC] < heap[LC]) ? RC : LC;
            } else {
                heap[(RC - 1) / 2] = (heap[heap[RC]] < heap[heap[LC]]) ? heap[RC] : heap[LC];
            }
            RC -= 2;
            LC -= 2;
        }
        
        arr[i] = heap[heap[0]];
        heap[heap[0]] = INF;
    }
}

int main(void){
    int arr[] = {8, 9, 1, 7, 3, 10, 5, 4, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    tournamentSort(arr, size);
    printer(arr, size);

    return 0;
}