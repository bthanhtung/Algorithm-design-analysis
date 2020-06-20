#include <stdio.h>

void InsertSort(int arr[], int n){
	int i, j, key;
	for(i = 0; i < n; i++){
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
	printf("Mang truoc khi sap xep:\n");
	PrintArray(arr, n);
	InsertSort(arr, n);
	printf("Mang sau khi sap xep: \n");
	PrintArray(arr, n);
	fclose(file);
	return 0;
}
