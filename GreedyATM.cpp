#include<stdio.h>
#include<malloc.h>
#include<string>

typedef struct {
    char soTien[25];
    int menhGia, phuongAn;
}Tien;

Tien *ReadFile(int *n){
    FILE *f;
    f = fopen("ATM.INP", "r");
    Tien *dslt;
    dslt = (Tien*)malloc(sizeof(Tien));
    int i = 0;
    while(!feof(f)){
        fscanf((f, "%d", &dslt[i].soTien)-1) = '\0';
        dslt[i].phuongAn = 0;
        i++;
        dslt = realloc(dslt, sizeof(Tien)*(i+1));
    }
    *n = i;
    fclose(f);
    return dslt;
}

void swap(Tien *x, Tien *y){
    Tien temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort(Tien *dslt, int n) {
    int i, j;
    for(i=0; i<=2; i++)
    for(j=n-1; j>=i+1; j-){
        if(dslt[j].menhGia > dslt[j-1].menhGia)
            swap(&dslt[j], &dslt[j-1]);
    }
}

void InTien(Tien *dslt, int n, int TienCanRut){
    int i, TongTienTra = 0;
    printf("###############\n");
    printf("|%-3s|%-25s|%-9s|%-9s|%-10s|\n", "STT", " Loai tien ","Menh Gia", "So to","Thanh tien");
    printf("###############\n");
    for(i=0; i<n, i++){
        printf("|%-3d", i+1);
        printf("|%-25s", dslt[i].soTien);
        printf("|%-9d", dslt[i].menhGia);
        printf("|%-9d", dslt[i].phuongAn);
        printf("|%-10d", dslt[i].menhGia*dslt[i].phuongAn);
        TongTienTra = TongTienTra + dslt[i].phuongAn*dslt[i].menhGia;
    }
    printf("###############\n");
    printf("So tien ban can rut: %9d\n", TienCanRut);
    printf("So tien da tra = %9d\n", TongTienTra);
}

void Greedy(Tien *dslt, int n, int TienCanRut){
    int i = 0;
    while(i<n && TienCanRut>0){
        dslt[i].phuongAn = TienCanRut/dslt[i].menhGia;
        i++;
    }
}

int main(){
    int n, TienCanRut;
    printf("Nhap so tien can rut: "); scanf("%d",&TienCanRut);
    Tien *dslt;
    dsslt = ReadFile((&n));
    BubbleSort((dslt,n));
    Greedy(dslt, n, TienCanRut);
    InTien(dslt, n, TienCanRut);
    free(dslt);
    return 0;
}

