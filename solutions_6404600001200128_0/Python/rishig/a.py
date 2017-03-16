import sys

def run(line):
    ms = [int(x) for x in line.split()]
    maxdiff = 0
    first = 0
    last = 0
    for m in ms:
        if m < last:
            first += last - m
            if last - m > maxdiff:
                maxdiff = last - m
        last = m

    second = 0
    for m in ms[:-1]:
        second += min(maxdiff, m)
    return '%d %d' % (first,second)

fin = open(sys.argv[1])
T = int(fin.readline().strip())
for i in range(1,T+1):
    line = fin.readline().strip()
    line = fin.readline().strip()
    ans = run(line)
    print('Case #%d: %s' % (i, ans))
