#fi=open("A-large.in"); fo=open("A-large.out","w")
fi=open("A-small-attempt0.in"); fo=open("A-small-attempt0.out","w")

def fnd():
    ans=[]
    n=int(fi.readline().strip())
    l=sorted([[int(x),chr(i+65)] for i,x in enumerate(fi.readline().strip().split())])
    while l[-1][0]!=l[-2][0]:
        if l[-1][0]-l[-2][0]>1: ans+=[l[-1][1]*2]; l[-1][0]-=2
        else: ans+=[l[-1][1]]; l[-1][0]-=1
    while len(l)>2:
        while l[0][0]:
                if l[0][0]>1: ans+=[l[0][1]*2]; l[0][0]-=2
                else: ans+=[l[0][1]]; l[0][0]-=1
        del l[0]
    while l[0][0]:
        ans+=[l[0][1]+l[1][1]]; l[0][0]-=1; l[1][0]-=1
    return ' '.join(ans)

for T in range(int(fi.readline())):     
    print("Case #"+str(T+1)+":",fnd(),file=fo)

fi.close()
fo.close()
print("OK")