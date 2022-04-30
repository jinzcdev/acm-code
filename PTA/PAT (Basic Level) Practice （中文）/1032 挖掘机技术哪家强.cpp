// https://pintia.cn/problem-sets/994805260223102976/problems/994805289432236032
#include <cstdio>
int arr[100000];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int index, value;
        scanf("%d %d", &index, &value);
        arr[index] += value;
    }
    int n_max, max = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            n_max = i;
        }
    }
    printf("%d %d", n_max, max);
    return 0;
}