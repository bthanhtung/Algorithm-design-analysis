#include<stdio.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void SelectionSort(int arr[], int n){
    int i, j, minIndex;
    for(i = 0; i < n; i++){
        minIndex = i;
        //Find the min element in arr
        for(j = i+1; j < n; j++)
            if(arr[j] < arr[minIndex])
                minIndex = j;
             //swap two elements
            swap(&arr[minIndex], &arr[i]);
    }
}

void PrintArray(int arr[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int i, n, arr[100];
    FILE *file;
	file = fopen("dayso.inp", "r");
    fscanf(file,"%d",&n);
    for (int i = 0; i <= n-1; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    printf("Mang truoc khi sap xep:\n");
    PrintArray(arr, n);
    SelectionSort(arr, n);
    printf("Mang sau khi sap xep: \n");
    PrintArray(arr, n);
    fclose(file);
    return 0;
}
