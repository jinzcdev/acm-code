// https://pintia.cn/problem-sets/994805342720868352/problems/994805367156883456
#include <iostream>
#include <string>
#include <map>
using namespace std;
string marsL[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string marsH[13] = {"###", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> mp;

int main(){
    for (int i = 0; i < 13; i++){
        mp[marsL[i]] = i;
        mp[marsH[i]] = i * 13;
    }
    int n;
    cin >> n;
    string str;
    getchar();
    for (int i = 0; i < n; i++){
        getline(cin, str);
        int len = str.length();
        if (str[0] >= '0' && str[0] <= '9'){
            int num = stoi(str);
            if (num < 13){
                cout << marsL[num] << endl;
            } else if (num % 13 == 0){
                cout << marsH[num / 13] << endl;
            } else {
                cout << marsH[num / 13] << " " << marsL[num % 13] << endl;
            }
        } else {
            string s1 = str.substr(0, 3), s2;
            int ans = mp[s1];
            if (str.length() > 4){
                ans += mp[str.substr(4, 3)];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}