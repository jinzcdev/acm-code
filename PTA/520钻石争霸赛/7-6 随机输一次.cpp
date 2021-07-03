// https://pintia.cn/problem-sets/1259839299727368192/problems/1259850789826048003
#include <bits/stdc++.h>
using namespace std;
vector<int> v, temp;
int n, i = 0;
bool iswin() {
    if (v[i] > 0) {
        v[i]--;
        return true;
    } else {
        v[i] = temp[i];
        if (++i == n) i = 0;
        return false;
    }
}
string win(string s) {
    if (s == "ChuiZi") return "Bu";
    return s == "JianDao" ? "ChuiZi" : "JianDao";
}
string lose(string s) {
    if (s == "ChuiZi") return "JianDao";
    return s == "JianDao" ? "Bu" : "ChuiZi";
}
int main() {
    scanf("%d", &n);
    v.resize(n);
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    temp = v;
    string s;
    while (cin >> s, s != "End") {
        if (iswin()) cout << win(s) << endl;
        else cout << lose(s) << endl;
    }
    return 0;
}