// https://pintia.cn/problem-sets/994805342720868352/problems/994805498207911936
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1010;
struct Window {
    int poptime, endtime;
    queue<int> q;
} window[20];
int processTime[1010] = {0}, ans[1010] = {0};
int main(){
    int n, m, k, q, query;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 0; i < 20; i++) window[i].poptime = window[i].endtime = 8 * 60;
    for (int i = 0; i < k; i++) scanf("%d", &processTime[i]);
	int index = 0;
	for (int i = 0; i < min(n * m, k); i++) {
		int NoW = index % n;
		window[NoW].q.push(index);
		window[NoW].endtime += processTime[index];
		if (index < n) window[NoW].poptime = processTime[index];
		ans[index] = window[NoW].endtime;
		index++;
	}
	for (; index < k; index++) {
		int NoW = -1, minPop = 0x7FFFFFFF;
		for (int i = 0; i < n; i++) {
			if (window[i].poptime < minPop) {
                minPop = window[i].poptime;
				NoW = i;
			}
		}
		window[NoW].q.pop();
		window[NoW].q.push(index);
		window[NoW].endtime += processTime[index];
		window[NoW].poptime += processTime[window[NoW].q.front()];
		ans[index] = window[NoW].endtime;
	}
	for (int i = 0; i < q; i++) {
        scanf("%d", &query);
        if (ans[query - 1] - processTime[query - 1] >= 17 * 60) printf("Sorry\n");
        else printf("%02d:%02d\n", ans[query - 1] / 60, ans[query - 1] % 60);
	}
    return 0;
}