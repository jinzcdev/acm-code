#include <iostream>
using namespace std;
int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    string name, minName, maxName, birth, minBirth = "9999/99/99", maxBirth = "0000/00/00";
    while (n--) {
        cin >> name >> birth;
        if (birth >= "1814/09/06" && birth <= "2014/09/06") {
            cnt++;
            if (birth <= minBirth) {
                minBirth = birth;
                minName = name;
            }
            if (birth >= maxBirth) {
                maxBirth = birth;
                maxName = name;
            }
        }
    }
    if (cnt == 0) {
        printf("0");
        return 0;
    }
    cout << cnt << " " << minName << " " << maxName << endl;
    return 0;   
}