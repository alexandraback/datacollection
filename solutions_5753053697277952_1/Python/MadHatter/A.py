__author__ = 'dkopiychenko'

def check(l):
    total = sum([a for a,b in l])
    for a,b in l:
        if 2*a > total: return False
    return True


def solve(l):
    r = []
    total = sum([a for a,b in l])
    while l:
        l.sort(reverse=True)
        l[0][0] -= 1
        if check(l):
            r.append(l[0][1])
            if l[0][0] == 0:
                del l[0]
        else:
            l[1][0] -= 1
            if not check(l): print 'AAAAAAAA'
            r.append(l[0][1]+l[1][1])
            if l[1][0] == 0:
                del l[0]
            if l[0][0] == 0:
                del l[0]

    return ' '.join(r)

t = int(raw_input())
for i in xrange(t):
    n = int(raw_input())
    l = [[int(v),chr(65+j)] for j,v in enumerate(raw_input().strip().split())]
    print 'Case #' + str(i+1) + ': ' + str(solve(l))