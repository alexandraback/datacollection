__author__ = 'Christian'

#fname = 'test_a.txt'
#fname = 'A-small-attempt0.in'
fname = 'A-large.in'

f = open(fname, 'r')
data = f.read().split('\n')
f.close()

res_file = open(fname + '.res', 'w')

def evacuate(L):
    res = []
    
    L.sort(reverse=True)
    effective_first = L[0][0]
    effective_second = L[1][0]
    
    if effective_first > effective_second:
        # send out from the first until first and second have the same number of senators
        n = effective_first - effective_second
        P = L[0][1]
        res += ([P+P] * (n/2))
        if n % 2 == 1:
            res.append(P)
        effective_first = effective_second
        
    # eliminate all the other parties
    for n, P in L[2:]:
        res += ([P+P] * (n/2))
        if n % 2 == 1:
            res.append(P)
    
    # then let the first 2 parties leave together
    P1 = L[0][1]
    P2 = L[1][1]
    
    for i in range(effective_second):
        res.append(P1+P2)
        
    return ' '.join(res)


T = int(data[0])
for i in range(T):
    print i
    P = data[2*i+1]
    L = [[int(x), chr(ord('A') + ind)] for ind,x in enumerate(data[2*i+2].split(' '))]
    print L
    print >> res_file, "Case #%s: %s" % (i+1, evacuate(L))
    
res_file.close()