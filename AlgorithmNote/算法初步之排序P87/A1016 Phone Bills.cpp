// https://pintia.cn/problem-sets/994805342720868352/problems/994805493648703488
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int toll[24] = {0};
int month = 0;

struct Record{
    char name[30];
    int month, dd, hh, mm;
    int time;
    bool status;       // on-line : true , off-line : false
} rec[maxn];

bool cmp(Record a, Record b){
    int s = strcmp(a.name, b.name);
    if (s != 0) return s < 0;
    else return a.time < b.time;
}

int computeAmount(Record a, Record b){
    int daySum = 0;
    for (int i = 0; i < 24; i++)
        daySum += toll[i];
    
    
}

int main(){
    for (int i = 0; i < 24; i++){
        scanf("%d", toll + i);
    }
    int n;
    char word[10];
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%s %d:%d:%d:%d %s", rec[i].name, &rec[i].month, &rec[i].dd, &rec[i].hh, &rec[i].mm, word);
        rec[i].time = (rec[i].dd * 24 + rec[i].hh) * 60 + rec[i].mm;
        if (strcmp(word, "on-line") == 0){
            rec[i].status = true;
        }else{
            rec[i].status = false;
        }
    }
    month = rec[0].month;
    sort(rec, rec + n, cmp);
    int on = 0, off, next;  // 标记当前on, off所在的下标
    while (on < n){
        int needPrint = 0;
        next = on;
        // 找到下一个用户的下标, 同时判断当前用户是否存在可输出的通话记录
        while (next < n && strcmp(rec[next].name,rec[on].name) == 0){
            if (needPrint == 0 && rec[next].status == true){
                needPrint = 1;
            }else if (needPrint == 1 && rec[next].status == false){
                needPrint = 2;
            }
            next++;
        }
        // 不存在可输出的通话记录就直接进行下一次的循环(即检查下一用户)
        if (needPrint < 2){
            on = next;
            continue;
        }
        printf("%s %02d\n", rec[on].name, month);
        int amount = 0;
        while (on < next){
            while (on < next - 1 && !(rec[on].status == true && rec[on + 1].status == false)){
                on++;
            }
            off = on + 1;
            // 当前用户的通话记录列表已全部遍历
            if (off == next){
                on = next;
                break;
            }
            printf("%02d:%02d:%02d ", rec[on].dd, rec[on].hh , rec[on].mm);
            printf("%02d:%02d:%02d ", rec[off].dd, rec[off].hh , rec[off].mm);
            int time = rec[off].time - rec[on].time;
            int money = time * toll[month];
            amount += money;
            printf("%d $%.2f\n", time, money / 100.0);
        }
        printf("Total amount: $%.2f\n", amount / 100.0);
    }
    return 0;
}