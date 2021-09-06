// https://pintia.cn/problem-sets/1259839299727368192/problems/1259850789826048001
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    string s = to_string(a + b);
    for (int i = 0; i < s.length(); i++) printf("%c\n", s[i]);
    return 0;
}