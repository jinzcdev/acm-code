// https://pintia.cn/problem-sets/994805342720868352/problems/994805344222429184
#include <bits/stdc++.h>
using namespace std;
struct node {
    string school;
    int cntMember = 0;
    double score = 0.0;
} s[100010];
bool cmp(node a, node b) {
    if ((int)a.score != (int)b.score) return (int)a.score > (int)b.score;
    else if (a.cntMember != b.cntMember) return a.cntMember < b.cntMember;
    return a.school < b.school;
}
void toLower(string &s) {
    for (int i = 0; i < s.length(); i++)
        if (isupper(s[i])) s[i] = s[i] + 32;
}
int main() {
    int n, score, cnt = 1;
    string id, school;
    unordered_map<string, int> mp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> id >> score >> school;
        toLower(school);
        int sid = mp[school];
        if (sid == 0) {
            mp[school] = cnt++;
            sid = mp[school];
            s[sid].school = school;
        }
        s[sid].cntMember++;
        if (id[0] == 'A') s[sid].score += score;
        else if (id[0] == 'B') s[sid].score += score / 1.5;
        else s[sid].score += score * 1.5;
    }
    sort(s + 1, s + cnt, cmp);
    printf("%d\n", cnt - 1);
    int tscore = (int)s[1].score, r = 1;
    for (int i = 1; i < cnt; i++) {
        if ((int)s[i].score != tscore) {
            r = i;
            tscore = s[i].score;
        }
        printf("%d %s %d %d\n", r, s[i].school.c_str(), (int)s[i].score, s[i].cntMember);
    }
    return 0;
}