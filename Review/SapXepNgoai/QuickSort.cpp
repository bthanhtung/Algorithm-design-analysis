#include <stdio.h>

void Swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int arr[], int low, int hight){
	int pivot = arr[hight];
	int i = (low-1);
	for(int j = low; j <= hight-1; j++){
		if(arr[j] <= pivot){
			i++;
			Swap(&arr[i], &arr[j]);
		}
	}
	Swap(&arr[i+1], &arr[hight]);
	return (i+1);
}

void QuickSort(int arr[], int low, int hight){
	if(low < hight){
		int pi = Partition(arr, low, hight);
		QuickSort(arr, low, pi-1);
		QuickSort(arr, pi+1, hight);
	}
}

void PrintArray(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int n, i, arr[100];
	FILE *file;
	file = fopen("dayso.inp", "r");
	fscanf(file, "%d", &n);
	for(i = 0; i < n; i++){
		fscanf(file, "%d", &arr[i]);
	}
	printf("Mang ban dau:\n");
	PrintArray(arr, n);
	QuickSort(arr, 0, n-1);
	printf("Mang sau khi QuickSort:\n");
	PrintArray(arr, n);
	fclose(file);
	return 0;
}
