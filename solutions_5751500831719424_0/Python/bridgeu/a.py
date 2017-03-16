import sys
r = sys.stdin.readline

T = int(r())

def count_repeats(s, char):
    if len(s) == 0:
        return 0
    if s[0] == char:
        return 1 + count_repeats(s[1:], char)
    else:
        return 0

def min_deletions(lens):
    ans = 100000000000000
    
    for num_dels in range(min(lens), max(lens) + 1):
        this_ans = 0
        for l in lens:
            this_ans = this_ans + abs(l-num_dels)
        ans = min(ans, this_ans)
    return ans

def progress(strs):
    some_left = False
    some_finished = False    

    for s in strs:
        if len(s) == 0:
            some_finished = True
        else:
            some_left = True
    
    if some_left and some_finished:
        return -1
    
    if some_finished:
        return 0

    first_char = strs[0][0]
    for s in strs:
       if s[0] != first_char:
           return -1
    
    lens = map(lambda x: count_repeats(x, first_char), strs)

    num_deletions = min_deletions(lens)
    new_strs = [s[l:] for s,l in zip(strs, lens)]
    rest = progress(new_strs)
    if rest < 0:
        return -1
    else:
        return num_deletions + rest

for i in range(T):
    N = int(r())
    strs = [r() for j in range(N)]
    result = progress(strs)

    if result < 0:
        result = "Fegla Won"
    else:
        result = str(result)

    print("Case #%d: %s" % (i+1, result))
