#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void traverseVector(vector<int> v){
	cout << "size: " << v.size() << " result: "; //size() 输出大小.
	for(vector<int>::iterator it = v.begin();it != v.end();it++){
		cout << *it <<" ";
	}
	cout << endl;
}

bool cmp(int a,int b){
	return a > b;
}

int main(){
	vector<int> node; int count = 10;
	while(count) node.push_back(10 - count--); //push_back() 把0-9放入vector中.
	node.push_back(2);
	node.push_back(9);
	node.push_back(1);
	node.push_back(5);
	// sort(node.begin(),node.end(),cmp);
	traverseVector(node);
	node.pop_back(); //pop_back() 删除最末尾的元素.
	node.erase(node.begin() + 1, node.end() - 7);// erase() 删除元素.
	node.insert(node.begin() + 1,1); //在it的位置插入元素 O(N).
	node.clear(); // 清空所有元素.
	traverseVector(node); //iterator迭代器遍历.
	return 0;
}
