// https://pintia.cn/problem-sets/994805342720868352/problems/994805472333250560
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 10010;
struct player {
    int arrive, p, tag, server;
} Player;

struct {
    int endtime, numServer;
    bool vip;
} T[101];
vector<player> P;

void init() {
    for (int i = 0; i < 100; i++) {
        T[i].vip = false;
        T[i].endtime = 28800;
        T[i].numServer = 0;
    }
}

void allocate(int pid, int tid) {
    if (P[pid].arrive <= T[tid].endtime) {
        P[pid].server = T[tid].endtime;
    } else {
        P[pid].server = P[pid].arrive;
    }
    T[tid].endtime = P[pid].server + P[pid].p;
    T[tid].numServer++;
}
bool cmpByArrive(player a, player b) { return a.arrive < b.arrive; }
bool cmpByServer(player a, player b) { return a.server < b.server; }
int main() {
    init();
    int n, p, tag, k, m, v;
    int hh, mm, ss;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &p, &tag);
        Player.arrive = hh * 3600 + mm * 60 + ss;
        Player.p = p * 60;
        Player.tag = tag;
        if (Player.arrive < 21 * 3600) P.push_back(Player);
    }
    sort(P.begin(), P.end(), cmpByArrive);
    scanf("%d%d", &k, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &v);
        T[v].vip = true;
    }
    for (int i = 0; i < P.size();) {
        if (P[i].server != 0) i++;
        if (i == (int)P.size()) break;
        int tid = -1, minendtime = 0x7FFFFFF;
        for (int j = 1; j <= k; j++) {
            if (T[j].endtime < minendtime) {
                minendtime = T[j].endtime;
                tid = j;
            }
        }
        if (T[tid].endtime >= 21 * 3600) break;
        if (T[tid].vip == true) {  // it's vip table
            if (P[i].tag == 1) {   // the first player is vip.
                allocate(i, tid);
                i++;
            } else {
                int pid = -1;
                for (int j = i; j < P.size() && P[j].arrive <= T[tid].endtime; j++) {
                    if (P[j].tag == 1 && P[j].server == 0) {
                        pid = j;
                        break;
                    }
                }
                if (pid != -1) {
                    allocate(pid, tid);
                } else {
                    allocate(i, tid);
                    i++;
                }
            }
        } else {                  // it's not vip table.
            if (P[i].tag == 0) {  //
                allocate(i, tid);
                i++;
            } else {
                int viptable = -1, minendtime = 0x7FFFFFFF;
                for (int j = 1; j <= k; j++) {
                    if (T[j].vip == true && T[j].endtime < minendtime) {
                        minendtime = T[j].endtime;
                        viptable = j;
                    }
                }
                if (viptable != -1 && P[i].arrive >= T[viptable].endtime) {
                    allocate(i, viptable);
                    i++;
                } else {
                    allocate(i, tid);
                    i++;
                }
            }
        }
    }
    sort(P.begin(), P.end(), cmpByServer);
    for (int i = 0; i < P.size(); i++) {
        if (P[i].server == 0) continue;
        int arrive = P[i].arrive, server = P[i].server;
        int wait = server - arrive;
        printf("%02d:%02d:%02d ", arrive / 3600, (arrive / 60) % 60, arrive % 60);
        printf("%02d:%02d:%02d ", server / 3600, (server / 60) % 60, server % 60);
        printf("%.0f\n", round(wait / 60.0));
    }
    for (int i = 1; i <= k; i++) {
        if (i != 1) printf(" ");
        printf("%d", T[i].numServer);
    }
    return 0;
}