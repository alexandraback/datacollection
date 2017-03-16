import datetime

def main():
    filename='A-small-attempt0.in'
    F=open(filename,'r')
    T=int(F.readline())
    answer=[]
    for q in range(T):
        d=datetime.datetime.today()
        #read text and make answer as ans for each  question
        N=int(F.readline())
        m=[int(x) for x in F.readline().split()]
        #str 1
        sum1=0
        for i in range(1,N):
            if m[i-1]-m[i]>=0:
                sum1+=m[i-1]-m[i]
        #str 2
        biggestrate=0
        for i in range(1,N):
            if m[i-1]-m[i]>biggestrate:
                biggestrate=m[i-1]-m[i]
        sum2=0
        for i in range(0,N-1):
            sum2+=min(m[i],biggestrate)
        ans=' '.join([str(sum1),str(sum2)])
        print 'Case:%d %sh%sm%s.%ssecn' % (q,d.hour, d.minute, d.second, d.microsecond)
        print ans
        answer.append('Case #'+str(q+1)+': '+ans+'\n')
    F.close()
    makeanswer(filename,answer)
     
def makeanswer(filename,answer):
    F=open('answer_'+filename,'w')
    F.writelines(answer)
    F.close()