from math import sqrt

for num in range(1, 10000):
    tmp = 0
    ans = []
    for fac in range(1, int(sqrt(num) + 1)):
        if num % fac == 0:
            tmp += fac
            ans.append(fac)
            if fac > 1 and num // fac != fac:
                tmp += num // fac
                ans.append(num // fac)
    if tmp == num:
        ans.sort()
        print('%d =' % num, ans)
