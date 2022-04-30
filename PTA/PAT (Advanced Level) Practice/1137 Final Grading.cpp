// https://pintia.cn/problem-sets/994805342720868352/problems/994805345401028608
#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
struct node {
    string id;
    int gp, gm, gf, g;
};
bool cmp(node &a, node &b) { return a.g != b.g ? a.g > b.g : a.id < b.id; }
int main() {
    int p, m, n, grade, cnt = 0;
    string id;
    scanf("%d%d%d", &p, &m, &n);
    vector<node> stu;
    unordered_map<string, int> strToNum;
    while (p--) {
        cin >> id >> grade;
        if (grade < 200) continue;
        stu.push_back({id, grade, -1, -1});
        strToNum[id] = ++cnt;
    }
    while (m--) {
        cin >> id >> grade;
        int pos = strToNum[id] - 1;
        if (pos >= 0) stu[pos].gm = grade;
    }
    while (n--) {
        cin >> id >> grade;
        int pos = strToNum[id] - 1;
        if (pos < 0) continue;
        stu[pos].gf = grade;
        stu[pos].g = grade >= stu[pos].gm ? grade : round(stu[pos].gm * 0.4 + stu[pos].gf * 0.6);
    }
    sort(stu.begin(), stu.end(), cmp);
    for (auto it : stu) {
        if (it.g < 60) continue;
        printf("%s %d %d %d %d\n", it.id.c_str(), it.gp, it.gm, it.gf, it.g);
    }
    return 0;
}