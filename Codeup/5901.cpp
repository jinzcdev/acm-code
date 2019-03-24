#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char* str = new char;
	scanf("%s",str);
	int len = strlen(str),mid = len / 2;
	bool isPalindrome = true;
	for(int i = 0;i <= mid;i++){
		if(str[i] != str[len - i - 1]){
			isPalindrome = false;
			break;
		}
	}
	if(isPalindrome)
		printf("YES");
	else
		printf("NO");
	return 0;
}