import datetime

def main():
    filename='B-small-attempt1.in'
    F=open(filename,'r')
    T=int(F.readline())
    answer=[]
    for q in range(T):
        d=datetime.datetime.today()
        #read text and make answer as ans for each  question
        [B,N]=[int(x) for x in F.readline().split()]
        M=[int(x) for x in F.readline().split()]
        Atop=100000*1000000000
        Abottom=0
        A=(Atop+Abottom)/2
        #print A
        #binarysearch
        while(1):
            cutted=0
            openlist=[]
            for k in range(B):
                Mk=M[k]
                opened=A%Mk
                if opened==0:
                    cutted+=A/Mk
                    openlist.append(k+1)
                else:
                    cutted+=1+A/Mk
            if (cutted<N) and (N<=cutted+len(openlist)):
                #print 1
                print openlist
                for i in range(len(openlist)):
                    if cutted+i+1==N:
                        ans=str(openlist[i])
                        break
                break
            elif cutted>=N:
#                print 2
                Atop=A
                A=(Atop+Abottom)/2
            else:
                #print 3
                Abottom=A
                A=(Atop+Abottom)/2
           # print cutted,openlist,A,Abottom,Atop
        print 'Case:%d %sh%sm%s.%ssecn' % (q,d.hour, d.minute, d.second, d.microsecond)
        print ans
        answer.append('Case #'+str(q+1)+': '+ans+'\n')
    F.close()
    makeanswer(filename,answer)
     
def makeanswer(filename,answer):
    F=open('answer_'+filename,'w')
    F.writelines(answer)
    F.close()