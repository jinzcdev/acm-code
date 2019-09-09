// https://pintia.cn/problem-sets/994805342720868352/problems/994805456881434624
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 2010;
struct Ga{
    string head;
    int numMember;
    int total;
} Gang[maxn];
int G[maxn][maxn], w[maxn] = {0};
bool visited[maxn] = {false};
map<string, int> stringToInt;   // 姓名 -> 编号
map<int, string> intToString;   // 编号 -> 姓名
int n, k;
int numGang = 0, numPerson = 0;

bool cmp(Ga a, Ga b){
    return a.head < b.head;
}
// 要求得到一个团伙的头目,成员数和总通话时长, 故使用引用类型,
void DFS(int start, int &head, int &numMember, int &totalWeight){
    visited[start] = true;
    numMember++;
    if (w[start] > w[head]){
        head = start;                   // 记录当前点权最大的成员为head
    }
    for (int i = 0; i < numPerson; i++){
        if (G[start][i] > 0){           // 表明成员begin与成员i之间存在通话
            totalWeight += G[start][i];     // 先累计该边的权值(与下行代码同时存在)
            G[start][i] = G[i][start] = 0;  // 一条边多次通话的权值在输入时已添加,此处仅防止走回路,故删除该边
            if (!visited[i]){           // 该顶点未访问, 则由此处继续DFS
                DFS(i, head, numMember, totalWeight);
            }
        }
    }
}

void DFSTraverse(){
    for (int v = 0; v < numPerson; v++){
        if (!visited[v]){       // 逻辑为真的个数就是团伙数(包括不合法的)
            int head = v, numMember = 0, totalWeight = 0;
            DFS(v, head, numMember, totalWeight);
            if (numMember > 2 && totalWeight > k){  // 人数大于2且总通话时长大于k满足一个团伙的条件
                Gang[numGang].head = intToString[head];
                Gang[numGang].numMember = numMember;
                Gang[numGang].total = totalWeight;
                numGang++;      // 团伙从numGang=0开始累加,循环结束后得到团伙的个数
            }
        }
    }
}

int change(string str){
    if (stringToInt.find(str) != stringToInt.end()) {
        return stringToInt[str];        // 如果map中存在该姓名则返回编号
    } else {
        stringToInt[str] = numPerson;   // 不存在由编号numPerson=0开始累加
        intToString[numPerson] = str;
        return numPerson++;
    }
}

int main(){
    cin >> n >> k;
    string name1, name2;
    int time;
    for (int i = 0; i < n; i++){
        cin >> name1 >> name2 >> time;
        int id1 = change(name1);        // 给姓名做编号存入map
        int id2 = change(name2);
        w[id1] += time;
        w[id2] += time;
        G[id1][id2] += time;            // 顶点id1,id2之间的边权
        G[id2][id1] += time;
    }
    DFSTraverse();
    sort(Gang, Gang + numGang, cmp);    // 按姓名字典序排序
    cout << numGang << endl;
    for (int i = 0; i < numGang; i++){
        cout << Gang[i].head << " " << Gang[i].numMember << endl;
    }
    return 0;
}