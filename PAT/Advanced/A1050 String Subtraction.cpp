#include <cstdio>
#include <cstring>
 
char str1[10010];
char str2[10010];
 
int main(){
	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i = 0; i < len1; i++){
		int j;
		for(j = 0; j < len2; j++){
			if(str1[i] == str2[j]){
				break;
			}
		}
		if(j == len2){
			printf("%c", str1[i]);
	    }
	}
	return 0;
}