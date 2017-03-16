import numpy as np

f = open('A-large.in', 'r')
o = open('A.out', 'w')

ord_A = ord('A')

# i + 1 < len(c)
def swap(c, i):
    c[i], c[i + 1] = c[i + 1], c[i]

def find(n, c):
    p = []
    c = [[v, chr(ord_A + i)] for i, v in enumerate(c)]
    c.sort(reverse = True)
    # print()
    # print(c)
    while c[0][0] > 0:
        p1 = c[0][1]
        c[0][0] -= 1
        i = 0
        while i + 1 < len(c) and c[i][0] < c[i + 1][0]:
            swap(c, i)
            i += 1
        if c[1][0] == c[0][0] and (len(c) == 2 or c[2][0] == 0):
            p2 = ''
        else:
            p2 = c[0][1]
            c[0][0] -= 1
            i = 0
            while i + 1 < len(c) and c[i][0] < c[i + 1][0]:
                swap(c, i)
                i += 1
        # print(c)
        p.append(p1 + p2)
    return ' '.join(p)

m = int(f.readline().strip())
i = 1

while i <= m:
    n = int(next(f).strip())
    c = list(map(int, next(f).split()))
    print('Case #{0}: {1}'.format(i, find(n, c)), file = o)
    i += 1

f.close()
o.close()
