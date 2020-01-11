// https://pintia.cn/problem-sets/994805260223102976/problems/1071785664454127616
#include <cmath>
#include <iostream>
using namespace std;
int getLen(int number) {
    int cnt = 0;
    while (number != 0) {
        number /= 10;
        cnt++;
    }
    return cnt;
}
int main() {
    int m;
    scanf("%d", &m);
    while (m--) {
        int n = 1, k, rs;
        scanf("%d", &k);
        int product = k * k;
        bool flag = false;
        for ( ; n <= 9; n++) {
            rs = n * product;
            int len = getLen(k), temp = rs % (int)pow(10, len);
            if (temp == k) {
                flag = true;
                break;
            }
        }
        if (flag == true) printf("%d %d\n", n, rs);
        else printf("No\n");
    }
    return 0;
}

/*
#include <iostream>
using namespace std;
int main() {
    int m;
    scanf("%d", &m);
    while (m--) {
        int k;
        bool flag = false;
        scanf("%d", &k);
        for (int n = 1; n <= 9; n++) {
            int product = n * k * k;
            string sk = to_string(k), spt = to_string(product);
            if (spt.substr(spt.length() - sk.length()) == sk) {
                printf("%d %d\n", n, product);
                flag = true;
                break;
            }
        }
        if (flag == false) printf("No\n");
    }
    return 0;
}
*/