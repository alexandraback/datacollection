fin = open("input.txt", 'r')
fout = open("output.txt", 'w')
t = int(fin.readline())

def process(b, n, ms):
    idle = [0 for i in range(b)]
    nxt = 1
    poss = []
    while nxt == 1 or idle != [0 for i in range(b)]:
        if 0 in idle:
            for i in range(b):
                if idle[i] == 0:
                    if nxt == n:
                        return i + 1
                    nxt += 1
                    idle[i] = ms[i]
                    poss.append(i + 1)
                    break
        else:
            m = min(idle)
            for i in range(b):
                idle[i] -= m
    j = nxt - 1
    return poss[n % j - 1]

for test in range(1, t + 1):
    print(test)
    b, n = map(int, fin.readline().split())
    ms = list(map(int, fin.readline().split()))
    if b == 1:
        res = 1
    else:
        res = process(b, n, ms)
    fout.write("Case #" + str(test) + ': ' + str(res) + '\n')
fin.close()
fout.close()
