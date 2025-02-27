#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include "../../include/utils.h"

#define INF INT_MAX

int *createHeap(int size, int *heapSize) {
    if (size > ((*heapSize) * 2 + 1)) {
        *heapSize = (*heapSize) * 2 + 1;
    }

    int *heap = malloc(sizeof(int) * (*heapSize));
    int i = 0;
    while (i < (*heapSize + 1) / 2) {
        heap[((*heapSize) / 2) + i] = i;
        i++;
    }
    return heap;
}

int backtrack(int *heap, int heapSize) {
    int val = 0;
    while (val < (heapSize - 1) / 2) {
        val = (heap[2 * val + 1] == heap[0]) ? 2 * val + 1 : 2 * val + 2;
    }
    return val;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int *mergeArrays(int arr[], int output[], int size) {
    int *merged = malloc(sizeof(int) * size);
    int index = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] != INF) {
            merged[index++] = arr[i];
        }
    }
    for (int i = 0; i < size; i++) {
        if (output[i] != INF) {
            merged[index++] = output[i];
        }
    }
    qsort(merged, index, sizeof(int), compare);

    return merged;
}

void tournamentSort(int arr[], int size) {
    int heapSize = 7;
    int *heap = createHeap(size, &heapSize);
    int *output = malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++) {
        output[i] = INF;
    }

    int j = 0;
    for (int i = (heapSize + 1) / 2; i < size; i++, j++) {
        int right = heapSize - 1;
        int left = right - 1;

        while (left > 0) {
            if (heap[right] == INF || heap[left] == INF) {
                if (heap[right] == INF) {
                    heap[(left - 1) / 2] = heap[left];
                } else {
                    heap[(right - 1) / 2] = heap[right];
                }
            } else {
                if (arr[heap[right]] < arr[heap[left]]) {
                    heap[(right - 1) / 2] = heap[right];
                } else {
                    heap[(left - 1) / 2] = heap[left];
                }
            }
            right -= 2;
            left -= 2;
        }

        output[j] = arr[heap[0]];
        int index = backtrack(heap, heapSize);
        heap[index] = i;
        arr[heap[0]] = INF;

        if (arr[i] < output[j]) {
            heap[index] = INF;
        }
    }

    output = mergeArrays(arr, output, size);
    
    memcpy(arr, output, sizeof(int) * size);
}

int main(void) {
    int arr[10] = {8, 9, 1, 7, 3, 10, 5, 4, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    tournamentSort(arr, size);
    printer(arr, size);

    return 0;
}