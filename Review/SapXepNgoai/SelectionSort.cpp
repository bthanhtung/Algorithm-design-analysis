#include <stdio.h>

void Swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void PrintArray(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void SelectionSort(int arr[], int n){
	int i, j, minIndex;
	for(i = 0; i < n; i++){
		minIndex = i;
		for(j = i+1; j < n; j++)
			if(arr[j] < arr[minIndex])
				minIndex = j;
			Swap(&arr[minIndex], &arr[i]);

	}
}

int main(){
	int i, n, arr[100];
	FILE  *file;
	file = fopen("dayso.inp", "r");
	fscanf(file, "%d", &n);
	for(i = 0; i < n; i++){
		fscanf(file, "%d", &arr[i]);
	}
	printf("Mang ban dau:\n");
	PrintArray(arr, n);
	SelectionSort(arr, n);
	printf("Mang sau khi sap xep:\n");
	PrintArray(arr, n);
	fclose(file);
	return 0;
}

