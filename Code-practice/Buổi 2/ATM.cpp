#include<stdio.h>
int main() {
	int menhgia[9] = {500000,200000,100000,50000,20000,10000,5000,2000,1000};
	int sotien, to;
	printf("Nhap so tien can rut: ");
	scanf("%d",&sotien);
	for (int i=0;i<9;i++){
		to = sotien/menhgia[i];
		if(to!=0){
			printf("%d to %d VND\n",to,menhgia[i]);
		}
		sotien = sotien%menhgia[i];
	}
	return 0;
}
