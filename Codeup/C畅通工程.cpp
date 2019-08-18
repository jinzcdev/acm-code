// http://codeup.cn/problem.php?cid=100000615&pid=1
#include <cstdio>
const int maxn = 1010;
int father[maxn];
bool isRoot[maxn];

int findFather(int v){
    if (v == father[v]) return v;
    else {
        int F = findFather(father[v]);
        father[v] = F;
        return F;
    }
}

void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB)
        father[faA] = faB;
}

void init(int n){
    for (int i = 1; i <= n; i++){
        father[i] = i;
        isRoot[i] = false;
    }
}


int main(){
    int n, m, a, b;
    while (scanf("%d", &n) != EOF){
        if (n == 0) break;
        init(n);
        scanf("%d", &m);
        for (int i = 0; i < m; i++){
            scanf("%d%d", &a, &b);
            Union(a, b);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++){
            int fa = findFather(i);
            if (!isRoot[fa]){
                ans++;
                isRoot[fa] = true;
            }
        }
        printf("%d\n", ans - 1);
    }
    return 0;
}

/*
5 3
1 2
3 2
4 5
5 3
1 2
3 2
4 5
0
 */ 