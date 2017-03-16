fin = open('A-small-attempt0.in', 'r')
fout = open('output.txt', 'w')

t = int(fin.readline())

def no50(a, b, p):
    if a <> None:
        p[a] -= 1
    if b <> None:
        p[b] -= 1
    count = sum(p)
    if max(p) > count//2:
        ok = False
        if a <> None:
            p[a] += 1
        if b <> None:
            p[b] += 1
    else:
        ok = True
    return ok    

def removeOne(n, p):
    for i in xrange(n):
        if p[i] > 0 and no50(i, None, p):
            return i
    return None

def removeTwo(n, p):
    for i in xrange(n):
        if p[i] > 0:
            for j in xrange(n):
                if i <> j or p[j] > 1:
                    if p[j] > 0 and no50(i, j, p):
                        return [i, j]
    return None

for i in xrange(t):
    print i
    n = int(fin.readline())
    p = map(int, fin.readline().split())

    plan = []

    while sum(p) > 0:
        one = removeOne(n, p)
        if one == None:
            two = removeTwo(n, p)
            plan += [chr(two[0] + 65) + chr(two[1] + 65)]
        else:
            plan += [chr(one + 65)]
    
    fout.write('Case #' + str(i + 1) + ': ' + ' '.join(plan) + '\n')

fout.close()

print 'FINISHED'
