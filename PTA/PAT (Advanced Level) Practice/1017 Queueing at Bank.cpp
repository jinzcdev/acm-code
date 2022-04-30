// https://pintia.cn/problem-sets/994805342720868352/problems/994805491530579968
#include <bits/stdc++.h>
using namespace std;
struct Customer {
    int arriveTime, procrssTime;
};
bool cmp(Customer a, Customer b) { return a.arriveTime < b.arriveTime; }
int main() {
    int n, k, h, m, s, pt;
    scanf("%d%d", &n, &k);
    vector<Customer> customer;
    vector<int> window(100, 8 * 3600);
    for (int i = 0; i < n; i++) {
        scanf("%d:%d:%d %d", &h, &m, &s, &pt);
        int arriveTime = h * 3600 + m * 60 + s;
        if (arriveTime <= 17 * 3600) customer.push_back({arriveTime, pt * 60});
    }
    if (customer.size() == 0) {
        printf("0.0\n");
        return 0;
    }
    sort(customer.begin(), customer.end(), cmp);
    double wt = 0.0;
    for (int i = 0; i < customer.size(); i++) {
        int indexW, minOverTime = 0x7FFFFFFF;
        for (int j = 0; j < k; j++) {
            if (window[j] < minOverTime) {
                indexW = j;
                minOverTime = window[j];
            }
        }
        if (window[indexW] <= customer[i].arriveTime)
            window[indexW] = customer[i].arriveTime + customer[i].procrssTime;
        else {
            wt += window[indexW] - customer[i].arriveTime;
            window[indexW] += customer[i].procrssTime;
        }
    }
    printf("%.1f", wt / customer.size() / 60.0);
    return 0;
}