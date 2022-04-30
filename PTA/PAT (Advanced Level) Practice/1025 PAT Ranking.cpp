// https://pintia.cn/problem-sets/994805342720868352/problems/994805474338127872
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 30010;

struct Student{
    char id[20];
    int score;
    int location_number;
    int rank_number;
}stu[30010];

bool cmp(Student a, Student b){
    if(a.score != b.score) return a.score > b.score;
    else return strcmp(a.id,b.id) < 0;
}

int main(){
    int n,k,cnt = 0;    // cnt(count)标记考场学生的总个数
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        scanf("%d",&k);
        for (int j = cnt; j < cnt + k; j++){
            scanf("%s %d",stu[j].id,&stu[j].score);
            stu[j].location_number = i;     // 考场号按照读入的顺序计数
        }
        sort(stu + cnt,stu + cnt + k,cmp);
        stu[cnt].rank_number = 1;
        for (int i = 1; i < k; i++){
            if(stu[cnt + i].score == stu[cnt + i - 1].score){
                stu[cnt + i].rank_number = stu[cnt + i - 1].rank_number;
            }else{
                stu[cnt + i].rank_number = i + 1;
            }
        }
        cnt += k;
    }

    sort(stu,stu + cnt,cmp);

    printf("%d\n",cnt);
    int r = 1;
    for (int i = 0; i < cnt; i++){
        if(i > 0 && stu[i].score != stu[i - 1].score){
            r = i + 1;
        }
        printf("%s %d %d %d\n",stu[i].id,r,stu[i].location_number,stu[i].rank_number);
    }
    return 0;
}