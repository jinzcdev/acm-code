// https://pintia.cn/problem-sets/994805260223102976/problems/994805296180871168
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 100010;
struct node {
    int data, next, ads;
} Node[maxn];
vector<node> L, ans;

int main() {
    int n, k, head, ads;
    scanf("%d%d%d", &head, &n, &k);
    while (n--) {
        scanf("%d", &ads);
        scanf("%d%d", &Node[ads].data, &Node[ads].next);
        Node[ads].ads = ads;
    }
    for (int p = head; p != -1; p = Node[p].next) {
        L.push_back(Node[p]);
    }
    if (k > L.size()) {
        ans = L;
    } else {
        int i = 0;
        while (i < L.size()) {
            if (i + k - 1 < L.size()) {
                for (int j = i + k - 1; j >= i; j--) {
                    ans.push_back(L[j]);
                }
                i += k;
            } else {
                break;
            }
        }
        while (i < L.size()) {
            ans.push_back(L[i++]);
        }
    }
    
    for (int i = 0; i < ans.size() - 1; i++) {
        printf("%05d %d %05d\n", ans[i].ads, ans[i].data, ans[i + 1].ads);
    }
    printf("%05d %d -1\n", ans[ans.size() - 1].ads, ans[ans.size() - 1].data);
    return 0;
}