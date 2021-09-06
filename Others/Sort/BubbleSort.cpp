#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> &a) {
    for (int i = 0; i < a.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}
void BubbleSort(vector<int> &a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    BubbleSort(a, n);
    print(a);
    return 0;
}