__author__ = 'anton'
import itertools

def group(l, f):
    cur = 0
    while cur < len(l):
        start = cur
        while cur < len(l) and f(cur) == f(start):
            cur += 1
        yield l[start: cur]

def B():
    file = open("input", "r")
    output = open("output", "w")
#    lines = [tmp.strip().split(" ") for tmp in file.readlines()[1::2]]
#    marr = [tmp.strip().split(" ") for tmp in open("input", "r").readlines()[2::2]]
#    cnt = 1
#    print lines, marr
    tn = int(file.readline())
    for cnt in range(1, tn + 1):
        n = int(file.readline())
        arr = [(int(s.split(" ")[0]), int(s.split(" ")[1])) for s in [file.readline() for i in range(n)]]
        best = [n - 1] * n
        for i in range(n):
            for j in range(i + 1, n):
                v = (arr[i][1] - arr[j][1], arr[j][0] - arr[i][0])
                per = sorted(range(n), key = lambda x: arr[x][0] * v[0] + arr[x][1] * v[1])
                sum = 0
                for l in group(per, f = lambda x: arr[per[x]][0] * v[0] + arr[per[x]][1] * v[1]):
                    for t in l:
                        best[t] = min(best[t], sum)
                        best[t] = min(best[t], n - len(l) - sum)
                    sum += len(l)
        output.write("Case #" + str(cnt) + ":\n")
        for a in best:
            output.write(str(a) + "\n")
        cnt += 1
    file.close()
    output.close()

B()