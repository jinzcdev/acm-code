// https://pintia.cn/problem-sets/994805260223102976/problems/994805263964422144
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m, k, temp, cntP = 0, cntG = 0;
    bool check[10000] = {false};
    cin >> n >> m;
    while (m--) {
        cin >> temp;
        check[temp] = true;
    }
    string name;
    while (n--) {
        cin >> name >> k;
        bool flag = false;
        vector<int> v(k);
        for (int i = 0; i < k; i++) {
            cin >> v[i];
            if (check[v[i]]) flag = true;
        }
        if (flag) {
            cntP++;
            cout << name << ":";
            for (int i = 0; i < v.size(); i++) {
                if (check[v[i]]) {
                    printf(" %04d", v[i]);
                    cntG++;
                }
            }
            printf("\n");
        }
    }
    printf("%d %d", cntP, cntG);
    return 0;
}