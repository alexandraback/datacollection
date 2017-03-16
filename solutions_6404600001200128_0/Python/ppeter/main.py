__author__ = 'Peter'
with open ("A-small-attempt0.out","w") as outF:
    with open("A-small-attempt0.in","r") as inF:
        nt= int(inF.readline())
        for t in xrange(nt):
            n= int(inF.readline())
            seq= map(int, inF.readline().split())

            erg0=0
            maxD=0
            for i in xrange(1,n):
                if seq[i-1]-seq[i]>0:
                    erg0+=seq[i-1]-seq[i]
                if seq[i-1]-seq[i]>maxD:
                    maxD=seq[i-1]-seq[i]
            erg1=0
            for i in xrange(1,n):
                erg1+=min(maxD,seq[i-1])

            outF.write("Case #%d: %d %d\n"%(t+1,erg0,erg1))

