#include <bits/stdc++.h>
using namespace std;
int post[35], in[35], numlevel = 1;
bool isfull = true;
map<int, int> father, lchild, rchild, level;
string s;
int create(int postl, int postr, int inl, int inr) {
    if (postl > postr) return 0;
    int root = post[postr];
    int k = inl;
    while (in[k] != post[postr]) k++;
    int numleft = k - inl;
    int left = create(postl, postl + numleft - 1, inl, k - 1);
    int right = create(postl + numleft, postr - 1, k + 1, inr);
    if ((left == 0 && right != 0) || (left != 0 && right == 0)) isfull = false;
    father[left] = father[right] = root;
    lchild[root] = left;
    rchild[root] = right;
    level[left] = level[right] = numlevel++;
    return root;
}
bool find(string val) { return s.find(val) != string::npos; }
int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    scanf("%d", &m);
    getchar();
    int root = create(0, n - 1, 0, n - 1);
    while (m--) {
        getline(cin, s);
        bool ans;
        if (!isdigit(s[0])) {
            ans = isfull;
        } else {
            int a, i = 0;
            while (isdigit(s[i])) i++;
            a = stoi(s.substr(0, i));
            if (s.substr(s.length() - 4) == "root") {
                ans = (root == a);
            } else if (s.find("of") != string::npos) {
                int start = s.length() - 1;
                while (isdigit(s[start])) start--;
                int b = stoi(s.substr(++start));
                if (find("pare")) ans = (father[b] == a);
                else if (find("left")) ans = (lchild[b] == a);
                else if (find("right")) ans = (rchild[b] == a);
            } else {
                while (!isdigit(s[i])) i++;
                int left = i;
                while (isdigit(s[i])) i++;
                int b = stoi(s.substr(left, i - left + 1));
                if (find("sib")) ans = (father[a] == father[b]);
                else ans = (level[a] == level[b]);
            }
        }
        printf("%s\n", ans ? "Yes" : "No");
    }
    return 0;
}