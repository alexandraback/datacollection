from fractions import gcd

def LCM(a):
    r1 = a[0]
    for x in (xrange(len(a)-1)):
        g = gcd(r1,a[x+1])
        lcm = r1*a[x+1]/g
        r1 = lcm
    return lcm


inF = open('B-small-attempt0.in.txt','r')
ouF = open('MaryamQ2.out','w')
t = int(inF.readline())
for j in xrange(t):
    l1 = map(int,inF.readline().split())
    b = l1[0]
    n = l1[1]
    l2 = map(int,inF.readline().split())
    lcm = LCM(l2)
    nA = 0;
    for x in l2 :
        nA += lcm/x
#    print nA
    
    nF = n% nA
    if nF == 0 : nF = nA
    serv = [0]*b
    end = [0]*b
    for jj in range(nF):
        a = end.index(min(end))
        end[a] +=l2[a]
    ouF.write('Case #'+str(j+1)+': '+str(a+1)+'\n')
ouF.close()


