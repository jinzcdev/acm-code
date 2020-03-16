// https://pintia.cn/problem-sets/994805342720868352/problems/994805344222429184
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct node {
    string sch;
    int score, t, a, b, num;
} Node[N];
bool cmp(node &a, node &b) {
    if (a.score != b.score) return a.score > b.score;
    else if (a.num != b.num) return a.num < b.num;
    return a.sch < b.sch;
}
int main() {
    int n, score, cnt = 0;
    scanf("%d", &n);
    string uid, sch;
    unordered_map<string, int> schToId;
    for (int i = 0; i < n; i++) {
        cin >> uid >> score >> sch;
        for (int i = 0; i < sch.size(); i++) sch[i] = tolower(sch[i]);
        if (schToId[sch] == 0) {
            schToId[sch] = ++cnt;
            Node[cnt].sch = sch;
        }
        int pos = schToId[sch];
        Node[pos].num++;
        if (uid[0] == 'T') Node[pos].t += score;
        else if (uid[0] == 'A') Node[pos].a += score;
        else Node[pos].b += score;
    }
    for (int i = 1; i <= cnt; i++)
        Node[i].score = (int)(Node[i].t * 1.5 + Node[i].a + Node[i].b / 1.5);
    sort(Node + 1, Node + cnt + 1, cmp);
    printf("%d\n", cnt);
    int rank = 1, pre = Node[1].score;
    for (int i = 1; i <= cnt; i++) {
        if (Node[i].score != pre) {
            rank = i;
            pre = Node[i].score;
        }
        printf("%d %s %d %d\n", rank, Node[i].sch.c_str(), Node[i].score, Node[i].num);
    }
    return 0;
}