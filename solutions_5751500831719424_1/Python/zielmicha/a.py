
def parse_string(s):
    cch = s[0]
    count = 0
    resp = []
    for ch in s:
        if ch == cch:
            count += 1
        else:
            resp.append((cch, count))
            cch = ch
            count = 1
    resp.append((cch, count))
    return resp

z = int(raw_input())

def check_dist(arr, d):
    return sum( abs(e - d) for e in arr )

def perform(strings):
    lengths = [ len(ss) for ss in strings ]
    if len(set(lengths)) != 1:
        return None

    for string in strings:
        for i in xrange(len(string)):
            if strings[0][i][0] != string[i][0]:
                return None

    dist_s = 0
    for leti in xrange(len(strings[0])):
        nums = [ string[leti][1] for string in strings ]
        dist = min(
            check_dist(nums, cand) for cand in xrange(0, max(nums) + 1)
        )
        dist_s += dist

    return dist_s

for casei in xrange(z):
    n = int(raw_input())
    strings = [ parse_string(raw_input()) for i in xrange(n) ]
    print 'Case #%d:' % (casei + 1),
    ret = perform(strings)
    if ret == None:
        print 'Fegla Won'
    else:
        print ret
