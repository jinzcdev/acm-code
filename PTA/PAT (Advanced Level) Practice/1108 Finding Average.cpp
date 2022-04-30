// https://pintia.cn/problem-sets/994805342720868352/problems/994805360777347072
n = int(input())
number = map(str, input().split())
ans, temp, cnt = 0.0, 0.0, 0
for it in number:
    try:
        temp = float(it)
        if (temp < -1000 or temp > 1000) or (it.find('.') != -1 and (len(it) - it.find('.') - 1 > 2)):
            print("ERROR: %s is not a legal number" % it)
        else:
            ans += temp
            cnt += 1
    except:
        print("ERROR: %s is not a legal number" % it)
if cnt == 0: print("The average of 0 numbers is Undefined")
elif cnt == 1: print("The average of 1 number is %.2f" % ans)
else: print("The average of %d numbers is %.2f" % (cnt, ans / cnt))

'''
#include <iostream>
#include <cctype>
using namespace std;
bool isValidNumber(string number) {
	int cntDot = 0, cntInvalid = 0, posDot;
	int i = number[0] == '-' ? 1 : 0;
    if (number[i] == '.') return false;
	for ( ; i < number.length(); i++){
		if (number[i] == '.') {
			cntDot++;
			posDot = i;
		} else if (!isdigit(number[i])) cntInvalid++;
	}
	if (cntInvalid > 0 || cntDot > 1) return false;
	if (cntDot == 1 && number.size() - 1 - posDot > 2) return false;
	if (stof(number) < -1000 || stof(number) > 1000) return false;
	return true;
}
int main() {
	int n, cnt = 0;
	string number;
	float sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> number;
		if (!isValidNumber(number)) {
			cout << "ERROR: " << number << " is not a legal number\n";
		} else {
			sum += stof(number);
			cnt++;
		}
	}
	if (cnt == 0) cout << "The average of 0 numbers is Undefined\n";
	else if (cnt != 1) printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
	else printf("The average of 1 number is %.2f\n", sum);
	return 0;
}
'''