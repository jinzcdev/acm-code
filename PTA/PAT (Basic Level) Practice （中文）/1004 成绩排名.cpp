// https://pintia.cn/problem-sets/994805260223102976/problems/994805321640296448
#include <bits/stdc++.h>
using namespace std;
int main() {
    string name, nameH, nameL, id, idH, idL;
    int n, grade, Min = 999, Max = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> id >> grade;
        if (grade > Max) {
            Max = grade;
            nameH = name;
            idH = id;
        }
        if (grade < Min) {
            Min = grade;
            nameL = name;
            idL = id;
        }
    }
    cout << nameH << " " << idH << endl;
    cout << nameL << " " << idL << endl;
    return 0;
}