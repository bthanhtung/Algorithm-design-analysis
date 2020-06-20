#include <C:\Users\student\Desktop\khaibao.cpp>
#include <stdio.h>
int i,j;

//SELECTION SORT
void SelectionSort(recordtype a[],int n){
int lowindex;
keytype lowkey;
for (i=0;i<=n-2;i++){
	lowkey = a[i].key;
	lowindex = i;
	for (j=i+1;j<=n-1;j++)
		if(a[j].key<lowkey){
			lowkey = a[j].key;
			lowindex = j;
		}
		swap(a[i],a[lowindex]);	
}
}

//INSERTION SORT 
void InsertionSort(recordtype a[],int n) {
	for(i=1;i<=n-1;i++){
		j=i;
		while ((j>0) && (a[j].key<a[j-1].key)) {
			swap(a[j],a[j-1]);
			j--;
		}
	}
}

//BUBBLE SORT
void BubbleSort(recordtype a[],int n) {
	for(i=0;i<=n-2;i++)
	     for(j=n-1;j<=n-1;j++)
	          if(a[j].key < a[i].key)
	               swap(a[j],a[i]);
}

//Find Pivot
int FindPivot(recordtype a[], int i, int j){
	keytype firstkey;
	int k;
	k = i+1;
	while (k<=j && a[k].key == a[i].key) k++;
	if (k>j) return -1;
	if (a[k].key>a[i].key) return k;
	return i;
}

//Partition
int Partition(recordtype a[],int i,int j,keytype pivot){
	int L,R;
	L = i;
	R = j;
	while (L<=R) {
		while (a[L].key < pivot) L++;
		while (a[R].key >= pivot) R--;
		if (L<R) swap(a[L],a[R]);
	}
	return L;
}

//QUICK SORT
void QuickSort(recordtype a[],int i,int j){
	keytype pivot;
	int pivotindex,k;
	pivotindex = FindPivot(a,i,j);
	if (pivotindex != -1) {
		pivot = a[pivotindex].key;
		k = Partition(a,i,j,pivot);
		QuickSort(a,i,k-1);
		QuickSort(a,k,j); 
	}
}

//Find Pivot (bien the)
int FindPivot1(recordtype a[], int i, int j){
	keytype firstkey;
	int k;
	k = i+1;
	while (k<=j && a[k].key == a[i].key) k++;
	if (k>j) return -1;
	if (a[k].key<a[i].key) return k;
	return i;
}

//Partition (bien the)
int Partition1(recordtype a[],int i,int j,keytype pivot){
	int L,R;
	L = i;
	R = j;
	while (L<=R) {
		while (a[L].key <= pivot) L++;
		while (a[R].key > pivot) R--;
		if (L<R) swap(a[L],a[R]);
	}
	return L;
}

//QUICK SORT
void QuickSort1(recordtype a[],int i,int j){
	keytype pivot;
	int pivotindex,k;
	pivotindex = FindPivot1(a,i,j);
	if (pivotindex != -1) {
		pivot = a[pivotindex].key;
		k = Partition1(a,i,j,pivot);
		QuickSort1(a,i,k-1);
		QuickSort1(a,k,j); 
	}
}

//PUSH DOWN 
void PushDown(recordtype a[], int first, int last){
	int r = first;
	while (r <= (last-1)/2)
	if (last == 2*r+1) {
		if (a[r].key > a[last].key)
		swap (a[r],a[last]);
	    r=last;
	} else if (a[r].key > a[2*r+1].key && a[2*r+1].key<=a[2*r+2].key){
		swap(a[r],a[2*r+1]);
		r=2*r+1;
	} else if (a[r].key > a[2*r+2].key && a[2*r+2].key<a[2*r+1].key){
		swap(a[r],a[2*r+2]);
		r=2*r+2;
    } else r=last;
}

//HEAP SORT
void HeapSort(recordtype a[],int n) {
	for (int i = (n-2)/2;i>=0;i--)
	PushDown(a,i,n-i);
	for (i = n-1;i>=2;i--) {
		swap(a[0],a[i]);
		PushDown(a,0,i-1);
	} 
	swap(a[0],a[1]);
}


int main (){
	int n,i;
	FILE *file;
	recordtype a[100];
	file = fopen("dayso.inp", "r");
    fscanf(file,"%d",&n);
    for (i = 0; i <= n-1; i++) {
        fscanf(file, "%d", &a[i]);
    }
    
	printf("\n");
	printf("Day so ban dau la: ");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
	}
	
	SelectionSort(a,n);
	printf("\n\nDay so sau khi sap xep chon la: ");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
	}
	
	InsertionSort(a,n);
	printf("\n\nDay so sau khi sap xep xen la: ");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
	}
	
	BubbleSort(a,n);
	printf("\n\nDay so sau khi sap xep noi bot la: ");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
	}
	
	QuickSort(a,0,n-1);
	printf("\n\nDay so sau khi sap xep nhanh la: ");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
	}
	
	HeapSort(a,n);
	printf("\n\nDay so sau khi sap xep vun dong la: ");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
    }
    
    QuickSort1(a,0,n-1);
	printf("\n\nDay so sau khi sap xep nhanh (bien the) la: ");
	for(i=0;i<=n-1;i++){
		printf("%d ",a[i]);
	}
}

