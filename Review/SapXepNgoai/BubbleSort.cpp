#include <stdio.h>

void Swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(int arr[], int n){
   int i, j;
   for (i = 0; i < n-1; i++)
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              Swap(&arr[j], &arr[j+1]);
}

void PrintArray(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int i, n, arr[100];
	FILE *file;
	file = fopen("dayso.inp", "r");
	fscanf(file, "%d", &n);
	for(i = 0; i < n; i++){
		fscanf(file, "%d", &arr[i]);
	}
	printf("Mang truoc khi sap xep:\n");
	PrintArray(arr, n);
	BubbleSort(arr, n);
	printf("Mang sau khi sap xep:\n");
	PrintArray(arr, n);
	fclose(file);
	return 0;
}
