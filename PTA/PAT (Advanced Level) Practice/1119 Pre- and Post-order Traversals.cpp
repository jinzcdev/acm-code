// https://pintia.cn/problem-sets/994805342720868352/problems/994805353470869504
#include <bits/stdc++.h>
using namespace std;
const int N = 35;
int pre[N], post[N], n;
vector<int> ansIn;
bool isunique = true;
void create(int prel, int prer, int postl, int postr) {
    if (prel > prer) return;
    if (prel == prer) {
        ansIn.push_back(pre[prel]);
        return;
    }
    int k = postl;
    while (post[k] != pre[prel + 1]) k++;
    int numRight = postr - k - 1;
    if (numRight == 0) isunique = false;
    create(prel + 1, prer - numRight, postl, k);
    ansIn.push_back(pre[prel]);
    create(prer - numRight + 1, prer, k + 1, postr - 1);
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    create(0, n - 1, 0, n - 1);
    printf("%s\n", isunique ? "Yes" : "No");
    for (int i = 0; i < ansIn.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", ansIn[i]);
    }
    printf("\n");
    return 0;
}