#include <stdio.h>

typedef struct {
	char TenDV[20];
	float trongLuong, giaTri;
	int phuongAn, soLuong;
}DoVat;

DoVat *ReadFile(float *weight, int *n){
	File *file;
	file = fopen("thamAn-balo3.inp","r");
	fscanf(file, "%f", &weight);
	DoVat *dsdv;
	dsdv = (DoVat*)malloc(sizeof(DoVat));
	int i = 0;
	while(!feof(file)){
		fscanf(file, "%f%f%d", &dsdv[i].trongLuong, &dsdv[i].giaTri, &dsdv[i].soLuong);
		fgets(dsdv[i].TenDV, 20, file);
		dsdv[i].TenDV[strlen(dsdv[i].TenDV)-1] = '\0';
		dsdv[i].phuongAn = 0;
		i++;
		dsdv = (DoVat*)realloc(sizeof(DoVat));
	}
	*n = i;
	fclose(file);
	return dsdv;
}

void Swap(DoVat *x, DoVat *y){
	DoVat *temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void BubbleSort(DoVat *dsdv, int n){
	for(int i = 0; i < n-2; i++)
		for(int j = n-1; j >= i+1; j--){
			float DGJ = dsdv[j].giaTri/dsdv[j].trongLuong;
			float DGK = dsdv[j-1].giaTri/dsdv[j-1].trongLuong;
			if(DGJ > DGK)
				Swap(&dsdv[j], &dsdv[j-1]);
		}
}

void InKetQua(DoVat *dsdv, int n){
	printf("TenDV(");
	for(int i = 0; i < n; i++){
		if(i != n-1)
			printf("%s, ", dsdv[i].TenDV);
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

void InKetQua2(DoVat *dsdv, int n; float weight){
	int i = 0;
	float tongGiaTri = 0.0; tongTongLuong = 0.0;
	for(i = 0; i < n; i++){
		tongGiaTri = tongGiaTri + dsdv[i].phuongAn * dsdv[i].giaTri;
		tongtrongLuong =  tongtrongLuong + dsdv[i].phuongAn * dsdv[i].trongLuong;
	}
	InKetQua(dsdv, n);
	printf("Trong luong cai balo = %.1f", weight);
	printf("Tong trong luong = %.1f", tongtrongLuong);
	printf("Tong gia tri = %.1f", tongGiaTri);
}

void Greedy(DoVat *dsdv, int n, float weight){
	for(int i = 0; i < n; i++){
		dsdv[i].phuongAn = weight/dsdv[i].trongLuong;
		if(dsdv[i].phuongAn > 1)
			dsdv[i].phuongAn = 1;
		weight = weight - dsdv[i].phuongAn * dsdv[i].trongLuong;
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

