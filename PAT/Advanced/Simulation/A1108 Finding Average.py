# https://pintia.cn/problem-sets/994805342720868352/problems/994805360777347072
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
if cnt == 0:
    print("The average of 0 numbers is Undefined")
elif cnt == 1:
    print("The average of 1 number is %.2f" % ans)
else:
    print("The average of %d numbers is %.2f" % (cnt, ans / cnt))
