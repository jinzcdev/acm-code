// https://pintia.cn/problem-sets/994805260223102976/problems/1071786104348536832
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int maxn = 10010;
struct student {
    string id;
    int score;
} stu[maxn];
struct pos {
    string id;
    int stuNum;
};
int n, m;
map<string, int> posToStuNum;
vector<pos> ans;

bool cmpCaseOne(student a, student b) {
    if (a.score != b.score) return a.score > b.score;
    return a.id < b.id;
}

bool cmpCaseThree(pos a, pos b) {
    if (a.stuNum != b.stuNum) return a.stuNum > b.stuNum;
    return a.id < b.id;
}

void doCaseOne(string level) {
    int cnt = 0;
    sort(stu, stu + n, cmpCaseOne);
    for (int i = 0; i < n; i++){
        if (stu[i].id[0] == level[0]) {
            cout << stu[i].id << " " << stu[i].score << endl;
            cnt++;
        }
    }
    if (cnt == 0) cout << "NA" << endl;
}

void doCaseTwo(string posId) {
    int num = 0, sum = 0, cnt = 0;
    for (int i = 0; i < n; i++){
        if (stu[i].id.substr(1, 3) == posId) {
            num++;
            sum += stu[i].score;
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << "NA" << endl;
        return;
    }
    cout << num << " " << sum << endl;
}


void doCaseThree(string date) {
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (stu[i].id.substr(4, 6) == date) {
            posToStuNum[stu[i].id.substr(1, 3)]++;
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << "NA" << endl;
        return;
    }
    for (map<string, int>::iterator it = posToStuNum.begin(); it != posToStuNum.end(); it++){
        pos P;
        P.id = (*it).first;
        P.stuNum = (*it).second;
        ans.push_back(P);
    }
    sort(ans.begin(), ans.end(), cmpCaseThree);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i].id << " " << ans[i].stuNum << endl;
    }
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> stu[i].id >> stu[i].score; 
    }
    for (int i = 0; i < m; i++){
        int ins;
        string para;
        cin >> ins >> para;
        cout << "Case " << i + 1 << ": " << ins << " " << para << endl;
        if (ins == 1) doCaseOne(para);
        else if (ins == 2) doCaseTwo(para);
        else if (ins == 3) doCaseThree(para);
    }
    return 0;
}