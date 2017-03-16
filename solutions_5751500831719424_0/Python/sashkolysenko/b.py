import sys
from itertools import groupby

def do_it(lines):
    if len(lines) == 1:
        return 0
    if len(set(lines)) == 1:
        return 0

    groups = []
    lens = set()

    for line in lines:
        groups.append([list(g) for k, g in groupby(line)])
        l = len(groups[-1])

        if lens and l not in lens:
            return

        lens.add(l)

    for i in range(len(groups[0])):
        l = None
        for g in groups:
            if l is None:
                l = g[i][0]
            if g[i][0] != l:
                return None
    
    assert len(lens) == 1

    num = 0
    for j in range(list(lens)[0]):
        if len(groups) == 2:
            num += abs(len(groups[0][j]) - len(groups[1][j]))
       
#        else:
#            num += count(groups, j)
        #for group in groups:
        #    print group[j]
        #    #num += 1

    return num

if __name__ == '__main__':

    test_cases = int(sys.stdin.readline().strip())

    for i in range(test_cases):
        num = int(sys.stdin.readline().strip())

        lines = []
        for j in range(num):
            lines.append(sys.stdin.readline().strip())

        num = do_it(lines)

        if num is None:
            print 'Case #{}: Fegla Won'.format(i + 1)
        else:
            print 'Case #{}: {}'.format(i + 1, num) 
