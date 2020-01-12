#include <cstdio>
#include <set>
using namespace std;
int main(){
	set<int> s;
/*	for (int i = 0; i < 5; ++i)
	{
		s.insert(i);
	}
*/

	s.insert(1);
	s.insert(4);
	s.insert(2);
	s.insert(2);
	s.insert(2);
	s.insert(8);

	printf("size = %d\n",s.size());
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		printf("%d ",*it);
	}

	set<int>::iterator it = s.find(2);
	it++;		// 存在多个文件
	printf("%d\n",*(it++));
	
	return 0;
}