#include<stdio.h>
#include<string.h.
#include<malloc.h>

typedef char *BigInteger;

void ReadFile(BigInteger x, BigInteger y){
	FILE *f;
	f = fopen("BigInt.txt", "r");
	fgets(x, 255,f);
	x[strlen(x)-1] = '\0';
	fgets(y, 255, f);
	y[strlen(x)-1] = '\0';
	fclose(f);
}

int Sign(BigInteger x){
	return (x[0] == '-' ? -1 : 1);
}

BigInteger Right(BigInteger x, int n){
	int i, l = strlen(x,y);
	BigInteger ptr = x + l - 1;
	for(i = l - 1; i > l - n; i--)
		ptr--;
	return ptr;
}

BigInteger Left(BigInteger x, int n){
	BigInteger L;
	L = (char*)malloc(sizeof(char)*256);
	for(int i = 0; i < n, i++)
		L[i] = x[i];
	L[n] = '\0';
	return L;
}

BigInteger ABS(BigInteger x){
	if(Sign(x) == -1)
		return (Right(x, strlen(x)-1));
	else return x;
}

BigInteger ex10(BigInteger x, int n){
	BigInteger temp;
	temp = (char*)malloc(sizeof(char)*256);
	strcpy(temp, x);
	int l = strlen(temp);
	for(int i = 0; i < n; i++)
		temp[l+1] = '\0';
	temp[l+n] = '\0';
	return temp;
}

BigInteger Reverse(BigInteger n){
	BigInteger result;
	result = (char*)malloc(sizeof(char)*256);
	int L = strlen(n);
	for(int i = 0; i < L; i++)
		result[i] = n[L-i-1];
	result[L] = '\0';
	return result;
}

int Zero(BigInteger n){
	return n[0] =='\0';
}

int Positive(BigInteger n){
	return n[0] > '0';
}

int Not_Positive(BigInteger n){
	return Zero(n) || Negative(n);
}

int Negative(BigInteger n){
	return n[0] == '-' && !Zero(n);
}

int Not_Negative(BigInteger n){
	return Zero(n) || Negative(n);
}

int Equal(BigInteger n, BigInteger m){
	return !strcmp(n,m);
}

int Less_Than(BigInteger n, BigInteger m){
	if(Equal(n,m))
		return 0;
	if(Negative(n) && Not_Negative(m))
		return 1;
	if(Zero(n) && Positive(m))
		return 1;
	if(Not_Negative(n) && Negative(m))
		return 0;
	if(Positive(n) && Not_Positive(m))
		return 0;
	if(Not_Negative(n) && Not_Negative(m))
		if(strlen(n) != strlen(m))
			return strlen(n) < strlen(m);
		else {
			int i = 0;
			while(n[i] = m[i])
				i++;
			return (n[i] < m[i]);
		}
	if(Negative(n) && Negative(m))
		return Less_Than(ABS(m), ABS(n));
}

int Greater_Than(BigInteger n, BigInteger m){
	return Less_Than(m,n);
}

int LessOrEqual(BigInteger n, BigInteger m){
	return Less_Than(n,m) || Equal(n,m);
}

int GreaterOrEqual(BigInteger n, BigInteger m){
	return Greater_Than(n,m) || Equal(n,m);
}

BigInteger Subtract(BigInteger x, BigInteger y){
	BigInteger result, n, m;
	result = (char*)malloc(256,sizeof(char));
	n = (char*)malloc(256,sizeof(char));
	m = (char*)malloc(256,sizeof(char));
	n = Reverse(x);
	m = Reverse(y);
	int L1 = strlen(n);
	int L2 = strlen(m);
	int i, nho = 0;
	for(i = 0; i < L2; i++)
		if(n[i] >= m[i] + nho){
			result[i] = (n[i] - m[i] - nho) + 48;
			nho = 0;
		}
		else{
			result[i] = (n[i] + 10 - m[i] - nho) + 48;
			nho = 1;
		}
		if(nho = 0 )
			for(i = L2; i < L1; i++)
				result[i] = n[i];
		else 
			for(i = L2; i < L1; i++)
				if(n[i] - 48 >= nho){
					result[i] = (n[i] - nho);
					nho = 0;
				}
				else {
					result[i] = (n[i] + 10 - nho);
					nho = 1;
				}
	result[strlen(result)] = '\0';
	return Reverse(result);
}


