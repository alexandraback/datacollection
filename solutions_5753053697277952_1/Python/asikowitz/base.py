inp = open("A-large.in","r")
out = open("al.out","w")

def readline(f):
    return f.readline().strip()

def trans(x):
    return chr(ord('A')+x)

def three_ones(L):
    count = 0
    for i in range(len(L)):
        if L[i] == 1:
            count += 1
    return count == 3

def find_maxs(L):
    if L[1] > L[0]:
        max1 = (L[0],0)
        max2 = (L[1],1)
    else:
        max1 = (L[1],1)
        max2 = (L[0],0)
    
    for i in range(2,len(L)):
        if L[i] > max1[0] and L[i] > max2[0]:
            max1 = max2
            max2 = (L[i],i)
        elif L[i] > max1[0]:
            max1 = (L[i],i)

    if max2[0] == 0:
        return (0,)
    elif max2[0] > max1[0]:
        return (1,max2[1])
    else:
        if three_ones(L):
            return (1,max2[1])
        else:
            return (2,max2[1],max1[1])

n = int(readline(inp))

for case in range(n):
    p = int(readline(inp))
    L = map(int, readline(inp).split(" "))
    
    ans = ""
    maxs = find_maxs(L)

    while maxs[0] != 0:
        if maxs[0] == 1:
            ans += " " + trans(maxs[1])
            L[maxs[1]] -= 1
        else:
            ans += " " + trans(maxs[1]) + trans(maxs[2])
            L[maxs[1]] -= 1
            L[maxs[2]] -= 1
        maxs = find_maxs(L)
            
    out.write("Case #%d: %s\n" % (case+1,ans[1:]))

inp.close()
out.close()
