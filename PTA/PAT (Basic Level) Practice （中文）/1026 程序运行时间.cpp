// https://pintia.cn/problem-sets/994805260223102976/problems/994805295203598336
#include <cstdio>
int main() {
    long long begin, end, tick, s;
    scanf("%lld%lld", &begin, &end);
    tick = end - begin;
    if (tick % 100 >= 50) s = tick / 100 + 1;
    else s = tick / 100;
    int h, m;
    h = s / 3600;
    m = (s - 3600 * h) / 60;
    s = s % 60;
    printf("%02d:%02d:%02d", h, m, s);
    return 0;
}