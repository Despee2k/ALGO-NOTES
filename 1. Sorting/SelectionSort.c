#include <stdio.h>

#define MAX 10

void selectionSort(int arr[]){
    for(int i = MAX - 1; i > 0; i--){
        int biggestIndex = 0;
        for(int j = 1; j <= i; j++){
            if(arr[j] > arr[biggestIndex]){
                biggestIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[biggestIndex];
        arr[biggestIndex] = temp;
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
    selectionSort(arr);
    printer(arr);

    return 0;
}