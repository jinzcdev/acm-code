// https://pintia.cn/problem-sets/994805046380707840/problems/1111914599412858885
#include <bits/stdc++.h>
using namespace std;
void changeItoYou(string &str, int pos) {
    str.replace(str.begin() + pos, str.begin() + pos + 1, "you");
}
void changeMeToYou(string &str, int pos) {
    str.replace(str.begin() + pos, str.begin() + pos + 2, "you");
}
void solve(string s) {
    while (s[0] == ' ') s.erase(s.begin());
    while (s[s.length() - 1] == ' ') s.erase(s.end() - 1);
    for (int i = 0; i < s.length(); i++) {
        while (s[i] == ' ' && s[i + 1] == ' ') s.erase(s.begin() + i + 1);
        if (i < s.length() - 1 && s[i] == ' ' && s[i + 1] == '\'')
            s.erase(s.begin() + i);
        if (i < s.length() - 1 && s[i] == ' ' && !isalnum(s[i + 1]))
            s.erase(s.begin() + i);
        if (s[i] == ' ' && s[i - 1] == '\'') s.erase(s.begin() + i);
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'I' && isupper(s[i])) s[i] += 32;
        if (s[i] == '?') s[i] = '!';
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'I') {
            if (s.length() == 1)
                s.replace(s.begin(), s.end(), "you");
            else if (i == 0 && !isalnum(s[i + 1])) {
                changeItoYou(s, i);
            } else if (i == s.length() - 1 && !isalnum(s[i - 1]))
                changeItoYou(s, i);
            else if (!isalnum(s[i - 1]) && !isalnum(s[i + 1])) {
                changeItoYou(s, i);
            }
        } else if (s[i] == 'm' && i + 1 < s.length() && s[i + 1] == 'e') {
            if (i == 0 && !isalnum(s[i + 2]))
                changeMeToYou(s, i);
            else if (i == s.length() - 2 && !isalnum(s[i - 1]))
                changeMeToYou(s, i);
            else if (!isalnum(s[i - 1]) && !isalnum(s[i + 2]))
                changeMeToYou(s, i);
        }
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'I') {
            if (s.length() == 1)
                s.replace(s.begin(), s.end(), "you");
            else if (i == 0 && !isalnum(s[i + 1])) {
                changeItoYou(s, i);
            } else if (i == s.length() - 1 && !isalnum(s[i - 1]))
                changeItoYou(s, i);
            else if (!isalnum(s[i - 1]) && !isalnum(s[i + 1])) {
                changeItoYou(s, i);
            }
        } else if (s[i] == 'm' && i + 1 < s.length() && s[i + 1] == 'e') {
            if (i == 0 && !isalnum(s[i + 2]))
                changeMeToYou(s, i);
            else if (i == s.length() - 2 && !isalnum(s[i - 1]))
                changeMeToYou(s, i);
            else if (!isalnum(s[i - 1]) && !isalnum(s[i + 2]))
                changeMeToYou(s, i);
        }
    }

    for (int i = 0; s.length() >= 9 && i < s.length() - 9 + 1; i++) {
        if (s.substr(i, 9) == "could you") {
            s.replace(s.begin() + i, s.begin() + i + 9, "I could");
        }
    }
    for (int i = 0; s.length() >= 7 && i < s.length() - 7 + 1; i++) {
        if (s.substr(i, 7) == "can you") {
            s.replace(s.begin() + i, s.begin() + i + 7, "I can");
        }
    }

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'I') {
            if (s.length() == 1)
                s.replace(s.begin(), s.end(), "you");
            else if (i == 0 && !isalnum(s[i + 1])) {
                changeItoYou(s, i);
            } else if (i == s.length() - 1 && !isalnum(s[i - 1]))
                changeItoYou(s, i);
            else if (!isalnum(s[i - 1]) && !isalnum(s[i + 1])) {
                changeItoYou(s, i);
            }
        } else if (s[i] == 'm' && i + 1 < s.length() && s[i + 1] == 'e') {
            if (i == 0 && !isalnum(s[i + 2]))
                changeMeToYou(s, i);
            else if (i == s.length() - 2 && !isalnum(s[i - 1]))
                changeMeToYou(s, i);
            else if (!isalnum(s[i - 1]) && !isalnum(s[i + 2]))
                changeMeToYou(s, i);
        }
    }
    cout << s << endl;
}
int main() {
    int n;
    cin >> n;
    getchar();
    while (n--) {
        string s;
        getline(cin, s);
        cout << s << endl;
        cout << "AI: ";
        solve(s);
    }
    return 0;
}

/*
// https://pintia.cn/problem-sets/994805046380707840/problems/1111914599412858885
#include <bits/stdc++.h>
using namespace std;

string line, orign;

bool is_fuhao(char c) { return (!isspace(c) && !isalpha(c) && !isdigit(c)); }

bool is_duli(int s, int t, int limit) {
    return (((s == 0) || isspace(line[s - 1]) || is_fuhao(line[s - 1])) &&
            ((t == limit) || isspace(line[t + 1]) || is_fuhao(line[t + 1])));
}

int find_duli(string s, int pos) {
    int idx;
    int len = line.length();
    while (pos < len && (idx = line.find(s, pos)) >= 0) {
        if (is_duli(idx, idx + s.length() - 1, len - 1))
            return idx;
        else
            pos += s.length();
    }
    return -1;
}

void replace_unit(string o, string t) {
    bool isUpdate = true;
    int pos = 0;
    while (pos < (int)line.length() && isUpdate) {
        isUpdate = false;
        int idx = find_duli(o, pos);
        if (idx >= 0) {
            line.replace(idx, o.length(), t);
            isUpdate = true;
            pos = idx + o.length();
        }
    }
}

void proc_replace() {
    replace_unit("I", "You");
    replace_unit("me", "You");
    replace_unit("can you", "I can");
    replace_unit("could you", "I could");
}

void del_blank() {
    bool isUpdate = true;
    while (isUpdate) {
        int len = line.length(), pos = 0;
        isUpdate = false;
        for (int i = pos; i < len; i++) {  // 结尾不会是空格，不会越界
            if (isspace(line[i]) &&
                (isspace(line[i + 1]) || is_fuhao(line[i + 1]))) {
                line.erase(i, 1);
                pos = i;
                isUpdate = true;
                break;
            }
        }
    }
}

void to_lower_tanhao() {
    transform(line.begin(), line.end(), line.begin(), [](char c) -> char {
        if (c == '?')
            return '!';
        else if (c == 'I')
            return 'I';
        return tolower(c);
    });
}

void input_and_trim() {
    getline(cin, orign);
    line = orign;

    if (!line.empty()) {
        line.erase(0, line.find_first_not_of(" "));
        line.erase(line.find_last_not_of(" ") + 1);
    }
}

int main() {
    int n;
    cin >> n;
    getchar();
    while (n--) {
        input_and_trim();
        to_lower_tanhao();
        del_blank();
        proc_replace();
        to_lower_tanhao();
        cout << orign << endl;
        cout << "AI: " << line << endl;
    }
}
*/