#! /opt/local/bin/python

f = open("A-small-attempt0.in")
#f = open("A-large.in")
#f = open("exA.in")

T= int(f.readline().strip());

for t in range(T):
    N=int(f.readline().strip());
    mi=  [int(x) for x in f.readline().strip().split()];
    a1,a2= 0,0
    maxrate=0
    for i in range(len(mi)-1):
        a1 += max(mi[i]-mi[i+1],0);
        maxrate= max(maxrate,max(mi[i]-mi[i+1],0))

    for i in range(len(mi)-1):
        a2 += min(mi[i],maxrate)


    print "Case #"+str(t+1)+":",a1,a2
