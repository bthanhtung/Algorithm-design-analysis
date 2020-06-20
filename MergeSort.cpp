#include<stdlib.h>
#include<stdio.h>

// Merges two sub-arrays of arr[].
// First sub-array is arr[l..m]
// Second sub-array is arr[m+1..r]
void merge(int arr[], int leftIndex, int midIndex, int rightIndex)
{
    int i, j, k;
    int n1 = midIndex - leftIndex + 1;
    int n2 =  rightIndex - midIndex;

    // create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[leftIndex+i];
    for (j = 0; j < n2; j++)
        R[j] = arr[midIndex+1+j];

    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first sub-array
    j = 0; // Initial index of second sub-array
    k = leftIndex; // Initial index of merged sub-array
    while (i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void MergeSort(int arr[], int leftIndex, int rightIndex){
    if (leftIndex < rightIndex){
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int midIndex = leftIndex+(rightIndex-leftIndex)/2;

        // Sort first and second halves
        MergeSort(arr, leftIndex, midIndex);
        MergeSort(arr, midIndex+1, rightIndex);
        merge(arr, leftIndex, midIndex, rightIndex);
    }
}

void printArray(int arr[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main(){
    int i, n, arr[100];
    FILE *file;
	file = fopen("dayso.inp", "r");
    fscanf(file,"%d",&n);
    for (int i = 0; i <= n-1; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    printf("Mang truoc khi sap xep:\n");
    printArray(arr, n);
    MergeSort(arr, 0, n - 1);
    printf("\nMang sau khi duoc MergeSort: \n");
    printArray(arr, n);
    return 0;
}
