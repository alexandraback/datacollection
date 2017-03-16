import sys
def identical(arr):
    min = -1
    for i in xrange(len(arr)):
        c = 0
        for j in xrange(len(arr)):
            c += abs(arr[j]-arr[i])
        if min == -1 or min > c:
            min = c
    return min
                 
def solve(N,strings):
    a = []
    for string in strings:
        x = []
        c = 0
        cur = ""
        for i in string:
            if cur == "":
                c += 1
                cur = i
            elif cur == i:
                c += 1
            else:
                x.append((cur,c))
                c = 1
                cur = i 
        x.append((cur,c))    
        a.append(x[:])
    
    #print a                        
    for it in a:
        for x in a:
            if len(x) != len(it):
                return "Fegla Won" 
            else:
                for i,j in zip(it,x):
                    if i[0] != j[0]:
                        return "Fegla Won"
    
    y = [] 
    for j in xrange(len(a[0])):
        m = []
        for i in xrange(len(a)):
            m.append(a[i][j][1])
        y.append(m)
    c = 0
    for it in y:
        c += identical(it)                       
    return c
T = int(sys.stdin.readline())
case = 1
for _ in xrange(T):
    N = int(sys.stdin.readline())
    strings = []
    for i in xrange(N):
        strings.append(sys.stdin.readline().strip())
    print "Case #%d:" %case , solve(N,strings)
    case += 1 
