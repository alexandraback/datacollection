import heapq


def solve_case():
    N = int(raw_input())
    senate = zip((-int(o) for o in raw_input().split()), range(N))
    heapq.heapify(senate)
    while senate:
        first = heapq.heappop(senate)
        second = heapq.heappop(senate)
        if (first[0] + 2) <= second[0]:
            yield chr(ord('A') + first[1]) * 2
            heapq.heappush(senate, second)
            heapq.heappush(senate, (first[0] + 2, first[1]))
            continue
        if first[0] == -1 and second[0] == -1 and len(senate) == 1:
            yield chr(ord('A') + first[1])
            heapq.heappush(senate, second)
            continue        
        yield chr(ord('A') + first[1]) + chr(ord('A') + second[1])
        if second[0] + 1 < 0:
            heapq.heappush(senate, (second[0] + 1, second[1]))
        if first[0] + 1 < 0:
            heapq.heappush(senate, (first[0] + 1, first[1]))


def solve():
    T = int(raw_input())
    for TC in xrange(1, T + 1):
        print "Case #%d: %s" % (TC, " ".join(solve_case()))


if __name__ == '__main__':
    solve()