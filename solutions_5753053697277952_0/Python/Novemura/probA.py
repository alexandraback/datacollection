import datetime
import string

def main():
    filename='A-small-attempt0.in'
    F=open(filename,'r')
    T=int(F.readline())
    answer=[]
    for q in range(T):
        d=datetime.datetime.today()
        #read text and make answer as ans for each  question
        N=int(F.readline())
        senatelist=[int(x) for x in F.readline().split()]
        rem=sum(senatelist)
        ansset=[]
        ASCII=string.ascii_uppercase
        while rem>0:
            senatelisttemp=senatelist[:]
            #danger=sum(senatelisttemp)/2+1
            evaq1=senatelisttemp.index(max(senatelisttemp))
            senatelisttemp[evaq1]-=1
            evaq2=senatelisttemp.index(max(senatelisttemp))
            if max(senatelisttemp)>sum(senatelisttemp)/2:
                senatelisttemp[evaq2]-=1
                ansset.append(ASCII[evaq1]+ASCII[evaq2])
                rem-=2
            else:
                ansset.append(ASCII[evaq1])
                rem-=1
            senatelist=senatelisttemp[:]
        ans=' '.join(ansset)
        print 'Case:%d %sh%sm%s.%ssecn' % (q,d.hour, d.minute, d.second, d.microsecond)
        print ans
        answer.append('Case #'+str(q+1)+': '+str(ans)+'\n')
    F.close()
    makeanswer(filename,answer)
     
def makeanswer(filename,answer):
    F=open('answer_'+filename,'w')
    F.writelines(answer)
    F.close()