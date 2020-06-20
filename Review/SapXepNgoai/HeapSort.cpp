#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Heapify(int arr[], int n, int i){
    int largest = i; //
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && arr[left] > arr[largest])
        largest = left;
    if(right < n && arr[right] > arr[largest])
        largest = right;
    if(largest != i){
        swap(&arr[i], &arr[largest]);
        Heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n){
    for(int i = n/2 -1; i >= 0; i--)
        Heapify(arr, n, i);
    for(int i = n-1; i >= 0; i--){
        swap(&arr[0], &arr[i]);
        Heapify(arr, i, 0);
    }
}

void PrintArray(int* arr, int size){
    int i;
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}


int main(){
    int i, n, arr[100];
    FILE *file;
	file = fopen("dayso.inp", "r");
    fscanf(file,"%d",&n);
    for (int i = 0; i <= n-1; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    printf("Mang truoc khi sap xep:\n");
    PrintArray(arr, n);
    HeapSort(arr, n);
    printf("Mang sau khi HeapSort: \n");
    PrintArray(arr, n);
    return 0;
}

