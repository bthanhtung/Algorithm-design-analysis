#include<stdio.h>
typedef int keytype;
typedef float othertype;
typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;
void swap(recordtype&x, recordtype &y) {
	recordtype temp;
	temp = x; 
	x = y;
	y = temp;
}

