#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct {
	char Ten[20];
	float Trong_Luong, Gia_Tri, Don_Gia;
	int Phuong_An;
}Do_Vat;

Do_Vat * ReadFromFile(float *W, int *n){
	FILE *f;
	f=fopen("CaiBalo1.INP","r");
	fscanf(f,"%f",W);
	Do_Vat *dsdv;
	dsdv = (Do_Vat*) malloc (sizeof(Do_Vat));
	int i = 0;
	while (!feof(f)){
		fscanf(f,"%f%f",&dsdv[i].Trong_Luong,&dsdv[i].Gia_Tri);
		fgets(dsdv[i].Ten,21,f);
		dsdv[i].Ten[strlen(dsdv[i].Ten)-1]='\0';
		dsdv[i].Phuong_An=0;
		i++;
		dsdv = (Do_Vat*) realloc(dsdv, sizeof(Do_Vat)*(i+1));
		}
		*n=i;
		fclose(f);
		return dsdv;
    } 
	
void swap(Do_Vat *x, Do_Vat *y){
	Do_Vat temp;
	temp = *x;
	*x = *y;	
	*y = temp;
}


void Don_Gia(Do_Vat dsdv[],int n){
	for (int i=0;i<n;i++) 
		dsdv[i].Don_Gia = dsdv[i].Gia_Tri/dsdv[i].Trong_Luong;
}

void Sap_Xep(Do_Vat dsdv[],int n) {
	Don_Gia(dsdv,n);
    for (int i=0;i<=n-1;i++) {
	    for (int j = i+1;j<=n;j++){
		    if (dsdv[i].Don_Gia < dsdv[j].Don_Gia) 
			swap(&dsdv[i],&dsdv[j]);
		}
	}				
}



void In(Do_Vat *dsdv, int n, float W){
	int i;
	float TongTL=0.0, TongGT=0.0;
	printf("|---|---------------------|---------|---------|---------|---------|\n");
	printf("|%-3s|%-21s|%-9s|%-9s|%-9s|%-9s|\n","STT","Ten Do Vat","T.Luong","Gia Tri","Don Gia","Ph.An");
	printf("|---|---------------------|---------|---------|---------|---------|\n");
	for (i=0;i<n;i++){
		printf("|%-3d",i+1);
		printf("|%-21s",dsdv[i].Ten);
		printf("|%-9.1f",dsdv[i].Trong_Luong);
		printf("|%-9.1f",dsdv[i].Gia_Tri);
		printf("|%-9.1f",dsdv[i].Don_Gia);
		printf("|%-9d|\n",dsdv[i].Phuong_An);
		TongTL = TongTL + dsdv[i].Phuong_An * dsdv[i].Trong_Luong;
		TongGT = TongGT + dsdv[i].Phuong_An * dsdv[i].Gia_Tri;
	}
	printf("|---|---------------------|---------|---------|---------|---------|\n");
	printf("Trong luong con lai cua cai ba lo la: %9.1f\n",W);
	printf("Tong trong luong = %9.1f\n",TongTL);
	printf("Tong gia tri = %9.1f\n",TongGT);
}

void Greedy(Do_Vat *dsdv, int n, float W) {
	for (int i=0;i<n;i++) {
		dsdv[i].Phuong_An = (int)(W/dsdv[i].Trong_Luong);
		W = W - dsdv[i].Phuong_An * dsdv[i].Trong_Luong;
	}
}

int main() {
	int i,j,n;
	float W;
	Do_Vat *dsdv;
	dsdv = ReadFromFile(&W, &n);
	Sap_Xep(dsdv,n);
	Greedy(dsdv,n,W);
	In(dsdv,n,W);
	free(dsdv);
	return 0;
}
