#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void Heapify(int arr[], int n, int i){
    int largest = i; //
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < n && arr[left] > arr[largest]) // If left child is larger than root
        largest = left;
    if(right < n && arr[right] > arr[largest]) // If right child is larger than largest so far
        largest = right;
    if(largest != i){   // Uf largest is not root
        swap(&arr[i], &arr[largest]);
        Heapify(arr, n, largest); // Recursively heapify the affected sub-tree
    }
}

void HeapSort(int arr[], int n){
    for(int i = n/2 -1; i >= 0; i--) // Build a heap (rearrange array)
        Heapify(arr, n, i);
    for(int i = n-1; i >= 0; i--){ // One by one extract an element from heap
        swap(&arr[0], &arr[i]);  // Move current root to end
        Heapify(arr, i, 0); // Call max Heapify on the reduced heap
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
    printf("\nMang sau khi HeapSort: \n");
    PrintArray(arr, n);
    return 0;
}

