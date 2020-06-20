#include<stdio.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition(int arr[], int low, int hight){
    int pivot = arr[hight];
    int i = (low-1);
    for(int j = low; j <= hight-1; j++){
        // If current element is smaller than or equal to pivot
        if(arr[j] <= pivot){
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[hight]);
    return (i+1);
}

void QuickSort(int arr[], int low, int hight){
    if(low < hight){
        //pi is partitioning index, arr[p] is now right place
        int pi = partition(arr, low, hight);
        // Separately sort elements before
        // partition and after partition
        QuickSort(arr, low, pi-1);
        QuickSort(arr, pi+1, hight);
    }
}

void PrintArray(int arr[], int n){
    int i;
    for(i = 0; i < n-1; i++){
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
    QuickSort(arr, 0, n-1);
    printf("Mang sau khi QuickSort: \n");
    PrintArray(arr, n);
    return 0;
}
