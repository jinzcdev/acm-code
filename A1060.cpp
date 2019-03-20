#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	string a,b;
	scanf("%d",&n);
	cin >> a >> b;
	string aa = a.substr(0,3);
	string bb = b.substr(0,3);
	if(b.find(aa) == 0){
		printf("YES ");
		printf("0.%s*10^%d",aa.c_str(),n);
	}
	else
		printf("NO ");
	return 0;
}