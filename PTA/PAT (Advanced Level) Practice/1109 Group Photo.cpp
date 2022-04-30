// https://pintia.cn/problem-sets/994805342720868352/problems/994805360043343872
// 39分钟, 可遍历人数列表, 分别取每行人数计算
#include <bits/stdc++.h>
using namespace std;
struct node {
    string name;
    int height;
};
bool cmp(node a, node b) {
    return a.height != b.height ? a.height > b.height : a.name < b.name;
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int colnum = n / k;
    vector<node> stu(n);
    for (int i = 0; i < n; i++) cin >> stu[i].name >> stu[i].height;
    sort(stu.begin(), stu.end(), cmp);
    int len = n % k == 0 ? colnum : colnum + n % k, id = 0;
    for (int i = 0; i < k; i++) {
        vector<node> row(len);
        int pos = len / 2, d = 0;
        int flag = 1;
        for (int j = 0; j < len; j++) {
            pos += d++ * flag;
            row[pos] = stu[id++];
            flag = -flag;
        }
        for (int k = 0; k < row.size(); k++) {
            if (k != 0) printf(" ");
            cout << row[k].name;
        }
        printf("\n");
        len = colnum;
    }
    return 0;
}

/*
// https://pintia.cn/problem-sets/994805260223102976/problems/994805272021680128
#include <bits/stdc++.h>
using namespace std;
struct node {
    string name;
    int height;
};
bool cmp(node a, node b) {
    return a.height != b.height ? a.height > b.height : a.name < b.name;
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<node> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].name >> v[i].height;
    sort(v.begin(), v.end(), cmp);
    int num = n / k, numLastRow = n % k != 0 ? num + n % k : num;
    int i = 0;
    while (i < n) {
        int len = (i != 0 ? num : numLastRow), pos = len / 2;
        vector<node> ans(len);
        bool flag = true;
        int d = 0;
        for (int j = 0; j < len; j++) {
            flag ? pos += d++ : pos -= d++;
            ans[pos] = v[i + j];
            flag = !flag;
        }
        for (int k = 0; k < ans.size(); k++) {
            if (k != 0) printf(" ");
            cout << ans[k].name;
        }
        printf("\n");
        i += len;
    }
    return 0;
}
*/