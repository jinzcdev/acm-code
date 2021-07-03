/*
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m, post[35], in[35], father[N], lchild[N], rchild[N], depth[N] = {0};
bool isfull = true;
int solve(int postl, int postr, int inl, int inr, int d) {
    if (postl > postr) return -1;
    int root = post[postr], k = inl;
    while (k <= inr && in[k] != post[postr]) k++;
    int numleft = k - inl;
    int left = solve(postl, postl + numleft - 1, inl, k - 1, d + 1);
    int right = solve(postl + numleft, postr - 1, k + 1, inr, d + 1);
    if (left != -1) {
        father[left] = root;
        lchild[root] = left;
    }
    if (right != -1) {
        father[right] = root;
        rchild[root] = right;
    }
    if (left * right < 0) isfull = false;
    depth[root] = d;
    return root;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    int root = solve(0, n - 1, 0, n - 1, 1);
    scanf("%d", &m);
    getchar();
    while (m--) {
        int a, b;
        string s;
        getline(cin, s);
        if (s[0] == 'I') {
            printf("%s\n", isfull ? "Yes" : "No");
            continue;
        }
        if (s[s.length() - 1] == 't') {
            int i = 0;
            while (isdigit(s[i])) i++;
            printf("%s\n", stoi(s.substr(0, i)) == root ? "Yes" : "No");
            continue;
        }
        if (isalpha(s[s.length() - 1])) {
            int i = 0, j;
            while (isdigit(s[i])) i++;
            a = stoi(s.substr(0, i));
            i += 5;
            j = i;
            while (isdigit(s[j])) j++;
            b = stoi(s.substr(i, j - i + 1));
            if (s[s.length() - 1] == 's') {
                printf("%s\n", father[a] == father[b] ? "Yes" : "No");
            } else {
                printf("%s\n", depth[a] == depth[b] ? "Yes" : "No");
            }
            continue;
        }
        int i = 0, j = s.length() - 1;
        while (isdigit(s[i])) i++;
        while (isdigit(s[j])) j--;
        a = stoi(s.substr(0, i));
        b = stoi(s.substr(j + 1));
        if (s.find('p') != string::npos) {
            printf("%s\n", father[b] == a ? "Yes" : "No");
        } else if (s.find("le") != string::npos) {
            printf("%s\n", lchild[b] == a ? "Yes" : "No");
        } else {
            printf("%s\n", rchild[b] == a ? "Yes" : "No");
        }
    }
    return 0;
}
*/

/////////////////

/*
#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int father[N];
int findFather(int x) {
    return x == father[x] ? x : father[x] = findFather(father[x]);
}
void uni(int a, int b) {
    int faA = findFather(a), faB = findFather(b);
    if (faA < faB)
        father[faB] = faA;
    else if (faA > faB)
        father[faA] = faB;
}
int main() {
    for (int i = 0; i < N; i++) father[i] = i;
    int n, k, m, record[N][N] = {0}, caller, receiver, d;
    scanf("%d%d%d", &k, &n, &m);
    while (m--) {
        scanf("%d%d%d", &caller, &receiver, &d);
        record[caller][receiver] += d;
    }
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        int cntShort = 0, cntCallBack = 0;
        for (int j = 1; j <= n; j++) {
            if (record[i][j] > 0 && record[i][j] <= 5) {
                cntShort++;
                if (record[j][i] != 0) cntCallBack++;
            }
        }
        if (cntShort > k && cntCallBack * 1.0 / cntShort <= 0.2) {
            v.push_back(i);
        }
    }
    if (v.size() == 0) {
        printf("None");
        return 0;
    }
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = j + 1; j < v.size(); j++) {
            if (record[v[i]][v[j]] != 0 && record[v[j]][v[i]] != 0) {
                uni(v[i], v[j]);
            }
        }
    }
    map<int, set<int> > mp;
    for (int i = 0; i < v.size(); i++) {
        mp[findFather(v[i])].insert(v[i]);
    }
    for (auto itt : mp) {
        set<int> s = move(itt.second);
        for (auto it = s.begin(); it != s.end(); it++) {
            if (it != s.begin()) printf(" ");
            printf("%d", *it);
        }
        printf("\n");
    }
    return 0;
}
*/