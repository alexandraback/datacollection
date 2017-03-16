import sys

fa1 = open('/tmp/A-small-attempt0.in')
fin = open('/tmp/in')
sf = sys.stdin


f = sf

if f != sf:
    print 'Warning! Input from file'

tests = int(f.readline())

def let(i):
    return chr(i + ord('A'))

assert (1, 2, 3)[0] == 1

def has_majority(l):
    fp = l[0][0]
    so = 0
    for c, p in l[1:]:
        so += c
    return fp > so

def equalize_top_two(l):
    ans = []
    l.sort()
    l.reverse()

    while l[0][0] > l[1][0]:
        c, p = l[0]
        ans.append(let(p))
        l[0] = (c-1, p)
    return ans


def remove_smaller(l):
    ans = []
    l.sort()
    l.reverse()

    for i in range(2, len(l)):
        while l[i][0] > 0:
            c, p = l[i]
            ans.append(let(p))
            l[i] = (c-1, p)
    return ans

def remove_top_two(l):
    ans = []
    l.sort()
    l.reverse()

    c, p1 = l[0]
    _, p2 = l[1]

    for _ in range(c):
        ans.append(let(p1) + let(p2))
    return ans

for tnr in range(1, tests+1):
    n = int(f.readline())

    l = []
    for i, el in enumerate(map(int, f.readline().strip().split())):
        l.append((el, i))

    l.sort()
    l.reverse()

    ans = []
    ans += equalize_top_two(l)
    ans += remove_smaller(l)
    ans += remove_top_two(l)

    print 'Case #%d: %s' % (tnr, ' '.join(ans))


