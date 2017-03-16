def nxt(parties):
    sp = filter(lambda x: x[0] > 0, sorted(parties))
    # print "nxt", parties, sp

    res = sp[-1][1]  # biggest is always picked
    sp[-1][0] -= 1

    sp = filter(lambda x: x[0] > 0, sorted(sp))
    if len(sp) != 0 and not (len(sp) == 2 and sp[-1][0] == sp[-2][0]):
        res += sp[-1][1]
        sp[-1][0] -= 1

    return res, filter(lambda x: x[0] > 0, sorted(sp))


def solve(parties):
    # print "a", parties
    ordr = []
    while True:
        res, parties = nxt(parties)
        ordr += [res]
        # print "res", res, parties
        if not parties:
            # print "done", parties
            break
    return ordr


# print solve([[2, 'a'], [2, 'b']])
# exit(0)
#print solve(map(list, zip([123, 345, 123, 345, 214, 34, 421, 4, 6, 234, 456, 821, 523, 12, 3, 7, 7, 44, 647, 234], "ABCDEFGHIJKLMNOPQRSTUVWXYZ")))
num = 1


def m():
    global num
    n = input()
    a = map(int, raw_input().split())

    # print "input", a

    print "Case #{0}: {1}".format(num, " ".join(solve(map(list, zip(a, "ABCDEFGHIJKLMNOPQRSTUVWXYZ")))))
    num += 1


tc = int(input())
for _ in range(tc):
    m()
