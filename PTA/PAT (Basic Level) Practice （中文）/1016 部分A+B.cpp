// https://pintia.cn/problem-sets/994805260223102976/problems/994805306310115328
#include <stdio.h>
int main() {
    long long a, b, pa = 0, pb = 0;
    int da, db;
    scanf("%ld%d%ld%d", &a, &da, &b, &db);
    for (; a != 0; a /= 10) if (a % 10 == da) pa = pa * 10 + da;
    for (; b != 0; b /= 10) if (b % 10 == db) pb = pb * 10 + db;
    printf("%d", pa + pb);
    return 0;
}

/*
a, da, b, db = input().split()
ta = 0 if a.count(da) == 0 else int(a.count(da) * '1')
tb = 0 if b.count(db) == 0 else int(b.count(db) * '1')
print(ta * int(da) + tb * int(db))
*/