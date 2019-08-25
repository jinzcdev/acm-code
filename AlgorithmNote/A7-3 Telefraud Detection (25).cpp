#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int maxn = 1010;
struct node {
    int id;
    map<int, int> record;
} P[maxn];
int k, n, m;
set<int> callers;
vector<node> suspect;

bool isSuspect(node p){
    int cnt = 0, cntShort = 0, cntReceive = 0;
    for (map<int, int>::iterator it = p.record.begin(); it != p.record.end(); it++){
        int receiver = (*it).first, duration = (*it).second;
        cnt++;
        if (duration <= 5) {
            cntShort++;
            if (p.id == 6 ){
                printf("%d %d\n", receiver, duration);
            }
            if (P[receiver].record[p.id] > 0){
                cntReceive++;
            }
        }
    }
    if (cntShort <= k) return false;
    printf("%d = %f %f\n", p.id, cntReceive * 1.0, cntShort*1.0);
    if (cntReceive * 1.0 <= cntShort * 0.2)return true;
    else return true;
}

int main(){
    scanf("%d%d%d", &k, &n, &m);
    int caller, receiver, duration;
    for (int i = 0; i < m; i++){
        scanf("%d%d%d", &caller, &receiver, &duration);
        P[caller].id = caller;
        P[caller].record[receiver] += duration;
        callers.insert(caller);
    }

    for (set<int>::iterator it = callers.begin(); it != callers.end(); it++){
        node p = P[*it];
        if (isSuspect(p)) {
            suspect.push_back(p);
        }
    }
    for (int i = 0; i < suspect.size(); i++){
        printf("%d  ", suspect[i].id);
    }
    

    return 0;
}