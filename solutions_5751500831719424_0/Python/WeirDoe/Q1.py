import math
import pdb

def check(words):
    prev_min_set = []
    operations_required = []
    prev_let = words[0][0]
    min_set = [words[0][0]]
    ops = -1
    for let in words[0]:
        if let!= prev_let:
            min_set.append(let)
            operations_required.append(ops)
            ops = 0
        else:
            ops += 1
        prev_let = let
    operations_required.append(ops)
    all_ops = [[0]*len(min_set) for i in range(len(words))]
    all_ops[0] = operations_required
    for i,w in enumerate(words[1:]):
        set_index = 0
        if w[0] != min_set[0]:
            return "Fegla Won"
        for let in w[1:]:
            if let!= min_set[set_index]:
                try:
                    if let != min_set[set_index+1]:
                        return "Fegla Won"
                except:
                    return "Fegla Won"
                set_index += 1
            else:
                all_ops[i+1][set_index] += 1
        if set_index != len(min_set)-1:
            return "Fegla Won"

    total_dist = 0
    
    for ops in zip(*all_ops):
        min_dist = -1
        for targ in ops:
            dist = 0
            for src in ops:
                dist += int(math.fabs(targ-src))
            if dist < min_dist or min_dist == -1:
                min_dist = dist
        total_dist += min_dist
    return total_dist

infile = open('A-small-attempt0(2).in','r')
outfile = open('out.txt','w')
T = int(infile.readline())
for t in range(T):
    N = int(infile.readline())
    words = []
    for n in range(N):
        words.append(infile.readline().split('\n')[0])
    val = check(words)
    outfile.write('Case #'+str(t+1)+': {0}'.format(val)+'\n')
    print 'Case #'+str(t+1)+': {0}'.format(val)
        
infile.close()
outfile.close()
print 'Completed'
