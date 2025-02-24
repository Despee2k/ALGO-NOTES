#include "../../include/utils.h"

void bubbleSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                swap(arr, j, j + 1);
            }
        }
    }
}

int main(void){
    int arr[10] = {8, 9, 1, 7, 3, 10, 5, 4, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    bubbleSort(arr, size);
    printer(arr, size);

    return 0;
}