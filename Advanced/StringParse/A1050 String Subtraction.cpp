#include <cstdio>
#include <cstring>
const int maxn = 10010;
bool hashTable[128] = {false};
int main(){
    char s1[maxn], s2[maxn];
    fgets(s1, sizeof(s1) + 2, stdin);
    fgets(s2, sizeof(s1) + 2, stdin);
    int len1 = strlen(s1), len2 = strlen(s2);
    s1[--len1] = '\0';
    s2[--len2] = '\0';              // 去掉fgets读取后字符串末尾多余的回车换行
    for (int i = 0; i < len2; i++) {
        hashTable[s2[i]] = true;    // 标记需要剪去的字符
    }
    for (int i = 0; i < len1; i++) {
        if (!hashTable[s1[i]]) {
            printf("%c", s1[i]);
        }
    }
    return 0;
}

/*
#include <iostream>
#include <string>
using namespace std;
bool hashTable[128] = {false};
int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s2.length(); i++){
        hashTable[s2[i]] = true;
    }
    for (int i = 0; i < s1.length(); i++){
        if (!hashTable[s1[i]]) {
            cout << s1[i];
        }
    }
    return 0;
}
*/