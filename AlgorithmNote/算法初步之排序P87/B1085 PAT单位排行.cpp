// https://pintia.cn/problem-sets/994805260223102976/problems/994805260353126400
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 100010;
map<string,int> mp; // 用map存放学校所在的索引号

struct School{
    char sname[10];
    int A,B,T;  // 甲,乙,顶级总分
    int stu_n;    // 考生数量
    int sum;    // 加权总分
} sch[maxn];

bool cmp(School a, School b){
    if(a.sum != b.sum) return a.sum > b.sum;
    else if (a.stu_n != b.stu_n) return a.stu_n < b.stu_n;
    else return strcmp(a.sname,b.sname) < 0;
}
// 学校单位码转为小写
void toLower(char *str){
    int len = strlen(str);
    for (int i = 0; i < len; i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    char id[10],sname[10];  // 考生准考证号, 学校名称
    int score,cnt = 0;
    for (int i = 0; i < n; i++){
        scanf("%s%d%s", id, &score, sname);
        toLower(sname);
        int pos = mp[sname];
        if(pos == 0){   // map中valuue默认为"0", 代表该学校未出现过
            pos = ++cnt;
            strcpy(sch[pos].sname,sname);
            mp[sname] = pos;    // 记录该学校的索引号
        }
        if(id[0] == 'A') sch[pos].A += score;
        else if(id[0] == 'B') sch[pos].B += score;
        else if(id[0] == 'T') sch[pos].T += score;
        sch[pos].stu_n++;        
    }
    //  计算机各学校PAT加权总分
    for (int i = 1; i <= cnt; i++){
        sch[i].sum = sch[i].B / 1.5 + sch[i].A + sch[i].T * 1.5;
    }

    sort(sch + 1, sch + cnt + 1, cmp);  // 第一个元素从1开始
    printf("%d\n",cnt);
    int k = 1;  // 记录前一个学校的排名
    for (int i = 1; i <= cnt; i++){
        if(i > 1 && sch[i].sum == sch[i - 1].sum){
            printf("%d %s %d %d\n", k, sch[i].sname, sch[i].sum, sch[i].stu_n);
        }else{
            k = i;
            printf("%d %s %d %d\n", k, sch[i].sname, sch[i].sum, sch[i].stu_n);
        }
    }
    return 0;
}