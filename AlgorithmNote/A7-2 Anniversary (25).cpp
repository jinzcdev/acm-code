#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<string, bool> hashMap;
vector<string> guest, ans;

bool cmp(string a, string b){
    return a.substr(6, 8) < b.substr(6, 8);
}

int main(){
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++){
        string alumni;
        cin >> alumni;
        guest.push_back(alumni);
        hashMap[alumni] = true;
    }
    cin >> m;
    for (int i = 0; i < m; i++){
        string alumni;
        cin >> alumni;
        if (hashMap[alumni] == true) {
            ans.push_back(alumni);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    if (ans.size() != 0)
        cout << ans.size() << endl << ans[0] << endl;
    else {
        // sort(guest.begin(), guest.end(), cmp);
        int oldest = 0;
        for (int i = 0; i < guest.size(); i++){
            if (guest[i].substr(6, 8) < guest[oldest].substr(6, 8)) {
                oldest = i;
            }
        }
        cout << "0" << endl << guest[oldest] << endl;
    }
    return 0;
}