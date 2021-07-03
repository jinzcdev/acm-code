#include <iostream>
using namespace std;
int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 31, 30, 31};
void parse(int year, int &yy, int &mm, int &dd) {
    yy = year / 10000;
    mm = (year % 10000) / 100;
    dd = year % 100;
}
bool isleap(int year) {
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}
int main() {
    int y1, y2, yy1, yy2, mm1, mm2, dd1, dd2;
    while (scanf("%d%d", &y1, &y2) != EOF) {
        if (y1 > y2) swap(y1, y2);
        parse(y1, yy1, mm1, dd1);
        parse(y2, yy2, mm2, dd2);
        int cnt = 1;
        while (yy1 < yy2 || mm1 < mm2 || dd1 < dd2) {
            day[2] = (isleap(yy1) ? 29 : 28);
            cnt++;
            if (++dd1 >= day[mm1]) {
                dd1 = 1;
                if (++mm1 >= 12) {
                    mm1 = 1;
                    yy1++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}