a, b = 1, 1
print('1, 1, ', end='')
for i in range(0, 18):
    a, b = b, a + b
    print('%d' % b, end='')
    if i != 17:
        print(', ', end='')
