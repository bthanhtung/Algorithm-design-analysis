//Bai toan cai ba lo 1
// Moi do vat co so luong khong han che
// Giai bai toan bang QUY HOACH DONG

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct {
    char TenDV[20];
    int trongLuong, giaTri, phuongAn, soLuong;
}DoVat;

typedef int bang[50][100]; // Ba lo co trong luong toi da 99 va co toi da 50 do vat

DoVat *ReadFile(int *weight, int *n){
    FILE *f;
    f = fopen("quyhoachdong-balo2.INP", "r");
    fscanf(f, "%d", weight); // Xac dinh trong luong Ba lo
    DoVat *dsdv;
    dsdv = (DoVat*)malloc(sizeof(DoVat));
    int i = 0;
    while (!feof(f)){
        fscanf(f, "%d%d%d", &dsdv[i].trongLuong, &dsdv[i].giaTri, &dsdv[i].soLuong);
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

void inKetQua(DoVat *dsdv, int n){
    printf("\nTenDV(");
    for(int i = 0; i < n; i++){
        if(i != n-1){
            printf("%s,", dsdv[i].TenDV);
        } else {
            printf("%s", dsdv[i].TenDV);
        }
    }
    printf(") = PA(");
    for(int i = 0; i < n; i++){
            if(i != n-1){
               printf("%d,", dsdv[i].phuongAn);
            } else {
            printf("%d", dsdv[i].phuongAn);
            }
    }
  /*  printf(") = DG(");
    for(int i = 0; i<n; i++){
            if(i != n-1){
               printf("%.1f,", dsdv[i].giaTri/dsdv[i].trongLuong);
            } else {
            printf("%.1f", dsdv[i].giaTri/dsdv[i].trongLuong);
            }
    } */
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
void InDSDV(DoVat *dsdv ,int n, int weight){
    int i, tongTrongLuong = 0, tongGiaTri=0;
    printf("|---|--------------------|---------|---------|---------|\n");
    printf("|%-3s|%-20s|%-9s|%-9s|%-9s|\n", "STT", "     Ten Do Vat   ","T. Luong", "Gia Tri", "P. An");
    printf("|---|--------------------|---------|---------|---------|\n");
    for(i=0;i<n;i++){
        printf("|%-3d",i+1);
        printf("|%-20s",dsdv[i].TenDV);
        printf("|%-9d",dsdv[i].trongLuong);
        printf("|%-9d",dsdv[i].giaTri);
        printf("|%-9d|\n",dsdv[i].phuongAn);
        tongTrongLuong = tongTrongLuong + dsdv[i].phuongAn * dsdv[i].trongLuong;
        tongGiaTri = tongGiaTri + dsdv[i].phuongAn * dsdv[i].giaTri;
    }
    printf("|---|--------------------|---------|---------|---------|\n");
    inKetQua(dsdv, n);
    printf("\nTrong luong cua ba lo = %d\n",weight);
    printf("Tong trong luong = %d, Tong gia tri = %d\n", tongTrongLuong, tongGiaTri);
}
*/
int Min(int a, int b){
    return (a>b)? b:a;
}

void TaoBang(DoVat *dsdv, int n, int weight, bang F, bang X){
    int xk, yk, k;
    int FMax, XMax, V;

// Dien hàng dau tien cua hai bang

    for(V = 0; V <= weight; V++) {
        X[0][V] = Min(V/dsdv[0].trongLuong, dsdv[0].soLuong);
        F[0][V] = X[0][V] * dsdv[0].giaTri;
}

// Ðien các dòng còn lai

    for(k = 1; k < n; k++)
        for(V = 0; V <= weight; V++) {
            FMax = F[k-1][V] ;
            XMax = 0;
            yk = Min(V/dsdv[k].trongLuong, dsdv[k].soLuong);
            for(xk = 1; xk <= yk; xk++)
            if(F[k-1][V-xk*dsdv[k].trongLuong] + xk*dsdv[k].giaTri > FMax){
                FMax = F[k-1][V-xk*dsdv[k].trongLuong]+xk*dsdv[k].giaTri;
                XMax = xk;
            }
            F[k][V] = FMax;
            X[k][V] = XMax;
        }
}

void InBang(int n, int weight, bang F, bang X){
    int V, k;
    for(k = 0; k < n; k++){
    for(V = 0; V <= weight; V++)
        printf("%4d%2d",F[k][V], X[k][V]);
        printf("\n");
    }
}

void TraBang(DoVat *dsdv, int n, int weight, bang X) {
   int k, V;
   V = weight;
   for(k = n-1; k >= 0; k--) {
      dsdv[k].phuongAn = X[k][V];
      V = V - X[k][V] * dsdv[k].trongLuong;
   }
}


int main(){
    int n, weight;
    bang X,F;
    DoVat *dsdv;
    dsdv = ReadFile(&weight, &n);
    TaoBang(dsdv,n,weight,F,X);
    InBang(n,weight,F,X);
    TraBang(dsdv,n,weight,X);
    InDSDV(dsdv,n,weight);
    free(dsdv);
    return 0;
}

