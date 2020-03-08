// https://pintia.cn/problem-sets/994805342720868352/problems/994805387268571136
#include <bits/stdc++.h>
using namespace std;
struct node {
    int id, ge, gi, gf, sch[5];
};
bool cmp(node &a, node &b) { return a.gf != b.gf ? a.gf > b.gf : a.ge > b.ge; }
int main() {
    int n, m, k, temp;
    scanf("%d%d%d", &n, &m, &k);
    vector<node> stu(n);
    vector<int> quota(m), sch[m];
    for (int i = 0; i < m; i++) scanf("%d", &quota[i]);
    for (int i = 0; i < n; i++) {
        stu[i].id = i;
        scanf("%d%d", &stu[i].ge, &stu[i].gi);
        for (int j = 0; j < k; j++) scanf("%d", &stu[i].sch[j]);
        stu[i].gf = stu[i].ge + stu[i].gi;
    }
    sort(stu.begin(), stu.end(), cmp);
    for (int i = 0; i < n; i++) {
        int stuId = stu[i].id;
        for (int j = 0; j < k; j++) {
            int schId = stu[i].sch[j], lastId = -1;
            if (sch[schId].size() != 0) lastId = *(sch[schId].end() - 1);
            if (sch[schId].size() < quota[schId] ||
                (stu[i].gf == stu[lastId].gf && stu[i].ge == stu[lastId].ge)) {
                sch[schId].push_back(i);
                break;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        vector<int> ans;
        for (auto it : sch[i]) ans.push_back(stu[it].id);
        sort(ans.begin(), ans.end());
        for (int j = 0; j < ans.size(); j++) {
            if (j != 0) printf(" ");
            printf("%d", ans[j]);
        }
        printf("\n");
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
struct node {
    int id, ge, gi, gf, choice[5];
};
bool cmp(node a, node b) { return a.gf != b.gf ? a.gf > b.gf : a.ge > b.ge; }
int main() {
    int n, k, m, quota[110] = {0}, temp;
    scanf("%d%d%d", &n, &k, &m);
    vector<node> stu(n);
    vector<int> ans[110];
    for (int i = 0; i < k; i++) scanf("%d", &quota[i]);
    for (int i = 0; i < n; i++) {
        stu[i].id = i;
        scanf("%d%d", &stu[i].ge, &stu[i].gi);
        for (int j = 0; j < m; j++) scanf("%d", &stu[i].choice[j]);
        stu[i].gf = stu[i].ge + stu[i].gi;
    }
    sort(stu.begin(), stu.end(), cmp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int stuId = stu[i].id, schId = stu[i].choice[j];
            int lastStuId = ans[schId].size() - 1;
            if (ans[schId].size() < quota[schId] ||
                (stu[ans[schId][lastStuId]].gf == stu[stuId].gf &&
                 stu[ans[schId][lastStuId]].ge == stu[stuId].ge)) {
                ans[schId].push_back(stu[i].id);
                break;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        sort(ans[i].begin(), ans[i].end());
        for (int j = 0; j < ans[i].size(); j++) {
            if (j != 0) printf(" ");
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/

/*
11 6 3
2 1 1 2 2 3
80 70 0 1 2
50 10 2 4 5
20 90 0 2 4
90 50 1 1 0
20 90 5 1 3
80 90 1 0 2
60 80 0 1 2
80 80 0 1 2
80 70 1 3 2
70 80 1 2 3
90 30 0 2 3

3 3 2
1 1 1
60 90 0 1
80 90 0 2
70 80 1 2

*/