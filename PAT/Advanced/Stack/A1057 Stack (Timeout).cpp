// https://pintia.cn/problem-sets/994805342720868352/problems/994805417945710592
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100010;
int main() {
    int n, key, s[maxn], top = -1;
    string op;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == "Pop") {
            if (top == -1)
                printf("Invalid\n");
            else {
                printf("%d\n", s[top--]);
            }
        } else if (op == "Push") {
            scanf("%d", &s[++top]);
        } else {
            if (top == -1)
                printf("Invalid\n");
            else {
                int arr[top + 1];
                memcpy(arr, s, (top + 1) * sizeof(int));
                sort(arr, arr + top + 1);
                printf("%d\n", arr[top / 2]);
            }
        }
    }
    return 0;
}