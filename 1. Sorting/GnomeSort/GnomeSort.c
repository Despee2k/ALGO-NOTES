#include "../../include/utils.h"

void gnomeSort(int arr[], int size){
    int i = 1;
    while(i < size){
        if(arr[i + 1] < arr[i]){
            swap(arr, i + 1, i);
            if(i > 0) i--;
        } else i++;
    }
}

int main(void){
    // int arr[10] = {8, 9, 1, 7, 3, 10, 5, 4, 2, 6};
    int arr[5] = {8, 9, 1, 7, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    gnomeSort(arr, size);
    printer(arr, size);

    return 0;
}