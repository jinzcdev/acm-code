#include <bits/stdc++.h>
using namespace std;
// int call[1010][1010] = {0};
const int INF = 0x3f3f3f3f;
const int N = 1010;
int father[N];
int k, n, m, caller, receiver, duration;
void init() {
    for (int i = 0; i < n; i++) {
        father[i] = i;
    }
}
int findFather(int x) {
    if (x == father[x]) return x;
    int fa = findFather(father[x]);
    father[x] = fa;
    return fa;
}
void uni(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) father[faA] = faB;
}
int main() {
    scanf("%d%d%d", &k, &n, &m);
    vector<map<int, int> > call(n + 1);
    while (m--) {
        scanf("%d%d%d", &caller, &receiver, &duration);
        call[caller][receiver] += duration;
    }
    vector<int> suspect;
    for (int i = 1; i <= n; i++) {
        int callto = 0, callback = 0;
        for (auto it : call[i]) {
            if (it.second <= 5) {
                callto++;
                if (call[it.first][i] != 0) callback++;
            }
        }
        if (callto <= k) continue;
        if (callback / callto * 1.0 <= 0.2) suspect.push_back(i);
    }
    for (int i = 1; i <= suspect.size(); i++) {
        father[i] = i;
    }
    sort(suspect.begin(), suspect.end());
    int pos = 1;
    map<int, int> numtoid, idtonum;
    for (int i = 0; i < suspect.size() - 1; i++) {
        int a = idtonum[suspect[i]], b = idtonum[suspect[i + 1]];
        if (a == 0) {
            idtonum[suspect[i]] = pos;
            numtoid[pos] = suspect[i];
            a = pos++;
        }
        if (b == 0) {
            idtonum[suspect[i + 1]] = pos;
            numtoid[pos] = suspect[i + 1];
            b = pos++;
        }
        if (call[suspect[i]][suspect[i + 1]] != 0 &&
            call[suspect[i + 1]][suspect[i]] != 0) {
            uni(a, b);
        }
    }
    map<int, vector<int> > ans;
    for (int i = 1; i < pos; i++) {
        ans[findFather(i)].push_back(numtoid[i]);
    }
    for (auto it : ans) {
        for (int i = 0; i < it.second.size(); i++) {
            if (i != 0) printf(" ");
            printf("%d", it.second[i]);
        }
        printf("\n");
    }
    return 0;
}