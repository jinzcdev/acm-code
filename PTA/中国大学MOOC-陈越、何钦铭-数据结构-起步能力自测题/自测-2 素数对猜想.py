def isPrime(x):
    if x <= 1:
        return False
    i = 2
    while i * i <= x:
        if x % i == 0:
            return False
        i += 1
    return True


n = int(input())
i, ans = 1, 0
while i <= n - 2:
    if isPrime(i) and isPrime(i + 2):
        ans += 1
    i += 1
print(ans)
