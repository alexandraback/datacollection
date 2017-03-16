import linecache
from sys import argv

filename = argv[1]
num = int(linecache.getline(filename, 1))
index = 2

def changes(a, b):

    if a == b:
        return 0

    total = 0
    ap = "\n"
    bp = "\n"
    ai = 0
    bi = 0

    while(ai < len(a) and bi < len(b)):
        ac = a[ai]
        bc = b[bi]

        if ai+1 < len(a):
            an = a[ai+1]
        else:
            an = None

        if bi+1 < len(b):
            bn = b[bi+1]
        else:
            bn = None

        # Equal cases.
        if ac == bc:
            if bn == an:
                ai += 1
                bi += 1

            elif bn != ac and an != bc:
                if bn == an:
                    ai += 1
                    bi += 1
                else:
                    return -1

            elif bn == ac:
                bi += 1
                total += 1

            elif an == bc:
                ai += 1
                total += 1

        else:
            return -1

    return total

def shortest(a):
    s = []
    p = None

    for c in list(a):
        if p != c:
            s.append(c)
            p = c

    return ''.join(s)

for i in range(num):
    count = int(linecache.getline(filename, index))
    strings = []
    final = float('inf')
    failed = False

    for j in range(0, count+1):

        if j == 0:
            master = shortest(linecache.getline(filename, index+1).strip())
        else:
            master = linecache.getline(filename, index+j).strip()
        temp = 0

        for k in range(1, count+1):
            checking = linecache.getline(filename, index+k).strip()
            steps = changes(master, checking)

            if steps == -1:
                failed = True
                break
            else:
                temp += steps

        if failed:
            break

        if temp < final:
            final = temp

    if failed:
        print "Case #%i: Fegla Won" % (i+1)
    else:
        print "Case #%i: %i" % (i+1, final)

    index += count + 1


