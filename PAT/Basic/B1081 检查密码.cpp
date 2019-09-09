// https://pintia.cn/problem-sets/994805260223102976/problems/994805261217153024
#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    string pw;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++){
        getline(cin, pw);
        if (pw.length() >= 6) {
            int invalid = 0, hasAlpha = 0, hasDigit = 0;
            for (int j = 0; j < pw.length(); j++){
                if ((pw[i] >= 'a' && pw[i] <= 'z') 
                || (pw[i] >= 'A' && pw[i] <= 'Z')) hasAlpha = 1;
                else if (pw[i] >= 0 && pw[i] <= 9) hasDigit = 1;
                else if (pw[i] != '.') invalid = 1;
            }
            if (invalid == 1) cout << "Your password is tai luan le.\n";
            else if (!hasAlpha) cout << "Your password needs zi mu.\n";
            else if (!hasDigit) cout << "Your password needs shu zi.\n";
            else cout << "Your password is wan mei.\n";
        } else {
            cout << "Your password is tai duan le.\n";            
        }
    }
    return 0;
}