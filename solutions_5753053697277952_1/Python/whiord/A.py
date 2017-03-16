T = int(raw_input())

A = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

N = 0

def left(i):
    return i*2


def right(i):
    return i*2 + 1


def parent(i):
    return i//2


def heapify(d, i):
    l = left(i)
    r = right(i)
    cand = i

    if l < N and d[i][1] < d[l][1]:
        d[i], d[l] = d[l], d[i]
        cand = l

    if r < N and d[i][1] < d[r][1]:
        d[i], d[r] = d[r], d[i]
        cand = r

    if i != cand:
        heapify(d, cand)

def build_heap(d):
    for i in xrange(N-1, -1, -1):
        heapify(d, i)

for i in xrange(T):
    print "Case #" + str(i + 1) + ":",

    N = int(raw_input())

    def get_next(d):
        if d[0][1] == 0: return False

        max_count = 1
        max_values = [0]

        if d[1][1] == d[0][1]:
            max_count += 1
            max_values.append(1)

        if N >= 3 and d[2][1] == d[0][1]:
            max_count += 1
            max_values.append(2)

        if max_count == 3:
            max_values = max_values[0:1]

        res = ''
        for j in max_values[::-1]:
            res += A[d[j][0]]
            d[j][1] -= 1
            heapify(d, j)

        print res,

        return True

    P = list(map(int, raw_input().split()))

    D = list(map(list, enumerate(P)))

    build_heap(D)

    while get_next(D):
        pass

    print







