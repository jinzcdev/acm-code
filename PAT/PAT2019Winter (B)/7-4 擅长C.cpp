#include <cctype>
#include <iostream>
using namespace std;
int main() {
    string alpha[26][10], str;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> alpha[i][j];
        }
    }
    getline(cin, str);
    int left = 0;
    for (int i = 0; i < str.length(); i++) {
        if (!isupper(str[i])) {
            int right = i - 1;
            for (int j = 0; j < 7; j++) {
                for (int k = left; k <= right; k++) {
                    if (k != left) printf(" ");
                    cout << alpha[str[k] - 'A'][j];
                }
                printf("\n");
            }
            left = i + 1;
        }
        if (!isupper(str[i]) && i != str.length() - 1) printf("\n");
    }
    if (isupper(str[str.length() - 1])) {
        for (int i = 0; i < 7; i++) {
            for (int j = left; j < str.length(); j++) {
                if (j != left) printf(" ");
                cout << alpha[str[j] - 'A'][i];
            }
            printf("\n");
        }
    }
    return 0;
}