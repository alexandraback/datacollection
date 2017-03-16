import sys

args = sys.argv
file = args[1]
f = open(file)

cases = int(f.readline())

for i in range(cases):
    num = int(f.readline())
    l = f.readline().split(' ')
    ms = [int(x) for x in l]
    mms = zip(ms[:-1],ms[1:])
    ds = [max(0,x - y) for (x,y) in mms]
    s = sum(ds)
    m = max(ds)
    vs = [min(x,m) for x in ms[:-1]]
    s2 = sum(vs)
    #print mms
    #print ds
    #print vs
    print "Case #%s: %s %s" % (i + 1,s, s2)
    
