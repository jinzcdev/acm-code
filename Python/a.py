a, b = map(int, input().split())
print(int(''.join(list(str(a * b))[::-1])))
