#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX 100

typedef struct{
	char TenDV[20];
	float giaTri, trongLuong;
	int phuongAn, soLuong
}DoVat;

DoVat *dsdv;
int n;
int x[MAX];
float weight, canTren, tongGiaTri, giaTriLonNhatTamThoi, trongLuongConLai;

DoVat *ReadFile(float *weight, int *n){
	FILE *file;
	file = fopen("nhanhCan-balo3.inp",  "r");
	fscanf(file, "%f", weight);
	DoVat *dsdv;
	dsdv = (DoVat*)malloc(sizeof(DoVat));
	int i = 0;
	while(!feof(file)){
		fscanf(file, "%f%f%d", &dsdv[i].trongLuong, &dsdv[i].giaTri, &dsdv[i].soLuong);
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

void Swap(DoVat *a, DoVat *b){
	DoVat temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void BubbleSort(DoVat *dsdv, int n){
	for(int i = 0; i <= n-2; i++)
		for(int j = n-1; j >= i+1; j--){
			float DGJ = dsdv[j].giaTri/dsdv[i].trongLuong;
			float DGJ1 = dsdv[j-1].giaTri/dsdv[j-1].trongLuong;
			if(DGJ > DGJ1)
				Swap(&dsdv[j], dsdv[j-1]);
		}
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
			printf("%d, ", dsdv[i].phuongAn);
		else printf("%d", dsdv[i].phuongAn);
	}
	printf(") = DG(");
	for(int i = 0; i < n; i++){
		if(i != n-1)
			printf("%.1f, ", dsdv[i].giaTri/dsdv[i].trongLuong);
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
	printf("\nTrong luong cai balo = %.1f", weight);
	printf("\nTong gia tri = %.1f", tongGiaTri);
	printf("nTong trong luong = %.1f", tongTrongLuong);
}

void RootValue(){
	trongLuongConLai = weight;
	canTren = trongLuongConLai * dsdv[0].giaTri/dsdv[0].trongLuong;
	giaTriLonNhatTamThoi = 0.0;
	tongGiaTri = 0.0;
}

void SaveMaxValue(){
	if(giaTriLonNhatTamThoi < tongGiaTri){
		giaTriLonNhatTamThoi = tongGiaTri;
		for(int i = 0; i < n; i++){
			dsdv[i].phuongAn = x[i];
		}
	}
}

void DoAgain(int i){
	int temp = trongLuongConLao/dsdv[i].trongLuong;
	for(int j = temp; j >= 0; j--){
		if(j > 1)
			j = 1;
		tongGiaTri tongGiaTri + j*dsdv[i].giaTri;
		trongLuongConLai = trongLuongConLai - j*dsdv[i].trongLuong;
		canTren = tongGiaTri + trongLuongConLai*dsdv[i+1].giaTri/dsdv[i+1].trongLuong;
		if(canTren > giaTriLonNhatTamThoi){
			x[i] = j;
			if((i == n-1) || (trongLuongConLai == 0))
				SaveMaxValue();
			else DoAgain(i+1);
		}
		x[i] = 0;
		tongGiaTri = tongGiaTri - j*dsdv[i].giaTri;
		trongLuongConLai = trongLuongConLai + j*dsdv[i].trongLuong;
	}
}

int main(){
	dsdv = ReadFile(&weight, &n);
	BubbleSort(dsdv, n);
	RootValue();
	SaveMaxValue();
	DoAgain(0);
	InDSDV(dsdv, n, weight);
	free(dsdv);
	return 0;
}