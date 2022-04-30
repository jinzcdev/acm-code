// https://pintia.cn/problem-sets/994805342720868352/problems/994805393241260032
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 10010;
struct node {
    int id, score[6], total, cntPass;
    bool shown;      // 记录是否有通过编译的提交
    node() { memset(score, -1, sizeof(score)); }
} stu[maxn];
bool cmp(node a, node b) {
    if (a.total != b.total) return a.total > b.total;
    else if (a.cntPass != b.cntPass) return a.cntPass > b.cntPass;
    else return a.id < b.id;
}
int main() {
    int n, k, m, full[6], id, pid, score;
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= k; i++) cin >> full[i];
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &id, &pid, &score);
        node &s = stu[id];
        if (score == -1 && s.score[pid] == -1) s.score[pid] = 0;
        if (score > s.score[pid]) {
            s.score[pid] = score;
            s.shown = true;
            if (score == full[pid]) s.cntPass++;    // 写在外层if之内保证只计数一次
        }
    }
    vector<node> ans;
    for (int i = 0; i < maxn; i++) {
        if (stu[i].shown == true) {
            int total = 0;
            for (int j = 1; j <= k; j++) {
                if (stu[i].score[j] != -1) total += stu[i].score[j];
            }
            stu[i].total = total;
            stu[i].id = i;
            ans.push_back(stu[i]);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    int r = 1;
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0 && ans[i].total != ans[i - 1].total) r = i + 1;
        printf("%d %05d %d", r, ans[i].id, ans[i].total);
        for (int j = 1; j <= k; j++ ) {
            int score = ans[i].score[j];
            if (score == -1) printf(" -");
            else printf(" %d", score);
        }
        printf("\n");
    }
    return 0;
}