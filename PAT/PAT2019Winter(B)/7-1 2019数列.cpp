// https://pintia.cn/problem-sets/1203317812083417088/problems/1203317880077287424
#include <iostream>
#include <vector>
using namespace std;
vector<int> v(1010);
int getResult(int pos) {
    int rs = 0, cnt = 0;
    while (cnt++ < 4) rs += v[pos - cnt];
    rs = rs % 10;
    v[pos] = rs;
    return rs;
}
int main() {
    int a[] = {2, 0, 1, 9};
    for (int i = 1; i <= 4; i++) v[i] = a[i - 1];
    int n;
    scanf("%d", &n);
    if (n < 5) {
        for (int i = 1; i <= n; i++) {
            printf("%d", v[i]);
        }
    } else {
        printf("2019");
        for (int i = 5; i <= n; i++) {
            printf("%d", getResult(i));
        }
    }
    return 0;
}