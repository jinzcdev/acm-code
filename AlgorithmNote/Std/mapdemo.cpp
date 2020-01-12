#include <iostream>
#include <map>
using namespace std;
int main(){
	map<char,int> m;
	m['a'] = 1;
	m['b'] = 2;

	cout << m.find('a') -> second << endl;
	//使用key或迭代器删除此元素.
	// m.erase('a');			
	// m.erase(m.find('a'));

	map<char,int>::iterator it = m.begin();
	for (; it != m.end(); it++)
	{
		printf("%c %d\n",it->first,it->second);
	}

	cout << "size:" <<m.size() << endl;


	return 0;
}