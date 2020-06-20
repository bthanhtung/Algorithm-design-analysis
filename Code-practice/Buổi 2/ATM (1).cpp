#include<stdio.h>
int main() {
	int n,i;
	FILE *file;
	int a[100];
	file = fopen("ATM.inp", "r");
    fscanf(file,"%d",&n);
    for (i = 0; i <= n-1; i++) {
        fscanf(file, "%d", &a[i]);
    }
	int sotien, to;
	printf("Nhap so tien can rut: ");
	scanf("%d",&sotien);
	for (int i=0;i<9;i++){
		to = sotien/a[i];
		if(to!=0){
			printf("%d to %d VND\n",to,a[i]);
		}
		sotien = sotien%a[i];
	}
	return 0;
}
