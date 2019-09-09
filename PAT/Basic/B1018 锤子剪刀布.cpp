// https://pintia.cn/problem-sets/994805260223102976/problems/994805304020025344
#include <cstdio>
#include <algorithm>
using namespace std;
struct gesture {
    char g;
    int count;
} p1[], p2;

char jia, yi;
bool isJiaWin() {
    if ((jia == 'C' && yi == 'J') || (jia == 'J' && yi == 'B') || (jia == 'B' && yi == 'C')) return true;
    else return false;
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%c %c", &jia, &yi);
        if (isJiaWin()) win[0][jia - 'A']++;
        else win[1][yi - 'A']++;
    }

}