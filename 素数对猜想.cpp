#include <stdio.h>
int IsPrime (int m) {
	int i;
	　　 if (m == 2) return 1;
	　　 if (m == 1 || m % 2 == 0) return 0;
	　　 for (i = 3; i * i <= m;) {
		　　 if (m % i == 0) return 0;
		　　 i += 2;
	　　 }
	　　 return 1;
}
void main () {
	　　 printf("They’re primes: \n\t");
	　　 for (int i = 1; i < 101; i++)
		　　 if (IsPrime(i)) printf(“%d “, i);
	　　 printf("\n");
}