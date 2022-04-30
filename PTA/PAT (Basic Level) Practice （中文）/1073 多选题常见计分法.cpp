// https://pintia.cn/problem-sets/994805260223102976/problems/994805263624683520
#include <bits/stdc++.h>
using namespace std;
struct node { int pid, opt; };
bool cmp(node a, node b) {
    return a.pid != b.pid ? a.pid < b.pid : a.opt < b.opt;
}
int main() {
    int n, m, hash[5] = {1, 2, 4, 8, 16};
    scanf("%d%d", &n, &m);
    vector<int> fullscore(m), optans(m, 0);
    vector<vector<int>> wrong(m, vector<int>(5, 0));
    int numopt, numtrue;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &fullscore[i], &numopt, &numtrue);
        char ch;
        for (int j = 0; j < numtrue; j++) {
            scanf(" %c", &ch);
            optans[i] += hash[ch - 'a'];
        }
    }
    int maxCnt = -1;
    vector<node> ans;
    for (int i = 0; i < n; i++) {
        getchar();
        double score = 0.0;
        for (int j = 0; j < m; j++) {
            scanf("(%d", &numopt);
            char ch;
            int opt = 0;
            while (numopt--) {
                scanf(" %c", &ch);
                opt += hash[ch - 'a'];
            }
            if (opt ^ optans[j]) {
                if ((opt | optans[j]) == optans[j])
                    score += fullscore[j] * 1.0 / 2;
                for (int k = 0; k < 5; k++) {
                    if ((opt ^ optans[j]) & hash[k]) {
                        wrong[j][k]++;
                        if (wrong[j][k] > maxCnt) {
                            maxCnt = wrong[j][k];
                            ans.clear();
                            ans.push_back({j, k});
                        } else if (wrong[j][k] == maxCnt) {
                            ans.push_back({j, k});
                        }
                    }
                }
            } else {
                score += fullscore[j];
            }
            if (j < m - 1) scanf(") ");
            else scanf(")");
        }
        printf("%.1f\n", score);
    }
    if (ans.size() == 0) {
        printf("Too simple");
    } else {
        sort(ans.begin(), ans.end(), cmp);
        for (int i = 0; i < ans.size(); i++) {
            printf("%d %d-%c\n", maxCnt, ans[i].pid + 1, ans[i].opt + 'a');
        }
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
struct node {
    int fullscore, num, rnum, ans[5] = {0}, cntWrong = 0, wrong[5] = {0};
};
int maxWrongCount = -1;
vector<pair<int, char>> ans;
bool cmp(pair<int, char> a, pair<int, char> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}
void check(vector<node> &q, int qid, int opt) {
    q[qid].wrong[opt]++;
    if (q[qid].wrong[opt] > maxWrongCount) {
        maxWrongCount = q[qid].wrong[opt];
        ans.clear();
        ans.push_back(pair<int, char>(qid, opt + 'a'));
    } else if (q[qid].wrong[opt] == maxWrongCount) {
        ans.push_back(pair<int, char>(qid, opt + 'a'));
    }
}
int main() {
    int n, m, num;
    scanf("%d%d", &n, &m);
    vector<node> q(m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &q[i].fullscore, &q[i].num, &q[i].rnum);
        char ch;
        for (int j = 0; j < q[i].rnum; j++) {
            scanf(" %c", &ch);
            q[i].ans[ch - 'a'] = 1;
        }
    }
    bool hasWrong = false;
    for (int i = 0; i < n; i++) {
        getchar();
        char ch;
        double score = 0.0;
        for (int j = 0; j < m; j++) {
            int cntRight = 0, isWrong = 0;
            vector<int> notchoosed(q[j].ans, q[j].ans + 5);
            scanf("(%d", &num);
            while (num--) {
                scanf(" %c", &ch);
                if (q[j].ans[ch - 'a'] == 0) {
                    check(q, j, ch - 'a');
                    isWrong = 1;
                } else {
                    cntRight++;
                    notchoosed[ch - 'a'] = 0;
                }
            }
            for (int i = 0; i < notchoosed.size(); i++)
                if (notchoosed[i] == 1) check(q, j, i);
            if (num <= q[j].rnum && !isWrong) {
                if (cntRight == q[j].rnum) score += q[j].fullscore;
                else score += q[j].fullscore * 1.0 / 2;
            }
            if (j < m - 1) scanf(") ");
            else scanf(")");
        }
        printf("%.1f\n", score);
    }
    if (ans.size() == 0) {
        printf("Too simple\n");
    } else {
        sort(ans.begin(), ans.end(), cmp);
        for (int i = 0; i < ans.size(); i++) {
            printf("%d %d-%c\n", maxWrongCount, ans[i].first + 1, ans[i].second);
        }
    }
    return 0;
}
*/