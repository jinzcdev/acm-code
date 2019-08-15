// https://pintia.cn/problem-sets/994805342720868352/problems/994805407749357568
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int n, in[maxn], CBT[maxn];

bool cmp(int a, int b){
    return a < b;
}

int index = 0;
void inOrder(int root){         // 中序遍历空的完全二叉排序(根结点序号为1), 遍历同时作赋值, 中序序列为有序序列
    if (root > n) return;
    inOrder(root * 2);
    CBT[root] = in[index++];
    inOrder(root * 2 + 1);
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &in[i]);
    }
    sort(in, in + n, cmp);      // 升序结点数组获得中序序列
    inOrder(1);
    for (int i = 1; i <= n; i++){
        printf("%d", CBT[i]);
        if (i < n) printf(" ");
    }
    return 0;
}