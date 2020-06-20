#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
	char TenDV[20];
	int giaTri, trongLuong, phuongAn, soLuong;
}DoVat;

typedef int bang[50][100];

DoVat *ReadFile(float *weight, int *n){
	FILE *file;
	file = fopen("quyHoachDong-balo2.inp", "r");
	fscanf(file, "%f", weight);
	DoVat *dsdv;
	dsdv = (DoVat*)malloc(size(DoVat));
	int i = 0;
	while(!feof(file)){
		fscanf(file, "%d%d%d", &dsdv[i].trongLuong, &dsdv[i].giaTri, &dsdv[i].soLuong);
		fgets(dsdv[i].TenDV, 20, file);
		dsdv[i].TenDV[strlen(dsdv[i].TenDV)-1] = '\0';
		dsdv[i].phuongAn = 0;
		i++;
		dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1));
	}
	*n = i;
	fclose(file);
	return dsdv;
}

void InKetQua(DoVat *dsdv, int n){
	printf("TenDV(");
	for(int i = 0; i < n; i++){
		if(i != n-1)
			printf("%s,", dsdv[i].TenDV);
		else printf("%s", dsdv[i].TenDV);
	}
	printf(") = PA(");
	for(int i = 0; i < n; i++){
		if(i != n-1)
			printf("%d,", dsdv[i].phuongAn);
		else printf("%d", dsdv[i].phuongAn);
	}
	printf(") = (");
	for(int i = 0; i < n; i++){
		if(i != n-1)
			printf("%.1f,", dsdv[i].giaTri/dsdv[i].trongLuong);
		else printf("%.1f", dsdv[i].giaTri/dsdv[i].trongLuong);
	}
}

void InDSDV(DoVat *dsdv, int n, int weight){
	float tongGiaTri = 0.0; tongTrongLuong = 0.0;
	for(int i = 0; i < n; i++){
		tongTrongLuong = tongTrongLuong + dsdv[i].phuongAn * dsdv[i].trongLuong;
		tongGiaTri = tongGiaTri + dsdv[i].phuongAn * dsdv[i].giaTri;
	}
	InKetQua(dsdv, n);
	printf("\nTrong luong balo = %.d", weight);
	printf("\nTong trong luong balo = %.1f". tongTrongLuong);
	printf("\nTong gia tri = %.1f", tongGiaTri);
}

int Min(int a, int b){
	return (a < b) ? a:b;
}

void TaoBang(DoVat *dsdv, int n, int weight, bang F, bang X){
	int xk, yk, k;
	int FMax, XMax, V;
	for(V = 0; V <= weight; V++){
		X[0][V] = Min(V/dsdv[0].trongLuong, dsdv[0].soLuong);
		F[0][V] = X[0][V] * dsdv[0].giaTri;
	}
	for(k = 0; k < n; k++)
		for(V = 0; V <= weight;  V++){
			FMax = F[k-1][V];
			XMax = 0;
			yk = Min(V/dsdv[k].trongLuong, dsdv[k].soLuong);
			for(xk = 1; xk <= yk; xk++)
				if(F[k-1][V-xk*dsdv[k].trongLuong] + xk*dsdv[k].giaTri > FMax){
					F[k-1][V-xk*dsdv[k].trongLuong + xk*dsdv[k].giaTri];
					XMax = xk;
				}
			F[k][V] = FMax;
			X[k][V] = XMax;
		}
}

void InBang(int n, int weight, bang F, bang X){
	int V, k;
	for(k = 0; k < n; k++)
		for(V = 0; V <= weight; V++){
			printf("%4d%2d", F[k][V], X[k][V]);
			printf("\n");
		}
}

void TraBang(DoVat *dsdv, int n, int weight, bang X){
	int k, V;
	V = weight;
	for(k = n-1; k >= 0; k--){
		dsdv[k].phuongAn = X[k][V];
		V = V - X[k][V]*dsdv[k].soLuong;
	}
}

int main(){
	int n, weight;
	bang F, X;
	DoVat *dsdv;
	dsdv = ReadFile(&weight, &n);
	TaoBang(dsdv, n, weight, F, X);
	InBang(n, weight, F, X);
	TraBang(dsdv, n, weight, X);
	InDSDV(dsdv, n, weight);
	free(dsdv);
	return 0;
}