// https://pintia.cn/problem-sets/994805342720868352/problems/994805493648703488
#include <bits/stdc++.h>
using namespace std;
struct node {
    string name;
    int month, day, hour, minute, time, flag;
};
int rate[25];
bool cmp(node a, node b) {
    return a.name != b.name ? a.name < b.name : a.time < b.time;
}
double getBillCharge(node record) {
    double amount =
        rate[record.hour] * record.minute + rate[24] * 60 * record.day;
    for (int i = 0; i < record.hour; i++) amount += rate[i] * 60;
    return amount / 100.0;
}
int main() {
    for (int i = 0; i < 24; i++) {
        scanf("%d", &rate[i]);
        rate[24] += rate[i];
    }
    int n;
    scanf("%d", &n);
    vector<node> record(n);
    string name, status;
    for (int i = 0; i < n; i++) {
        cin >> record[i].name;
        scanf("%d:%d:%d:%d", &record[i].month, &record[i].day, &record[i].hour,
              &record[i].minute);
        cin >> status;
        record[i].time = (record[i].day * 24 + record[i].hour) * 60 + record[i].minute;
        record[i].flag = (status == "on-line" ? 1 : -1);
    }
    sort(record.begin(), record.end(), cmp);
    map<string, vector<node> > ans;
    for (int i = 0; i < n - 1; i++) {
        if (record[i].name == record[i + 1].name && record[i].flag == 1 && record[i + 1].flag == -1) {
            ans[record[i].name].push_back(record[i]);
            ans[record[i].name].push_back(record[i + 1]);
        }
    }
    for (auto it : ans) {
        cout << it.first;
        vector<node> v = it.second;
        printf(" %02d\n", v[0].month);
        double amount = 0;
        for (int i = 0; i < v.size(); i += 2) {
            double charge = getBillCharge(v[i + 1]) - getBillCharge(v[i]);
            amount += charge;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", v[i].day,
                   v[i].hour, v[i].minute, v[i + 1].day, v[i + 1].hour,
                   v[i + 1].minute, v[i + 1].time - v[i].time, charge);
        }
        printf("Total amount: $%.2f\n", amount);
    }
    return 0;
}