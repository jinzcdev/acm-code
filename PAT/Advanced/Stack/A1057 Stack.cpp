// https://pintia.cn/problem-sets/994805342720868352/problems/994805417945710592
#include <cstdio>
#include <cstring>
#include <set>
#include <stack>
using namespace std;
set<int> num;
stack<int> s;
int main(){
    char cmd[15];
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%s", cmd);
        if (strcmp(cmd, "Pop") == 0) {
            if (s.empty()) printf("Invalid\n");
            else {
                printf("%d\n", s.top());
                num.erase(s.top());
                s.pop();
            }
        } else if (strcmp(cmd, "Push") == 0) {
            scanf("%d", &x);
            num.insert(x);
            s.push(x);
        } else {
            if (s.size() == 0) printf("Invalid\n");
            else {
                int mid = 0, size = (int)num.size(), index;
                if (size % 2 == 0) index = size / 2;
                else index = (size + 1) / 2;
                set<int>::iterator it = num.begin();
                while (it != num.end() && mid++ < index - 1) {
                    it++;
                }
                printf("%d\n", *it);
            }
        }
    }
    return 0;
}