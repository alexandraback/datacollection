__author__ = 'Peter'
from Queue import PriorityQueue
import math
with open ("B-small-attempt4.out","w") as outF:
    with open("B-small-attempt4.in","r") as inF:
        nt= int(inF.readline())
        for it in xrange(nt):
            b,n= map(int, inF.readline().split())
            seq= map(int, inF.readline().split())
            nOther=[]
            for i in xrange(len(seq)):
                sp=0
                for j in xrange(len(seq)):
                    if i!=j:
                        sp+=seq[i]/seq[j]+1
                nOther.append(sp+1)

            queue= PriorityQueue()

            for i in xrange(len(seq)):
                queue.put((-seq[i],-i,1))

            count=0
            while True:
                t,ind,dCount=queue.get()
                t=-t
                ind=-ind
                count+=dCount
                if count==n:
                    outF.write("Case #%d: %d\n"%(it+1, ind+1))
                    break
                countLeft=n-count
                assert countLeft>0
                nNext= max(1,countLeft/nOther[ind])
                queue.put((-t-seq[ind]*nNext,-ind,nNext))