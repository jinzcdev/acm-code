// https://pintia.cn/problem-sets/1146683407522816000/problems/1192048712459005952
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1010;
int main() {
    int n, b[N], id, hh, mm;
    char op;
    scanf("%d", &n);
    memset(b, -1, sizeof(b));
    int cnt = 0, time = 0, day = 0;
    while (scanf("%d %c %d:%d", &id, &op, &hh, &mm) != EOF) {
        if (id == 0) {
            if (cnt == 0)
                printf("0 0\n");
            else
                printf("%d %.0f\n", cnt, time * 1. / cnt);
            cnt = time = 0;
            memset(b, -1, sizeof(b));
            if (++day == n) break;
        } else {
            if (op == 'S') {
                b[id] = hh * 60 + mm;
            } else if (op == 'E' && b[id] != -1) {
                cnt++;
                time += (hh * 60 + mm - b[id]);
                b[id] = -1;
            }
        }
    }
    return 0;
}