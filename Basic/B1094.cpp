#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

int l,k;
char* n;

bool IsPrime(int n){
	if(n <= 1)	return false;
	int sqr = (int)sqrt(1.0 * n);
	for (int i = 2; i < sqr; i++){
		if(n % i == 0)	return false;
	}
	return true;
}

void findPrimeGroup(){
	
}


int main(){
	scanf("%d %d",&l,&k);
	n = (char*)malloc(sizeof(cahr));
	scanf("%s",n);

	return 0;
}