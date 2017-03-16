def reduce(s):
    red = s[0]
    for l in s:
        if l != red[-1]:
            red += l
    return red

def has_sol(strings):
    return len(set(map(reduce, strings))) == 1

def count_reps(s):
    last = ""
    counts = []
    for l in s:
        if l == last:
            counts[-1] += 1
        else:
            last = l
            counts.append(1)
    return counts

def median(l):
    return sorted(l)[len(l)/2]

def ops_for_letter(counts):
    m = median(counts)
    return sum(abs(m - c) for c in counts)


def min_ops(strings):
    scounts = map(count_reps, strings)
    ops = []
    for j in xrange(len(scounts[0])):
        lcounts = [scounts[i][j] for i in xrange(len(scounts))]
        ops.append(ops_for_letter(lcounts))
    return sum(ops)

def solve(strings):
    if not has_sol(strings):
        return "Fegla Won"
    else:
        return '%d' % min_ops(strings)
    

    
def readint(f):
    return int(f.readline()[:-1])

def readint(f):
    return int(f.readline()[:-1])


f = open('/Users/jolleon/Downloads/A-small-attempt0 (1).in')

ntests = readint(f)

for case in xrange(ntests):
    n = readint(f)
    strings = []
    for _ in xrange(n):
        strings.append(f.readline()[:-1])
    print 'Case #%d: %s' % (case+1, solve(strings))