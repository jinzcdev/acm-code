// https://pintia.cn/problem-sets/994805046380707840/problems/1111914599412858887
#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct node {
    string fn, sn;
    int fid, sex = 0;
} L[N];
bool check(int a, int b) {
    int hash[N] = {0};
    for (int i = 1; a != -1; a = L[a].fid, i++) hash[a] = i;
    for (int i = 1; b != -1; b = L[b].fid, i++) {
        if (hash[b] && (hash[b] < 5 || i < 5)) return false;
        if (i >= 5) return true;
    }
    return true;
}
int main() {
    int n, m;
    unordered_map<string, int> getid;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        cin >> L[i].fn >> L[i].sn;
        string s = L[i].sn;
        if (s[s.length() - 1] == 'f' || s[s.length() - 1] == 'm') {
            if (s[s.length() - 1] == 'f') L[i].sex = 1;
            s.erase(s.end() - 1);
        } else if (s.substr(s.length() - 4) == "sson") {
            s = s.substr(0, s.length() - 4);
        } else {
            s = s.substr(0, s.length() - 7);
            L[i].sex = 1;
        }
        L[i].sn = s;
        getid[L[i].fn] = i;
    }
    for (int i = 1; i <= n; i++) {
        string s = L[i].sn;
        if (getid[s] == 0)
            L[i].fid = -1;
        else
            L[i].fid = getid[s];
    }
    scanf("%d", &m);
    string a, b, c, d;
    while (m--) {
        cin >> a >> b >> c >> d;
        if (getid[a] == 0 || getid[c] == 0)
            printf("NA\n");
        else {
            int ida = getid[a], idb = getid[c];
            if (L[ida].sex == L[idb].sex) printf("Whatever\n");
            else printf("%s\n", check(ida, idb) ? "Yes" : "No");
        }
    }
    return 0;
}