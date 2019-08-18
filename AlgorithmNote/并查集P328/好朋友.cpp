#include <cstdio>
const int N = 110;
int father[N];
bool isRoot[N];

void init(int n){
    for (int i = 1; i <= n; i++){
        father[i] = i;
        isRoot[i] = false;
    }
}

int findFather(int x){
    if (x == father[x]) return x;
    else {
        int F = findFather(father[x]);
        father[x] = F;
        return F;
    }
}

void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB){
        father[faA] = faB;
    }
}

int main(){
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    init(n);
    for (int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        Union(a, b);
    }
    for (int i = 1; i <= n; i++){
        isRoot[findFather(i)] = true;
        printf("father[%d]=%d\n", i, father[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        ans += isRoot[i];
    }
    printf("%d", ans);
    return 0;
}


/*
int findFather(int x){
   int a = x;
   while (x != father[x]){
       x = father[x];
   }
   while (a != father[a]){
       int z = a;
       a = father[a];
       father[z] = x;
   }
   return x;
}
---------
7 5
1 2
2 3
3 1
1 4
5 6
3
--------
*/