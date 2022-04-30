// https://pintia.cn/problem-sets/994805342720868352/problems/994805417945710592
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010, N = 316;
int block[N] = {0}, table[MAXN] = {0};
stack<int> s;
int PeekMedian(int k) {
    int sum = 0, i = 0;
    while (sum + block[i] < k) sum += block[i++];
    int num = i * N;
    while (sum + table[num] < k) sum += table[num++];
    return num;
}
void Push(int x) {
    s.push(x);
    block[x / N]++;
    table[x]++;
}
void Pop() {
    int top = s.top();
    s.pop();
    block[top / N]--;
    table[top]--;
    printf("%d\n", top);
}
int main() {
    int n, x;
    scanf("%d", &n);
    char cmp[15];
    while (n--) {
        scanf("%s", cmp);
        if (cmp[1] == 'u') {
            scanf("%d", &x);
            Push(x);
        } else {
            if (s.empty()) printf("Invalid\n");
            else if (cmp[1] == 'o') Pop();
            else {
                int len = s.size();
                printf("%d\n", PeekMedian(len % 2 ? (len + 1) / 2 : len / 2));
            }
        }
    }
    return 0;
}