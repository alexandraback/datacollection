def readints():
    return [int(X) for X in input().split(' ')]

def chr(X):
    return 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'[X]

for C in range(int(input())):
    N = int(input())
    data = readints()
    plan = []
    while sum(data) > 0:
        m = max(data)
        i = data.index(m)
        data[i] -= 1
        n = max(data)
        if (n == m and sum(data) != 2):
            j = data.index(m)
            data[j] -= 1
            plan.append(chr(i)+chr(j))
        else:
            plan.append(chr(i))
    print("Case #{}: {}".format(1+C, ' '.join(plan)))
            

