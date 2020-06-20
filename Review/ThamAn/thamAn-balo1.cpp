#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
	char TenDV[20];
	float trongLuong, giaTri;
	int phuongAn;
}DoVat;

DoVat *ReadFile(float *weight, int *n){
	FILE *file;
	file = fopen("thamAn-balo1.inp", "r");
	fscanf(file, "%f", weight);
	DoVat *dsdv;
	dsdv = (DoVat*)malloc(sizeof(DoVat));
	int i = 0;
	while(!feof(file)){
		fscanf(file, "%f%f", &dsdv[i].trongLuong, &dsdv[i].giaTri);
		fgets(dsdv[i].TenDV, 20, file);
		dsdv[i].TenDV[strlen(dsdv[i].TenDV)-1] = '\0';
		dsdv[i].phuongAn = 0;
		i++;
		dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat));
	}
	*n = i;
	fclose(file);
	return dsdv;
}

void Swap(DoVat *x, DoVat *y){
	DoVat temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void BubbleSort(DoVat *dsdv, int n){
	int i, j;
	for(i = 0; i <= n-2; i++)
		for(j = n-1; j >= i+1; j--){
			float DGJ = dsdv[j].giaTri/dsdv[j].trongLuong;
			float DGJ1 = dsdv[j-1].giaTri/dsdv[j-1].trongLuong;
			if(DGJ > DGJ1)
				Swap(&dsdv[j], &dsdv[j-1]);
		}
}

void InKetQua(DoVat *dsdv, int n){
	printf("TenDV(");;
	for(int i = 0; i < n; i++){
		if(i != n-1)
			printf("%s,", dsdv[i].TenDV);
		printf("%s", dsdv[i].TenDV);
	}
	printf(") = PA(");
	for(int i = 0; i < n; i++){
		if(i != n-1)
			printf("%d, ", dsdv[i].phuongAn);
		printf("%d", dsdv[i].phuongAn);
	}
	printf(")");
}

void InKetQua2(DoVat * dsdv, int n, int weight){
	int i;
	float tongTrongLuong = 0.0, tongGiaTri = 0.0;
	for(int i = 0; i < n; i++){
		tongTrongLuong = tongTrongLuong + dsdv[i].phuongAn * dsdv[i].trongLuong;
		tongGiaTri = tongGiaTri + dsdv[i].phuongAn * dsdv[i].giaTri;
	}
	InKetQua(dsdv, n);
	printf("\nTrong luong cua cai balo = %.1f\n", weight);;
	printf("Tong trong luong = %.1f\n", tongTrongLuong);;
	printf("Tong gia tri = %.1f", tongGiaTri);
}

void Greedy(DoVat *dsdv, int n, float weight){
	int i = 0;
	for(i = 0; i < n; i++){
		dsdv[i].phuongAn = (weight/dsdv[i].trongLuong);
		weight = weight-dsdv[i].phuongAn * dsdv[i].trongLuong;
	}
}

int main(){
	int n;
	float weight;
	DoVat *dsdv;
	dsdv = ReadFile(&weight, &n);
	BubbleSort(dsdv, n);
	Greedy(dsdv, n, weight);
	InKetQua2(dsdv, n, weight);
	free(dsdv);
	return 0;
}
