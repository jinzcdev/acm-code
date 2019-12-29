a, b = map(int, input().split())
print(sum(int(str(a) * i) for i in range(1, b + 1)))