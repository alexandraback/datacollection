fin = open("input.txt", 'r')
fout = open("output.txt", 'w')
t = int(fin.readline())

def process(n, ms):
    f = 0
    m = 0
    for i in range(1, n):
        f += max(ms[i - 1] - ms[i], 0)
        m = max(m, ms[i - 1] - ms[i])
    s = 0
    for i in range(1, n):
        s += min(m, ms[i - 1])
    return f, s


for test in range(1, t + 1):
    n = int(fin.readline())
    ms = list(map(int, fin.readline().split()))
    f, s = process(n, ms)
    fout.write("Case #" + str(test) + ': ' + str(f) + ' ' + str(s) + '\n')
fin.close()
fout.close()
