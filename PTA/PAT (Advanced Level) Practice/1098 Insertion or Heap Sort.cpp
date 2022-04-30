// https://pintia.cn/problem-sets/994805342720868352/problems/994805368847187968
#include <bits/stdc++.h>
using namespace std;
void downAdjust(vector<int> &heap, int low, int high) {
    for (int i = low, j = i * 2; j <= high; i = j, j *= 2) {
        if (j + 1 <= high && heap[j + 1] > heap[j]) j++;
        if (heap[i] >= heap[j]) break;
        swap(heap[i], heap[j]);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    vector<int> origin(n + 1), v(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &origin[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    int i = 2, j;
    while (i <= n && v[i - 1] <= v[i]) j = ++i;
    while (i <= n && v[i] == origin[i]) i++;
    if (i == n + 1) {
        printf("Insertion Sort\n");
        sort(v.begin() + 1, v.begin() + j + 1);
    } else {
        printf("Heap Sort\n");
        int pos = n;
        while (pos >= 1 && v[pos] >= v[1]) pos--;
        swap(v[1], v[pos]);
        downAdjust(v, 1, pos - 1);
    }
    printf("%d", v[1]);
    for (int k = 2; k <= n; k++) printf(" %d", v[k]);
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> origin, v;
void downAdjust(int low, int high) {
    int i = low, j = i * 2;
    while (j <= high) {
        if (j + 1 <= high && origin[j + 1] > origin[j]) j++;
        if (origin[i] < origin[j]) {
            swap(origin[i], origin[j]);
            i = j;
            j = i * 2;
        } else {
            break;
        }
    }
}
void createHeap() {
    for (int i = n / 2; i >= 1; i--) {
        downAdjust(i, n);
    }
}
int main() {
    cin >> n;
    origin.resize(n + 1);
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &origin[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    int i = 2, j;
    while (i <= n && v[i - 1] <= v[i]) j = ++i;
    while (i <= n && v[i] == origin[i]) i++;
    if (i == n + 1) {
        printf("Insertion Sort\n");
        sort(origin.begin() + 1, origin.begin() + j + 1);
    } else {
        printf("Heap Sort\n");
        createHeap();
        bool flag = false;
        for (int k = n; k > 1; k--) {
            swap(origin[k], origin[1]);
            downAdjust(1, k - 1);
            if (flag == true) break;
            flag = true;
            for (int l = 1; l <= n; l++) {
                if (origin[l] != v[l]) {
                    flag = false;
                    break;
                }
            }
        }
    }
    for (int l = 1; l <= n; l++) {
        if (l != 1) printf(" ");
        printf("%d", origin[l]);
    }
    return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> origin, v;
void downAdjust(int low, int high) {
    int i = low, j = i * 2;
    while (j <= high) {
        if (j + 1 <= high && v[j + 1] > v[j]) j++;
        if (v[i] >= v[j]) break;
        swap(v[i], v[j]);
        i = j;
        j = i * 2;
    }
}
int main() {
    cin >> n;
    origin.resize(n + 1);
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) scanf("%d", &origin[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    int i = 2, j;
    while (i <= n && v[i - 1] <= v[i]) j = ++i;
    while (i <= n && v[i] == origin[i]) i++;
    if (i == n + 1) {
        printf("Insertion Sort\n");
        sort(v.begin() + 1, v.begin() + j + 1);
    } else {
        printf("Heap Sort\n");
        int pos = n;
        while (pos > 2 && v[pos] >= v[1]) pos--;
        swap(v[pos], v[1]);
        downAdjust(1, pos - 1);
    }
    for (int l = 1; l <= n; l++) {
        if (l != 1) printf(" ");
        printf("%d", v[l]);
    }
    return 0;
}*/
/*#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 110;
int n, origin[maxn], temp[maxn], changed[maxn];

bool isSame(int *a, int *b) {
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

void printArray(int *a) {
    for (int i = 1; i <= n; i++) {
        if (i != 1) printf(" ");
        printf("%d", a[i]);
    }
}

void downAdjust(int low, int high) {
    int i = low, j = i * 2;
    while (j <= high) {
        if (j + 1 <= high && temp[j + 1] > temp[j]) {
            j = j + 1;
        }
        if (temp[j] > temp[i]) {
            swap(temp[j], temp[i]);
            i = j;
            j = i * 2;
        } else {
            break;
        }
    }
}

bool insertSort() {
    bool flag = false;
    for (int i = 2; i <= n; i++) {
        if (i != 2 && isSame(temp, changed)) {
            flag = true;
        }
        sort(temp, temp + i + 1);
        if (flag) {
            return true;
        }
    }
    return false;
}

void heapSort() {
    bool flag = false;
    for (int i = n / 2; i >= 1; i--) {
        downAdjust(i, n);
    }
    for (int i = n; i > 1; i--) {
        if (i != n && isSame(temp, changed)) {
            flag = true;
        }
        swap(temp[i], temp[1]);
        downAdjust(1, i - 1);
        if (flag == true) {
            printArray(temp);
            return;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", origin + i);
        temp[i] = origin[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", changed + i);
    }
    if (insertSort()) {
        printf("Insertion Sort\n");
        printArray(temp);
    } else {
        printf("Heap Sort\n");
        for (int i = 1; i <= n; i++) {
            temp[i] = origin[i];
        }
        heapSort();
    }
    return 0;
}
*/