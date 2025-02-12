#include <stdio.h>

#define MAX 10

void shellSort(int arr[]){
    int gap;
    int i, j;
    
    for(gap = MAX/2; gap > 0; gap /= 2){
        for(i = gap; i < MAX; i++){
            int temp = arr[i];
            for(j = i; j >= gap && arr[j] < arr[j - gap]; j -= gap){
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void printer(int arr[]){
    printf("Array: ");
    for(int i = 0; i < MAX; i++){
        printf("[%d]", arr[i]);
    }
    printf("\n");
}

int main(void){
    int arr[MAX] = {8, 9, 1, 7, 3, 10, 5, 4, 2, 6};
    shellSort(arr);
    printer(arr);

    return 0;
}