import sys

f = open(sys.argv[1])
f.readline()
m = f.readline()
t = 1
while m != "":
    m = [int(x) for x in f.readline().split()]

    c1 = 0
    for i in range(1,len(m)):
        if m[i-1]-m[i] > 0:
            c1 += m[i-1]-m[i]

    mdiff = [m[i-1]-m[i] for i in range(1,len(m))]

    crate = max(mdiff)
    c2 = 0
    for i in range(len(m)-1):
        c2 += min(crate,m[i])

    print "Case #{}: {} {}".format(t,c1,c2)


    t += 1
    m = f.readline()
