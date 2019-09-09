// https://pintia.cn/problem-sets/994805260223102976/problems/994805266007048192
#include <iostream>
using namespace std;
int main(){
    string password, userIn;
    int n, cnt = 0;
    cin >> password >> n;
    getchar();      // 避免getline接收回车
    while (getline(cin, userIn)) {
        if (userIn == "#" || ++cnt > n) break;
        if (password == userIn) {
            cout << "Welcome in";
            break;
        } else {
            cout << "Wrong password: " << userIn << endl;
            if (cnt == n) {
                cout << "Account locked" << endl;
                break;
            }
        }
    }
    return 0;
}


/*
Correct%pw 3
correct%pw
Correct@PW
whatisthepassword!
#

cool@gplt 3
coolman@gplt
coollady@gplt
cool@gplt
try again
#
*/