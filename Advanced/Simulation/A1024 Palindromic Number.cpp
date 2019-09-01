// https://pintia.cn/problem-sets/994805342720868352/problems/994805476473028608
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100;
int maxStep;

bool isPali(char *number){
    int len = strlen(number), mid = len / 2;
    for (int i = 0; i < mid; i++){
        if (number[i] != number[len - 1 - i]) return false;
    }
    return true;
}

void findPali(char *number, int step){
    bool isP = isPali(number);
    if (isP || step == maxStep) {
        printf("%s\n%d", number, step);
        return;
    }
    char sum[maxn];
    int k = 0, len = strlen(number), cnt = 0;
    for (int i = 0; i < len; i++){
        int temp = (number[i] - '0') + (number[len - 1 - i] - '0') + k;
        sum[cnt++] = temp % 10 + '0';
        k = temp / 10;
    }
    if (k != 0) sum[cnt++] = k + '0';
    sum[cnt] = '\0';
    reverse(sum, sum + cnt);
    findPali(sum, ++step);
}

int main(){
    char number[maxn];
    scanf("%s %d", number, &maxStep);
    findPali(number, 0);
    return 0;
}

/*
#include <iostream>
#include <algorithm>
using namespace std;
string s;
void add(string t) {
    int len = s.length(), carry = 0;
    for(int i = 0; i < len; i++) {
        s[i] = s[i] + t[i] + carry - '0';
        carry = 0;
        if(s[i] > '9') {
            s[i] = s[i] - 10;
            carry = 1;
        }
    }
    if(carry) s += '1';
    reverse(s.begin(), s.end());
}
int main() {
    int cnt, i;
    cin >> s >> cnt;
    for(i = 0; i <= cnt; i++) {
        string t = s;
        reverse(t.begin(), t.end());
        if(s == t || i == cnt) break;
        add(t);
    }
    cout << s << endl << i;
    return 0;
}
*/