// https://pintia.cn/problem-sets/994805342720868352/problems/994805371602845696
#include <bits/stdc++.h>
using namespace std;
struct node {
    string name;
    int time, flag = 0;
};
bool cmp1(node a, node b) {
    return a.name != b.name ? a.name < b.name : a.time < b.time;
}
bool cmp2(node a, node b) { return a.time < b.time; }
int main() {
    int n, k, maxtime = -1, hh, mm, ss;
    scanf("%d%d", &n, &k);
    string status;
    vector<node> record(n), car;
    for (int i = 0; i < n; i++) {
        cin >> record[i].name;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        cin >> status;
        record[i].time = hh * 3600 + mm * 60 + ss;
        record[i].flag = (status == "in" ? 1 : -1);
    }
    sort(record.begin(), record.end(), cmp1);
    map<string, int> mapp;
    for (int i = 0; i < n - 1; i++) {
        if (record[i].name == record[i + 1].name && record[i].flag == 1 &&
            record[i + 1].flag == -1) {
            car.push_back(record[i]);
            car.push_back(record[i + 1]);
            mapp[record[i].name] += (record[i + 1].time - record[i].time);
            maxtime = max(maxtime, mapp[record[i].name]);
        }
    }
    sort(car.begin(), car.end(), cmp2);
    vector<int> cnt(n);
    cnt[0] = 1;
    for (int i = 1; i < car.size(); i++) {
        cnt[i] += cnt[i - 1] + car[i].flag;
    }
    int preindex = 0;
    for (int i = 0; i < k; i++) {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int time = hh * 3600 + mm * 60 + ss;
        int j = preindex;
        for (; j < car.size(); j++) {
            if (car[j].time > time) {
                printf("%d\n", cnt[j - 1]);
                break;
            } else if (j == car.size() - 1) {
                printf("%d\n", cnt[j]);
            }
        }
        preindex = j;
    }
    for (auto it : mapp) {
        if (it.second == maxtime) printf("%s ", it.first.c_str());
    }
    printf("%02d:%02d:%02d\n", maxtime / 3600, (maxtime % 3600) / 60,
           maxtime % 60);
    return 0;
}