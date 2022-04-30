// https://pintia.cn/problem-sets/994805260223102976/problems/1478634461852217344
n, m = map(int, input().split())
lst = []
while n != 0:
    n -= 1
    a = max(list(map(int, input().split())))
    lst.append(a)
print(*lst)
print(max(lst))
    