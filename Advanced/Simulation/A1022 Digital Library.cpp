// https://pintia.cn/problem-sets/994805342720868352/problems/994805480801550336
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int maxn = 10010;
int n, m;
string books[maxn][6];              // 二维数组表示所有的书本及其相关信息

bool cmp(string a, string b){
    return a < b;                   // ID较小的书排在前列
}

void search(int index, string data){
    vector<string> ans;
    bool flag = false;
    for (int i = 0; i < n; i++){
        if (index != 3){                    // index为3通过值精确匹配
            if (books[i][index] == data){
                ans.push_back(books[i][0]);
                flag = true;
            }
        } else {                            // index为3时代表keywords, 存在多个值
            int begin = 0, end;
            string keywords = books[i][index];
            for (int j = 0; j < keywords.length(); j++){
                end = j;
                if (end == keywords.length() - 1 || keywords[end + 1] == ' '){
                    if (data == keywords.substr(begin, end - begin + 1)){
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
        sort(ans.begin(), ans.end(), cmp);      // 对本次书本查询结果通过ID进行升序排序
        for (int i = 0; i < ans.size(); i++){
            cout << ans[i] << endl;
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