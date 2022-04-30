// https://pintia.cn/problem-sets/994805260223102976/problems/994805262303477760
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
    int n, m, temp, teacher;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> teacher;
        vector<int> v;
        double student = 0;
        for (int j = 0; j < n - 1; j++) {
            cin >> temp;
            if (temp >= 0 && temp <= m) v.push_back(temp);
        }
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size() - 1; i++) {
            student += v[i];
        }
        student /= v.size() - 2;
        printf("%.0f\n", round((teacher + student) / 2));
    }
    return 0;
}