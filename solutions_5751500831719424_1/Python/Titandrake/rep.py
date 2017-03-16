t = input()

def make_id(s):
    id = []
    ch = s[0]
    count = 1
    for i in range(1, len(s)):
        if s[i] == ch:
            count += 1
        else:
            id.append((ch, count))
            ch = s[i]
            count = 1
    id.append((ch, count))
    return id
    
# given 2 id strings of same letters
# return min differences?

def num_swaps_letter(li):
    best = 10**6
    for i in range(len(li)):
        score = sum(abs(a - li[i]) for a in li)
        best = min(score, best)
    return best
    
    
def num_swaps(strings):
    ids = [make_id(s) for s in strings]
    len1 = len(ids[0])
    lens = [len(id) for id in ids]
    if lens.count(len1) != len(strings):
        return "Fegla Won"
    swaps = 0
    for i in xrange(len1):
        col = [id[i] for id in ids]
        ch = col[0][0]
        nums = []
        for j in xrange(len(strings)):
            if col[j][0] != ch:
                return "Fegla Won"
            else:
                nums.append(col[j][1])
        swaps += num_swaps_letter(nums)
    return str(swaps)

for case in xrange(1,t+1):
    n = input()
    print "Case #%d: %s" % (case, num_swaps([raw_input() for _ in xrange(n)]))
    