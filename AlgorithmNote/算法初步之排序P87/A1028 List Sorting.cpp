// https://pintia.cn/problem-sets/994805342720868352/problems/994805468327690240
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int c;

struct Student {
    int id;
    char name[10];
    int score;
} stu[maxn];

bool cmp(Student a, Student b){
    if (c == 1){
        return a.id < b.id;
    }else if(c == 2){
        int s = strcmp(a.name, b.name);
        if (s != 0) return s < 0;
        else return a.id < b.id;
    }else{
        if (a.score == b.score) return a.id < b.id;
        else return a.score < b.score;
    }
}

int main(){
    int n;
    scanf("%d%d",&n,&c);
    for (int i = 0; i < n; i++){
        scanf("%d %s %d", &stu[i].id, stu[i].name, &stu[i].score);
    }
    sort(stu, stu + n, cmp);
    for (int i = 0; i < n; i++){
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
    }
    return 0;
}