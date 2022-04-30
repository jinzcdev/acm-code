#include <bits/stdc++.h>
using namespace std;
bool isprime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}
int main() {
    string s;
    cin >> s;
    bool flag = true;
    while (s.length() != 0) {
        int x = stoi(s);
        if (isprime(x)) {
            cout << s << " " << "Yes" << endl;
        } else {
            cout << s << " " << "No" << endl;
            flag = false;
        }
        s.erase(s.begin());
    }
    if (flag) printf("All Prime!");
    return 0;
}