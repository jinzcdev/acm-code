#include <iostream>
#include <string>
using namespace std;
int main(){
	string a = "123456789";
	string b = "abc";
	// cout << a.length() << a.size() << endl;	//length & size 得到字符串的长度.
	// a.clear();
	// a.insert(3,b);	//在指定位置插入一个字符串,只能是字符串类型.
	// a.insert(a.begin()+3,b.begin(),b.end());	//首参数表示插入字符串的起始位置(迭代器类型).
	// a.erase(a.begin()+2,a.end()-1);	//使用迭代器类型 参数表示起始位置和结束位置.
	// a.erase(5,3);	//使用整型参数 first:起始位置 second:长度


/*	string c = "IamChar.";
	cout << c.substr(0,1) << endl;
	cout << c.substr(1,2) << endl;
	cout << c.substr(3,5) << endl;
	//求字串,首个参数为起始位置,第二个参数为字串长度.
*/


	/*
	//匹配字符串.
	string c = "567";
	cout << a.find(c) << endl;	//匹配出现第一次相同子串的位置

	if(a.find(c,5) != string::npos){
		cout << a.find(c,5) << endl;
	}*/

	// a.replace(3,3,b);	//替换字符串.


	cout << a <<endl;
	return 0;
}