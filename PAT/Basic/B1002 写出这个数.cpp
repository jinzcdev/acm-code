#include <iostream>
#include <vector>
using namespace std;
string change[10] = {"ling", "yi",  "er", "san", "si",
                     "wu",   "liu", "qi", "ba",  "jiu"};
int main() {
    vector<int> ans;
    string s;
    int number = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++) number += s[i] - '0';
    while (number != 0) {
        ans.push_back(number % 10);
        number /= 10;
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        if (i != ans.size() - 1) printf(" ");
        cout << change[ans[i]];
    }
    return 0;
}
/*
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int sum = 0;
		String s = in.nextLine();
		in.close();
		char[] ch1 = s.toCharArray();
		for (int i = 0; i < ch1.length; i++) {
			sum += (ch1[i] - 48);
		}

		char[] ch2 = (sum + "").toCharArray();
		for (int i = 0; i < ch2.length; i++) {
            String[] str = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
			String s1 = str[ch2[i] - 48];
			System.out.print(s1);
			if (i != ch2.length - 1)
				System.out.print(" ");
		}
	}
}
*/

// https://pintia.cn/problem-sets/994805260223102976/problems/994805324509200384
// #include <cstdio>
// #include <cstring>
// const int maxn = 110;
// char n[maxn];
// char change[10][5] = {"ling", "yi",  "er", "san", "si",
//                       "wu",   "liu", "qi", "ba",  "jiu"};
// int ans[10] = {0};
// int main() {
//     scanf("%s", n);
//     int len = strlen(n), num = 0, sum = 0;
//     for (int i = 0; i < len; i++) sum += n[i] - '0';
//     while (sum != 0) {
//         ans[num++] = sum % 10;
//         sum = sum / 10;
//     }
//     for (int i = num - 1; i >= 0; i--) {
//         printf("%s", change[ans[i]]);
//         if (i != 0) printf(" ");
//     }
//     return 0;
// }