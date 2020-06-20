#include<stdio.h>>
#include<malloc.h>>
#include<string.h>

#define MAX 100

typedef struct {
    char TenDV[20];
    float trongLuong, giaTri;
    int phuongAn, soLuong;
} DoVat;

DoVat *dsdv;
int n;
int x[MAX];
float weight, canTren, tongGiaTri, giaTriLonNhatTamThoi, trongLuongConLai;

DoVat *ReadFile(float *weight, int *n){
    FILE *f;
    f = fopen("CaiBalo3.inp", "r");
    fscanf(f,"%f", weight);
    DoVat *dsdv;
    dsdv = (DoVat*)malloc(sizeof(DoVat));
    int i = 0;
    while(!feof(f)){
        fscanf(f, "%f%f%d", &dsdv[i].trongLuong, &dsdv[i].giaTri, &dsdv[i].soLuong);
        fgets(dsdv[i].TenDV, 20, f);
        dsdv[i].TenDV[strlen(dsdv[i].TenDV)-1] = '\0';
        dsdv[i].phuongAn = 0;
        i++;
        dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat)*(i+1));
    }
    *n = i;
    fclose(f);
    return dsdv;
}

void swap(DoVat *a, DoVat *b){
    DoVat c;
     c = *a;
    *a = *b;
    *b = c;
}

void BubbleSort(DoVat *dsdv, int n){
    int i, j;
    for(i = 0; i <= n-2; i++)
    for(j = n-1; j >= i+1; j--){
        float donGiaJ = dsdv[j].giaTri/dsdv[j].trongLuong;
        float donGiaJ_1 = dsdv[j-1].giaTri/dsdv[j-1].trongLuong;
        if(donGiaJ > donGiaJ_1)
            swap(&dsdv[j],  &dsdv[j-1]);
    }
}

void inKetQua(DoVat *dsdv, int n){
    printf("TenDV(");
    for(int i=0; i<n; i++){
        if(i != n-1){
            printf("%s,", dsdv[i].TenDV);
        } else {
            printf("%s", dsdv[i].TenDV);
        }
    }
    printf(") = PA(");
    for(int i = 0; i<n; i++){
            if(i != n-1){
               printf("%d,", dsdv[i].phuongAn);
            } else {
            printf("%d", dsdv[i].phuongAn);
            }
    }
    printf(") = DG(");
    for(int i = 0; i<n; i++){
            if(i != n-1){
               printf("%.1f,", dsdv[i].giaTri/dsdv[i].trongLuong);
            } else {
            printf("%.1f", dsdv[i].giaTri/dsdv[i].trongLuong);
            }
    }
    printf(")");
}

void InDSDV(DoVat *dsdv , int n, float weight){
    int i;
    float tongGiaTri = 0, tongTrongLuong = 0;
    for(i = 0; i < n; i++){
        tongTrongLuong = tongTrongLuong + dsdv[i].phuongAn * dsdv[i].trongLuong;
        tongGiaTri = tongGiaTri + dsdv[i].phuongAn * dsdv[i].giaTri;
    }
    inKetQua(dsdv, n);
    printf("\nTrong luong cua ba lo = %.1f\n", weight);
    printf("Tong trong luong = %.1f\n", tongTrongLuong);
    printf("Tong gia tri: %.1f\n", tongGiaTri);
}

/*
void InDSDV(DoVat *dsdv , int n, float weight){
    int i;
    float tongGiaTri = 0, tongTrongLuong = 0;
    printf("|---|--------------------|---------|---------|---------|---------|\n");
    printf("|%-3s|%-20s|%-9s|%-9s|%-9s|%-9s|\n", "STT", " Ten Do Vat","T.Luong", "Gia Tri", "Don Gia", "P. An");
    printf("|---|--------------------|---------|---------|---------|---------|\n");
    for(i = 0; i < n; i++){
        printf("|%-3d",i+1);
        printf("|%-20s",dsdv[i].TenDV);
        printf("|%-9.1f",dsdv[i].trongLuong);
        printf("|%-9.1f",dsdv[i].giaTri);
        printf("|%-9.1f",dsdv[i].giaTri/dsdv[i].trongLuong);
        printf("|%-9d|\n",dsdv[i].phuongAn);

        tongTrongLuong = tongTrongLuong + dsdv[i].phuongAn * dsdv[i].trongLuong;
        tongGiaTri = tongGiaTri + dsdv[i].phuongAn * dsdv[i].giaTri;
}
    printf("|---|--------------------|---------|---------|---------|---------|\n");
    inKetQua(dsdv, n);
    printf("\nTrong luong cua ba lo = %9.1f\n", weight);
    printf("Tong trong luong = %9.1f\n", tongTrongLuong);
    printf("Tong gia tri: %.1f\n", tongGiaTri);
}   */

void rootValue(){
    trongLuongConLai = weight;
    canTren = trongLuongConLai*dsdv[0].giaTri/dsdv[0].trongLuong;
    giaTriLonNhatTamThoi = 0.0;
    tongGiaTri = 0.0;
}

void saveMaxValue(){
    int i;
    if(giaTriLonNhatTamThoi < tongGiaTri){
        giaTriLonNhatTamThoi = tongGiaTri;
        for(i = 0; i < n; i++){
            dsdv[i].phuongAn = x[i];
        }
    }
}

void doAgain(int i){
    int j;
    int temp = trongLuongConLai/dsdv[i].trongLuong;
    for(j = temp; j >= 0; j--){
            if( j > 1){
                j = 1;
            }
        tongGiaTri = tongGiaTri + j*dsdv[i].giaTri;
        trongLuongConLai  = trongLuongConLai - j*dsdv[i].trongLuong;
        canTren = tongGiaTri + trongLuongConLai*dsdv[i+1].giaTri/dsdv[i+1].trongLuong;
        if(canTren > giaTriLonNhatTamThoi){
            x[i] = j;
            if((i == n-1) || (trongLuongConLai == 0))
                saveMaxValue();
            else
                doAgain((i+1));
        }
        x[i] = 0;
        tongGiaTri = tongGiaTri - j*dsdv[i].giaTri;
        trongLuongConLai = trongLuongConLai + j*dsdv[i].trongLuong;
    }
}

int main(){
    dsdv = ReadFile(&weight, &n);
    BubbleSort(dsdv,n);
    rootValue();
    saveMaxValue();
    doAgain(0);
    InDSDV(dsdv, n, weight);
    free(dsdv);
    return 0;
}




