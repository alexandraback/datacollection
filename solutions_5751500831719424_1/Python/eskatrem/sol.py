import sys 
feglaWon = "Fegla Won"

def distinct(lst):
    if type(lst) is not list:
        return lst
    return list(set(lst))

def minForm(string):
    n = len(string)
    if n <= 1:
        return string
    c = string[0]
    res = c
    count = 0
    for i in range(1,n):
        tmp = string[i]
        if tmp != c:
            res +=tmp
            c = tmp
        else:
            count += 1
    return (res, count)

def minOps(str1, str2):
    g1 = groups(str1)
    g2 = groups(str2)
    tmp1 = map(lambda x:x[0],g1)
    tmp2 = map(lambda x:x[0],g2)
    if tmp1 != tmp2:
        return False
    return sum(map(lambda x,y: abs(len(x)-len(y)),g1,g2))

def groups(string):
    if len(string) == 0:
        return []
    if len(string) == 1:
        return [string]
    res = []
    n = len(string)
    c = string[0]
    tmpStr = c
    for i in range(1,n):
        tmp = string[i]
        if tmp != c:
            res.append(tmpStr)
            c = tmp
            tmpStr = c
        else:
            tmpStr +=c
    res.append(tmpStr)
    return res

def makeTable(strs):
    table = []
    for s1 in strs:
        tmpLine = []
        for s2 in strs:
            tmp = abs(len(s1)-len(s2))
            tmpLine.append(tmp)
        table.append(tmpLine)
    return table

def solveStrs(strs):
    table = makeTable(strs)
    return min(map(lambda x: sum(x),table))

# def solve(strs):
#     table = []
#     for s1 in strs:
#         tmpLine = []
#         for s2 in strs:
#             if s1 == s2:
#                 tmpLine.append(0)
#             else:
#                 tmp = minOps(s1,s2)
#                 if tmp == False:
#                     return feglaWon
#                 tmpLine.append(tmp)
#         table.append(tmpLine)
#     return min(map(lambda x: sum(x), table))

def letters(grp):
    return map(lambda x:x[0], grp)

def solve(strs):
    grps = map(groups, strs)
#    print grps
    for g1 in grps:
        for g2 in grps:
            if letters(g1) != letters(g2):
                return feglaWon
    nGrps = len(grps[0])
    res = 0
    for i in range(nGrps):
        tmp = solveStrs(map(lambda x:x[i],grps))
        res += tmp
    return res

def main():
    fileName = sys.argv[1]
    f = open(fileName, 'r+')
    lines = [line for line in f]
    nCases = int(lines[0])
    k = 1
    count = 1
    while count <= nCases:
        n = int(lines[k])
        strs = [lines[i] for i in range(k+1,k+n+1)]
        strs = map(lambda x: x.replace("\n",""), strs)
        #print n,strs
        print "Case #"+str(count)+": "+str(solve(strs))
        k = k+n
        k = k+1
        count = count+1

if __name__ == "__main__":
    main()
