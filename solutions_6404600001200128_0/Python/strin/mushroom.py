import sys

file_in = open(sys.argv[1] + '.in', 'r.')
file_out = open(sys.argv[1] + '.out', 'w.')

T = int(file_in.readline())


def diff(m):
    l = len(m)
    res = []
    for i in range(0, l-1):
        res.append(m[i+1] - m[i])
    return res


def select(d):
    return [-di for di in d if di < 0]


def method1(m):
    d = diff(m)
    s = select(d)
    if len(s) > 0:
        return sum(s)
    else:
        return 0


def method2(m):
    d = diff(m)
    s = select(d)
    if len(s) > 0:
        rate = max(s)
    else:
        rate = 0
    l = len(m)
    res = 0
    for i in range(l-1):
        res += min(m[i], rate)
    return res


for t in range(1, T+1):
    file_out.write('Case #%d: ' % t)
    N = int(file_in.readline())
    m = file_in.readline()
    m = [int(num) for num in m.split(' ')]
    file_out.write('%d %d\n' % (method1(m), method2(m)))

file_in.close()
file_out.close()
