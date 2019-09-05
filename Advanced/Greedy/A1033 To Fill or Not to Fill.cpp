// https://pintia.cn/problem-sets/994805342720868352/problems/994805458722734080
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 0x7FFFFFFF;
struct station {
    double dis, price;
} st[maxn];
bool cmp(station a, station b) {
    return a.dis < b.dis;
}
int main(){
    int n;
    double Cmax, D, Davg;
    scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &st[i].price, &st[i].dis);
    }
    st[n].price = 0;
    st[n].dis = D;  // n就是终点站
    sort(st, st + n, cmp);
    if (st[0].dis != 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }
    int now = 0;
    double ans = 0.0, nowTank = 0, maxDis = Cmax * Davg;    // 加满油能行驶的最大距离
    while (now < n) {
        int k = -1;
        double minPrice = INF;
        // 找到从now能到达的比当期加油站更便宜的第一个加油站, 如果不存在, 就找加满油后所能到达的加油站中最便宜的站
        for (int i = now + 1; i <= n && st[i].dis - st[now].dis <= maxDis; i++) {
            if (st[i].price < minPrice) {
                minPrice = st[i].price;
                k = i;
                if (minPrice < st[now].price) { // 找到的加油站比now便宜, 直接break
                    break;
                }
            }
        }
        if (k == -1) break;     // k==-1,加满油也无法到达下一站, 此时退出, 输出答案
        double gasNowToK = (st[k].dis - st[now].dis) / Davg;    // 从当前站到K站所需要的油量
        if (minPrice < st[now].price) { // 比当前站便宜
            if (nowTank < gasNowToK) {  // 剩余油量不够, 则加至刚好到k站的油量
                ans += (gasNowToK - nowTank) * st[now].price;
                nowTank = 0;    // 到达后, 油量剩余为0
            } else {
                nowTank -= gasNowToK;   // 剩余油量足够到达k站, 则当前油量减去所需油量
            }
        } else {        // 比当前站价格高, 则在当前站加满油
            ans += (Cmax - nowTank) * st[now].price;
            nowTank = Cmax - gasNowToK;
        }
        now = k;    // 游客到达k站
    }
    if (now == n) printf("%.2f\n", ans);
    else printf("The maximum travel distance = %.2f\n", st[now].dis + maxDis);
    return 0;
}