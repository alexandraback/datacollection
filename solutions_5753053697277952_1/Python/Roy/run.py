lines = open("A-large (2).in").readlines()

T = int(lines[0])

caseno = 1

alpha = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

import operator

idx = 1    
while caseno <= T and idx < len(lines):
    line = lines[idx]
    line = line.lstrip().rstrip()
    N = int(line)
    
    idx = idx + 1
    line = lines[idx]
    line = line.lstrip().rstrip()
    arrP = (line.split(" "))
    
    arrnumP = map(int, arrP)
    
    total = sum(arrnumP)
    ans = ""
    
    while total > 0:
        # remove max element
        index, value = max(enumerate(arrnumP), key=operator.itemgetter(1))
        ans = ans + alpha[index]
        arrnumP[index] = value-1
        total = total - 1
        # remove one more, if it would not leave only one senator
        if total != 2:
            index, value = max(enumerate(arrnumP), key=operator.itemgetter(1))
            ans = ans + alpha[index]
            arrnumP[index] = value-1
            total = total - 1
        
        ans = ans + " "
        
    
    print 'Case #%s: %s' % (caseno, ans)
    
    idx = idx + 1
    caseno = caseno + 1
        
