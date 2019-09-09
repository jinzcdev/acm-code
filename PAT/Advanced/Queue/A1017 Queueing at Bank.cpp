// https://pintia.cn/problem-sets/994805342720868352/problems/994805491530579968
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct Customer {
    int arriveTime;         // 客户到达时间
    int procrssTime;        // 客户所需的业务处理时间
} tempCustomer;
vector<Customer> customer;
vector<int> window(100, 8 * 3600);  // 存放每个窗口的结束所有业务的最终时间
bool cmp(Customer a, Customer b) {
    return a.arriveTime < b.arriveTime;
}
int main(){
    int n, k, h, m, s, pt;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d:%d:%d %d", &h, &m, &s, &pt);
        int arriveTime = h * 3600 + m * 60 + s; // 把时间转为时分秒
        if (arriveTime > 17 * 3600) continue;   // 跳过无法接收业务办理的客户
        tempCustomer.arriveTime = arriveTime;
        tempCustomer.procrssTime = pt * 60;
        customer.push_back(tempCustomer);
    }
    if (customer.size() == 0) {     // 满足条件的人数为0时直接终止程序
        printf("0.0\n");
        return 0;
    }
    sort(customer.begin(), customer.end(), cmp);    // 按客户到达的时间递增排序
    double wt = 0.0;    // waiting time, 记录总的等待时间
    for (int i = 0; i < customer.size(); i++) {
        int indexW, minOverTime = 0x7FFFFFFF;   // 找出最早结束的窗口
        for (int j = 0; j < k; j++) {
            if (window[j] < minOverTime) {
                indexW = j;
                minOverTime = window[j];
            }
        }
        if (window[indexW] <= customer[i].arriveTime) { // 最早结束时间比客户到达时间早, 不需要等待
            window[indexW] = customer[i].arriveTime + customer[i].procrssTime;
        } else { // 最早结束时间比客户到达时间晚, 则客户需要等待
            wt += window[indexW] - customer[i].arriveTime;      // 客户的等待时间
            window[indexW] += customer[i].procrssTime;          // 重新记录该窗口的业务结束时间
        }
    }
    printf("%.1f", wt / customer.size() / 60.0);
    return 0;
}