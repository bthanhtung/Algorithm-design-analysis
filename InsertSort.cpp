#include <math.h>
#include <stdio.h>


void InsertionSort(int arr[], int n){
    int i, j, key;
    for(i = 1; i < n; i++){
        key = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void PrintArray(int arr[], int n){
    int i;
    for(i = 0; i < n-1; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int i, n;
    FILE *file;
	file = fopen("dayso.INP", "r");
    fscanf(file, "%d", &n);
    int arr[n];
    for (int i = 0; i <= n-1; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    printf("Mang truoc khi sap xep:\n");
    PrintArray(arr, n);
  //  int a = sizeof(arr)/sizeof(arr[0]); // =arr.length
    InsertionSort(arr, n);
    printf("Mang sau khi InsertSort:\n");
    PrintArray(arr, n);
    fclose(file);
    return 0;
}
