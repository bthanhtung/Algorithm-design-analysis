#include <math.h>
#include <stdio.h>


void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void BubbleSort(int arr[], int n){
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

void PrintArray(int arr[], int n){
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main(){
    int i, n, arr[100];
    FILE *file;
	  file = fopen("dayso.inp", "r");
    fscanf(file, "%d", &n);
    for (int i = 0; i <= n-1; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    printf("Mang truoc khi sap xep:\n");
    PrintArray(arr, n);
    // n = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr, n);
    printf("Mang sau khi InsertSort:\n");
    PrintArray(arr, n);
    fclose(file);
    return 0;
}
