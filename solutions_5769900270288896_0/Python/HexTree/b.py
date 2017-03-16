class unique_element:
    def __init__(self,value,occurrences):
        self.value = value
        self.occurrences = occurrences

def perm_unique(elements):
    eset=set(elements)
    listunique = [unique_element(i,elements.count(i)) for i in eset]
    u=len(elements)
    return perm_unique_helper(listunique,[0]*u,u-1)

def perm_unique_helper(listunique,result_list,d):
    if d < 0:
        yield tuple(result_list)
    else:
        for i in listunique:
            if i.occurrences > 0:
                result_list[d]=i.value
                i.occurrences-=1
                for g in  perm_unique_helper(listunique,result_list,d-1):
                    yield g
                i.occurrences+=1

g = open("data1.txt", 'w')
with open("data.txt", 'r') as f:
    T = int(f.readline())
    for r in range(T):
        R, C, N = [int(x) for x in f.readline().split()]
        RC = R*C
        house = [0]*RC
        for i in range(N):
            house[i] = 1
        best = 4*RC
        for perm in list(perm_unique(house)):
            arrange = list(perm)
            unhap = 0
            #check rows
            for i in range(R):
                for j in range(C-1):
                    if arrange[i*C + j] == 1 and arrange[i*C + j + 1] == 1:
                        unhap += 1
            #check columns
            for i in range(R-1):
                for j in range(C):
                    if arrange[i*C + j] == 1 and arrange[(i+1)*C + j] == 1:
                        unhap += 1
            best = min(best, unhap)

        g.write("Case #%d: %d\n" % (r+1, best))
f.close()
g.close()