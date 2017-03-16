__author__ = 'anton'
import itertools

def B():
    file = open("input", "r")
    output = open("output", "w")
    lines = [tmp.strip().split(" ") for tmp in file.readlines()[1::2]]
    marr = [tmp.strip().split(" ") for tmp in open("input", "r").readlines()[2::2]]
    cnt = 1
    print lines, marr
    for line, arr_str in itertools.izip(lines, marr):
        print line, arr_str
        arr = [int(x) for x in arr_str]
        b = int(line[0])
        n = int(line[1])
        l = -1
        r = 2 *100000 *1000000000
        while l + 1 < r:
            m = (l + r) / 2
            oppa = 0
            for x in arr:
                oppa += m / x + 1
            if oppa >= n:
                r = m
            else:
                l = m
        tmp = n
        for x in arr:
            tmp -= (r - 1) / x + 1
            print x, (r - 1) / x + 1
        res = -1

        print r, oppa, tmp
        for i in range(len(arr)):
            if r % arr[i] == 0:
                tmp -= 1
                if tmp == 0:
                    res = i
                    break
        output.write("Case #" + str(cnt) + ": " + str(res + 1) + "\n")
        cnt += 1
    file.close()
    output.close()

B()