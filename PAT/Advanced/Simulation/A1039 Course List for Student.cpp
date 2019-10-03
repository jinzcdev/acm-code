// https://pintia.cn/problem-sets/994805342720868352/problems/994805447855292416
#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    int n, k, course, m;
    map<string, set<int> > ans;
    string stu;
    scanf("%d%d", &n, &k);
    while (k--) {
        scanf("%d%d", &course, &m);
        while (m--) {
            cin >> stu;
            ans[stu].insert(course);
        }
    }
    while (n--) {
        cin >> stu;
        cout << stu << " " << ans[stu].size();
        for (auto it : ans[stu]) {
            printf(" %d", it);
        }
        printf("\n");
    }
    return 0;
}