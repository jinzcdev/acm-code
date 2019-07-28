// https://pintia.cn/problem-sets/994805260223102976/problems/994805262622244864
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main() {
    char *a = (char*)malloc(sizeof(char));
	scanf("%s",a);
	while (scanf("%s",a)) {
        if (a[2] == 'T') printf("%d", a[0]-'A'+1);
    }
    return 0;
}