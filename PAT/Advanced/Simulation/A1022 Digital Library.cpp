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
            if (i != 3)
                maps[i][s].insert(id);
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
        if (maps[k].find(s) == maps[k].end()) printf("Not Found\n");
        else {
            for (auto it : maps[k][s]) printf("%07d\n", it);
        }
    }
    return 0;
}

/*
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int maxn = 10010;
int n, m;
string books[maxn][6];              // 二维数组表示所有的书本及其相关信息

void search(int index, string data){
    vector<string> ans;
    bool flag = false;
    for (int i = 0; i < n; i++){
        if (index != 3){                    // index为3通过值精确匹配
            if (books[i][index] == data){
                ans.push_back(books[i][0]);
                flag = true;
            }
        } else {                            // index为3时代表keywords,
存在多个值 int begin = 0, end; string keywords = books[i][index]; for (int j =
0; j < keywords.length(); j++){ end = j; if (end == keywords.length() - 1 ||
keywords[end + 1] == ' '){ if (data == keywords.substr(begin, end - begin + 1)){
                        ans.push_back(books[i][0]);
                        flag = true;
                    }
                    begin = j + 2;
                }
            }
        }
    }
    if (!flag){
        printf("Not Found\n");
    } else {
        sort(ans.begin(), ans.end());      //
对本次书本查询结果通过ID进行升序排序 for (int i = 0; i < ans.size(); i++){ cout
<< ans[i] << endl;
        }
    }
}

int main(){
    cin >> n;
    getchar();
    string str;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 6; j++){
            getline(cin, str);
            books[i][j] = str;
        }
    }
    cin >> m;
    int begin;
    getchar();                      // 接收回车换行
    for (int i = 0; i < m; i++){
        getline(cin, str);
        cout << str << endl;
        search(str[0] - '0', str.substr(3, str.length() - 3));
    }
    return 0;
}

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int maxn = 10010;
int n, m;
vector<vector<string> > books;      // 表示所有的书本及其相关信息

bool cmp(vector<string> a, vector<string> b){
    return a[0] < b[0];             // ID较小的书排在前列
}

void search(int index, string data){
    bool flag = false;
    for (int i = 0; i < n; i++){
        if (index != 3){            // index为3通过值精确匹配
            if (books[i][index] == data){
                cout << books[i][0] << endl;
                flag = true;
            }
        } else {                    // index为3时代表keywords, 存在多个值
            int begin = 0, end;
            string keywords = books[i][index];
            for (int j = 0; j < keywords.length(); j++){
                end = j;
                if (end == keywords.length() - 1 || keywords[end + 1] == ' '){
                    if (data == keywords.substr(begin, end - begin + 1)){
                        cout << books[i][0] << endl;
                        flag = true;
                    }
                    begin = j + 2;
                }
            }
        }
    }
    if (!flag){
        printf("Not Found\n");
    }
}

int main(){
    cin >> n;
    getchar();          // 接收回车换行
    string str;
    for (int i = 0; i < n; i++){
        vector<string> book;
        for (int j = 0; j < 6; j++){
            getline(cin, str);
            book.push_back(str);
        }
        books.push_back(book);
    }
    sort(books.begin(), books.end(), cmp);  // 通过书本ID进行升序排序
    cin >> m;
    int begin;
    getchar();          // 接收回车换行
    for (int i = 0; i < m; i++){
        getline(cin, str);
        cout << str << endl;
        search(str[0] - '0', str.substr(3, str.length() - 3));
    }
    return 0;
}
*/