#include "../../include/utils.h"
#include <stdbool.h>

void combSort(int arr[], int size){
    int gap = size;
    double shrink = 1.3;
    bool swapped = true;
    
    while(gap > 1 || swapped){
        gap = (int)(gap / shrink);
        if(gap < 1) gap = 1;
        swapped = false;
        for(int i = 0; i < size - gap; i++){
            if(arr[i] > arr[i + gap]){
                swap(arr, i, i + gap);
                swapped = true;
            }
        }
    }
}

int main(void){
    int arr[10] = {8, 9, 1, 7, 3, 10, 5, 4, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    combSort(arr, size);
    printer(arr, size);

    return 0;
}