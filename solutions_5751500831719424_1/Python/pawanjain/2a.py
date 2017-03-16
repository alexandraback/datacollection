import os
f_inp = 'inp_1.txt'
f_out = 'out_1.txt'
f=open(f_inp)
f_o = open(f_out, 'w')
def next_line(f):
    line = f.readline()
    if line:
        line = line.strip()
    return line

def get_res(nums):
    s = min(nums)
    e = max(nums)
    if len(nums) == 2:
        return abs(s-e)
    min_l = None
    res = None
    for i in range(s,e+1):
        l = sum([abs(i-_) for _ in nums])
        if not min_l or l < min_l:
            min_l = l
    print nums, min_l
    return min_l
def get_num(strs, n):
    uniqs = []
    uniq_counts = []
    for s in strs:
        chars = [_ for _ in s]
        uniq_chars = []
        counts = []
        for c in chars:
            if not uniq_chars or uniq_chars[-1] != c:
                uniq_chars.append(c)
                counts.append(1)
            else:
                counts[-1] += 1
        uniqs.append(''.join(uniq_chars))
        uniq_counts.append(counts)
    if len(set(uniqs)) != 1:
        return None
    
    print strs, uniqs, uniq_counts
    total_chances = 0
    for x in range(len(uniq_counts[0])):
        nums = [_[x] for _ in uniq_counts]
        chances = get_res(nums)
        total_chances += chances
    
    num = total_chances
    return num

num_tc = int(next_line(f))
np = 'Fegla Won'
resp = 'Case #%s: %s'
for i in xrange(1,num_tc+1):
    n = int(next_line(f))
    strs = []
    for _ in range(n):
        strs.append(next_line(f))
    res = get_num(strs, n)
    if res is None:
        res = np
    out = resp % (i, res)
    f_o.write('%s\n' % out)
    print out
f.close()
f_o.close()
