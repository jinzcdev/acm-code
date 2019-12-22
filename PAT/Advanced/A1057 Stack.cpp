// https://pintia.cn/problem-sets/994805342720868352/problems/994805417945710592
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 100010;
void insertion_sort(vector<int> &arr) {
    for (vector<int>::iterator it = arr.begin() + 1; it != arr.end(); it++) {
        int key = *it;
        vector<int>::iterator j = it - 1;
        while ((j >= arr.begin()) && (key < *j)) {
            *(j + 1) = *j;
            j--;
        }
        *(j + 1) = key;
    }
}
int main() {
    int n, key, s[maxn], top = -1;
    string op;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> op;
        if (op == "Pop") {
            if (top == -1)
                printf("Invalid\n");
            else {
                vector<int>::iterator pos = find(v.begin(), v.end(), s[top]);
                if (pos != v.end()) v.erase(pos);
                printf("%d\n", s[top--]);
            }
        } else if (op == "Push") {
            scanf("%d", &s[++top]);
            v.push_back(s[top]);
        } else {
            if (top == -1)
                printf("Invalid\n");
            else {
                // int arr[top + 1];
                // memcpy(arr, s, (top + 1) * sizeof(int));
                // sort(arr, arr + top + 1);
                insertion_sort(v);
                // printf("%d\n", arr[top / 2]);
                printf("%d\n", v[top / 2]);
            }
        }
    }
    return 0;
}