// http://codeup.cn/problem.php?id=1928
#include <cstdio>
#include <cstring>
int month[13][2] = {{365, 366}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}};

// 判断是否为闰年
bool isLeap(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main(){
    int time1, time2;
    scanf("%d%d", &time1, &time2);
    // 始终让time1更小
    if (time1 > time2){
        int temp = time1;
        time1 = time2;
        time2 = temp;
    }
    int y1 = time1 / 10000, m1 = time1 % 10000 / 100, d1 = time1 % 100;
    int y2 = time2 / 10000, m2 = time2 % 10000 / 100, d2 = time2 % 100;

    int ans = 0;
    // 逐天计算日差
    while (y1 < y2 || m1 < m2 || d1 < d2){
        d1++;
        if (d1 == month[m1][isLeap(y1)] + 1){
            m1++;
            d1 = 1;
        }
        if (m1 == 13){
            y1++;
            m1 = 1;
        }
        ans++;
    }

    printf("%d", ans);
    return 0;
}