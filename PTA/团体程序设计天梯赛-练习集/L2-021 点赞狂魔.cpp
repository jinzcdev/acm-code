// https://pintia.cn/problem-sets/994805046380707840/problems/994805058485469184
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 110;
// struct node {
//     string name;
//     int cnt, num;
// };
// bool cmp(node &a, node &b) {
//     return a.cnt != b.cnt ? a.cnt > b.cnt : a.num < b.num;
// }
// int main() {
//     int n, a;
//     scanf("%d", &n);
//     vector<node> v(n);
//     string str;
//     for (int i = 0; i < n; i++) {
//         cin >> v[i].name >> v[i].num;
//         unordered_set<int> s;
//         for (int j = 0; j < v[i].num; j++) {
//             scanf("%d", &a);
//             s.insert(a);
//         }
//         v[i].cnt = s.size();
//     }
//     sort(v.begin(), v.end(), cmp);
//     vector<string> ans;
//     for (int i = 0; i < 3; i++) {
//         if (i < v.size()) ans.push_back(v[i].name);
//         else ans.push_back("-");
//     }
//     for (int i = 0; i < 3; i++) {
//         if (i != 0) printf(" ");
//         cout << ans[i];
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int N = 110;
struct node {
    string name;
    int cnt;
    double avg;
    bool operator<(const node &a) const {
        return cnt != a.cnt ? cnt > a.cnt : avg < a.avg;
    }
};
int main() {
    int n, a, k;
    scanf("%d", &n);
    vector<node> v(n);
    string str;
    for (int i = 0; i < n; i++) {
        cin >> v[i].name >> k;
        unordered_set<int> s;
        for (int j = 0; j < k; j++) {
            scanf("%d", &a);
            s.insert(a);
        }
        v[i].cnt = s.size();
        v[i].avg = k * 1.0 / v[i].cnt;
    }
    sort(v.begin(), v.end());
    vector<string> ans;
    for (int i = 0; i < 3; i++) {
        if (i < v.size()) ans.push_back(v[i].name);
        else ans.push_back("-");
    }
    for (int i = 0; i < 3; i++) {
        if (i != 0) printf(" ");
        cout << ans[i];
    }
    return 0;
}