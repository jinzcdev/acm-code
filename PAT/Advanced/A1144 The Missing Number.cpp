// https://pintia.cn/problem-sets/994805342720868352/problems/994805343463260160
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, temp;
    map<int, int> hash;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (temp > 0) hash[temp] = 1;
    }
    int number = 1;
    while (hash[number] == 1) number++;
    cout << number;
    return 0;
}