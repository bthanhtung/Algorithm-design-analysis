#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct {
    char TenDV[20];
    float trongLuong, giaTri;
    int phuongAn, soLuong;
}DoVat;

DoVat *ReadFromFile(float *weight, int *n){
    FILE *f;
    f = fopen("CaiBalo2.INP", "r");
    fscanf(f, "%f",weight);
    DoVat *dsdv;
    dsdv =(DoVat*)malloc(sizeof(DoVat));
    int i = 0;
    while (!feof(f)){
    fscanf(f, "%f%f%d",&dsdv[i].trongLuong,&dsdv[i].giaTri, &dsdv[i].soLuong);
    fgets(dsdv[i].TenDV,20,f);
    dsdv[i].TenDV[strlen(dsdv[i].TenDV)-1]='\0';
    dsdv[i].phuongAn = 0;
    i++;
    dsdv=(DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1));
}
    *n = i;
    fclose(f);
    return dsdv;
}

void swap(DoVat *x, DoVat *y){
    DoVat Temp;
    Temp = *x;
    *x = *y;
    *y = Temp;
}

void BubbleSort(DoVat *dsdv, int n){
    int i,j;
    for(i=0; i<=n-2; i++)
    for (j=n-1; j>=i+1; j--){
    float DGJ = dsdv[j].giaTri/dsdv[j].trongLuong;
    float DGJ_1 = dsdv[j-1].giaTri/dsdv[j-1].trongLuong;
    if (DGJ>DGJ_1)
    swap(&dsdv[j],&dsdv[j-1]);
 }
}
void InDSDV(DoVat *dsdv ,int n, float weight){
    int i;
    float TongTrongLuong = 0.0, TongGiaTri = 0.0;

    printf("|---|----------------------|-----------|-----------|-----------|-----------|\n");
    printf("|%-3s|%-22s|%-11s|%-11s|%-11s|%-11s|\n", "STT", " Ten Do Vat","Trong Luong", "Gia Tri", "Don Gia", "Phuong An");
    printf("|---|----------------------|-----------|-----------|-----------|-----------|\n");
    for(i=0;i<n;i++){
    printf("|%-3d", i+1);
    printf("|%-22s", dsdv[i].TenDV);
    printf("|%-11.1f", dsdv[i].trongLuong);
    printf("|%-11.1f", dsdv[i].giaTri);
    printf("|%-11.1f", dsdv[i].giaTri/dsdv[i].trongLuong);
    printf("|%-11d|\n", dsdv[i].phuongAn);

    TongTrongLuong = TongTrongLuong + dsdv[i].phuongAn * dsdv[i].trongLuong;
    TongGiaTri = TongGiaTri + dsdv[i].phuongAn * dsdv[i].giaTri;
}
    printf("|---|----------------------|-----------|-----------|-----------|-----------|\n");
    printf("\n");
    printf("Trong luong cua ba lo = %.1f\n", weight);
    printf("Tong trong luong = %.1f\n", TongTrongLuong);
    printf("Tong gia tri = %.1f\n", TongGiaTri);
}
void Greedy(DoVat *dsdv,int n, float weight){
    int i;
    for(i= 0; i<n; i++) {
    dsdv[i].phuongAn = (weight/dsdv[i].trongLuong);
    if(dsdv[i].phuongAn > dsdv[i].soLuong)
        dsdv[i].phuongAn = dsdv[i].soLuong;
    weight = weight-dsdv[i].phuongAn * dsdv[i].trongLuong;
 }
}
int main(){
    int n;
    float weight;
    DoVat *dsdv;
    dsdv = ReadFromFile(&weight, &n);
    BubbleSort(dsdv,n);
    Greedy(dsdv,n,weight);
    InDSDV(dsdv,n,weight);
    free(dsdv);
    return 0;
}
