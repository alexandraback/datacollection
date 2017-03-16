import sys

#input = sys.stdin
#output = sys.stdout

input = open('input.txt', 'r')
output = open('output.txt', 'w')

T = int(input.readline())
for z in range(T):
    print(z)
    n = int(input.readline())
    v = [int(i) for i in input.readline().split()]
    a, b = 0, 0
    r = 0
    for i in range(n - 1):
        if v[i] > v[i + 1]:
            a += v[i] - v[i + 1]
        b = max(b, v[i] - v[i + 1])
    for i in range(n - 1):
        r += min(v[i], b)
    print('Case #', z + 1, ': ', a, ' ', r, sep = '', file = output)

input.close()
output.close()