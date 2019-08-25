// https://pintia.cn/problem-sets/994805260223102976/problems/994805261217153024
#include <iostream>
#include <string>
using namespace std;
string answer[5] = {
    "Your password is wan mei.",
    "Your password is tai duan le.",
    "Your password is tai luan le.",
    "Your password needs shu zi.",
    "Your password needs zi mu."
};

int main(){
    int n, k = 0;
    string pw;
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++){
        getline(cin, pw);
        if (pw.length() < 6) {
            cout << answer[1];
            continue;
        }
        int len = 0, type;
        for (int j = 0; j < pw.length(); j++){
            if (pw[i] != '.' && !(pw[i] >= 'a' && pw[i] <= 'z') 
            && !(pw[i] >= 'A' && pw[i] <= 'Z')) {
                type = 2;
                break;
            }
        }
        

    }
    
}