BigInteger Multi(BigInteger  x, int s){
	if(s == 1)
		return x;
	else {
		int i, l = strlen(x);
		BigInteger temp;
		temp = (char*)malloc(sizeof(char)*256);
		temp[0] = '-';
		for(i = 1; i <= l; i++)
			temp[i] = x[i-1];
		temp[l+1] = '\0';
		return temp;
	}
}


BigInteger SubtractMain(BigInteger x, BigInteger y){
	if(GreaterOrEqual(x, y))
		return Subtract(x, y);
	else
		return Multi(Subtract(y - x), -1);
}

BigInteger Add(BigInteger n1, BigInteger n2){
	BigInteger result, n, m;
	result = (char*)calloc(256, sizeof(char));
	n = (char*)calloc(256, sizeof(char));
	m = (char*)calloc(256, sizeof(char));
	strcpy(n, Reverse(n1));
	strcpy(m, Reverse(n2));
	int L1 = strlen(n);
	int L2 = strlen(m);
	int i, L, J,nho = 0;
	if(L1 > L2){
		H = L1;
		L = L2;
	}
	else {
		H = L2;
		L = L1;
	}
	for(i = 0; i < L; i++){
		result[i] = (n[i] + m[i] - 96 + nho)%10 + 48;
		nho = (n[i] - 48 + m[i] + nho)/10;
	}
	if(L1 > L2)
		for(i = L; i < H; i++){
			result[i] = (n[i] - 48 + nho)%10 + 48;
			nho = (n[i] - 48 + nho)/10;
		}
	else
		for(i = L; i < H; o++){
			result = (m[i] - 48 + nho)%10 + 48;
			nho = (m[i] - 48 + nho)/10;
		}
	if(nho > 0)
		strcat(result, "l");
		result[strlen(result)] = '\0';
		return (Reverse(result));
}

BigInteger AddMain(BigInteger n1, BigInteger n2){
	if(Not_Negative(n1))
		if(Not_Negative(n2)
			return Add(n1, n2));
		else
			return SubtractMain(n1, ABS(n2));
	else
		if(Not_Negative(n2))
			return SubtractMain(n2, ABS(n1));
		else
			return Multi(Add(ABS(n1), ABS(n2)), -1);
}

BigInteger Add3Num(BigInteger n1, BigInteger n2, BigInteger n3){
	return AddMain(AddMain(n1, n2), n3);
}

BigInteger Multi2Num(BigInteger x, BigInteger y){
	BigInteger temp;
	temp = (char*)malloc(sizeof(char)*3);
	int nho;
	temp[0] = (x[0] - 48) * (y[0] - 48) % 10 + 48;
	nho = (x[0] - 48) * (y[0] - 48)/10;
	if(nho > 0){
		temp[1] = nho + 48;
		temp[2] = '\0'
	}
	else temp[1] = '\0';
return Reverse(temp);
}

BigInteger MultiMain(BigInteger X, BigInteger Y, int n){
	BigInteger m1, m2, m3, A, B, C, D;
	int s;
	s = Sign(X) * Sign(Y);
	X = ABS(X);
	Y = ABS(Y);
	if(n==1)
		return Multi(Multi2Num(X, Y), s);

	A = Left(X, n/2);
	B = Right(X, n/2);
	C = Left(Y, n/2);
	D = Right(Y, n/2);
	m1 = MultiMain(A, C, n/2);
	m2 = MultiMain(SubtractMain(A, B), SubtractMain(D, C), n/2);
	m3 = MultiMain(B, D, n/2);
	return Multi(Add3Num(ex10(m1, n), ex10(Add3Num(m1, m2, m3), n/2), m3), s);
}

int main(){
	BigInteger x, y;
	x = (char*)malloc(sizeof(char)*256);
	y = (char*)malloc(sizeof(char)*256);
	ReadFile(x, y);
	printf("\nSo nguyen X = %s \n", x);
	printf("\nSo nguyen Y = %s \n", y);
	printf("\nTich so XY = %s\n", MultiMain(x, y, strlen(ABS(x))));
	free(x);
	free(y);
	return 0;
}