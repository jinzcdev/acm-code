// https://pintia.cn/problem-sets/994805342720868352/problems/994805502658068480
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 2010;

struct Student{
    int id;
    int grade[4];
} stu[maxn];

int now;
char course[4] = {'A','C','M','E'};
int r[10000000][4] = {0};

bool cmp(Student a,Student b){
    return a.grade[now] > b.grade[now];
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++){
        scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
        stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3])) / 3.0 + 0.5;
    }

    for(now = 0; now < 4; now++){
        sort(stu, stu + n, cmp);
        r[stu[0].id][now] = 1;
        for(int i = 1; i < n; i++){
            if(stu[i].grade[now] == stu[i - 1].grade[now]){
                r[stu[i].id][now] = r[stu[i - 1].id][now];
            }else{
                r[stu[i].id][now] = i + 1;
            }
        }
    }

    int id;
    for (int i = 0; i < m; i++){
        scanf("%d",&id);
        if(r[id][0] == 0) printf("N/A\n");
        else{
            int k = 0;
            for (int j = 0; j < 4; j++){
                if(r[id][j] < r[id][k]){
                    k = j;
                }
            }
            printf("%d %c\n",r[id][k],course[k]);
        }
    }
    return 0;
}