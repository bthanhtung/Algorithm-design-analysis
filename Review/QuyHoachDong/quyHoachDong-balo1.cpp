#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct{
	char TenDV[20];
	int giaTri, trongLuong, phuongAn;
}DoVat;

typedef int bang[50][100];

DoVat *ReadFile(int *weight, int *n){
	FILE *file;
	file = fopen("quyHoachDong-balo1.inp", "r");
	fscanf(file, "%d", weight);
	DoVat *dsdv;
	dsdv = (DoVat*)malloc(sizeof(DoVat));
	int i = 0;
	while(!feof(file)){
		fscanf(file, "%d%d", &dsdv[i].trongLuong, &dsdv[i].giaTri);
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
	printf(") = DG(");
	for(int i = 0; i < n; i++){
		if(i != n-1)
			printf("%.1f,", dsdv[i].giaTri/dsdv[i].trongLuong);
		else printf("%.1f", dsdv[i].giaTri/dsdv[i].trongLuong);
	}
	printf(")");
}

void InDSDV(DoVat *dsdv, int n, float weight){
	float tongGiaTri = 0.0, tongTrongLuong = 0.0;
	for(int i = 0; i < n; i++){
		tongGiaTri = tongGiaTri + dsdv[i].phuongAn * dsdv[i].giaTri;
		tongTrongLuong = tongTrongLuong + dsdv[i].phuongAn * dsdv[i].trongLuong;
	}
	InKetQua(dsdv, n);
	printf("\nTrong luong cua balo = %.1f", weight);
	printf("\nTong gia tri = %.1f", tongGiaTri);
	printf("\nTong trong luong = %.1f", tongTrongLuong);
}

void TaoBang(DoVat *dsdv, int n, float weight, bang F, bang X){
	int xk, yk, k;
	int FMax, XMax, V;
	for(V = 0; V <= weight; V++){
		X[0][V] = V/dsdv[0].trongLuong;
		F[0][V] = X[0][V] * dsdv[0].giaTri;
	}
	for(k = 1; k < n; k++){
		for(V = 0; V <= weight; V++){
			FMax = F[k-1][V];
			XMax = 0;
			yk = V/dsdv[k].trongLuong;
			for(xk = 1; xk <= yk; xk++)
				if(F[k-1][V-xk*dsdv[k].trongLuong] + xk*dsdv[k].giaTri > FMax){
					FMax = F[k-1][V-xk*dsdv[k].trongLuong] + xk*dsdv[k].giaTri;
					XMax = xk;
				}
			F[k][V] = FMax;
			X[k][V] = XMax;
		}
	}
}

void InBang(int n, int weight, bang F, bang X){
	int V, k;
	for(k = 0; k < n; k++){
		for(V = 0; V <= weight; V++){
			printf("%4d%2d", F[k][V], X[k][V]);
			printf("\n");
		}
	}
}

void TraBang(DoVat *dsdv, int n, int weight, bang X){
	int k, V;
	V = weight;
	for(k = 0; k < n; k++){
		dsdv[k].phuongAn = X[k][V];
		V = V - X[k][V]*dsdv[k].trongLuong;
	}
}

int main(){
	int n, weight;
	bang X, F;
	DoVat *dsdv;
	dsdv = ReadFile(&weight, &n);
	TaoBang(dsdv, n, weight, F, X);
	InBang(n, weight, F, X);
	TraBang(dsdv, n,  weight, X);
	InDSDV(dsdv, n, weight);
	free(dsdv);
	return 0;
}
