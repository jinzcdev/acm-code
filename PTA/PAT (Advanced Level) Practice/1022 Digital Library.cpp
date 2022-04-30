// https://pintia.cn/problem-sets/994805342720868352/problems/994805480801550336
#include <bits/stdc++.h>
using namespace std;
unordered_map<string, set<int> > maps[6];
int main() {
    int n, m, k, id;
    string s;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &id);
        getchar();
        for (int i = 1; i <= 5; i++) {
            getline(cin, s);
            if (i != 3) maps[i][s].insert(id);
            else {
                int left = 0;
                for (int j = 1; j < s.length(); j++) {
                    if (s[j] == ' ') {
                        maps[i][s.substr(left, j - left)].insert(id);
                        left = j + 1;
                    }
                }
                maps[i][s.substr(left)].insert(id);
            }
        }
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d: ", &k);
        getline(cin, s);
        printf("%d: %s\n", k, s.c_str());
        if (maps[k].find(s) == maps[k].end()) {
            printf("Not Found\n");
        } else {
            for (auto it : maps[k][s]) printf("%07d\n", it);
        }
    }
    return 0;
}