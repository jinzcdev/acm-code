// https://pintia.cn/problem-sets/994805260223102976/problems/994805260583813120
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int d, n;
    cin >> d >> n;
    vector<int> v, temp;
    v.push_back(d);
    while (--n) {
        int now = v[0], cnt = 0;
        temp.push_back(now);
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == now) {
                cnt++;
            } else {
                now = v[i];
                temp.push_back(cnt);
                temp.push_back(now);
                cnt = 1;
            }
        }
        temp.push_back(cnt);
        v = temp;
        temp.clear();
    }
    for (auto it : v) {
        printf("%d", it);
    }
    return 0;
}