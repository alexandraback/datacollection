#n=int(raw_input())
#a=[int(x) for x in raw_input().split()] 

filename='A-small-attempt0.in'
f=open(filename)
#g=f.read()
newfile=open('output.txt','wb')
t=int(f.readline())
a=0
while a<t:
    firstboard=[]
    secondboard=[]
    pp=f.readline()
    #print pp
    if len(pp)>0:
        firstanswer=int(pp.strip())
    j=0
    #d=[str(x) for x in f.readline().strip()]
    while j<4:
        k=f.readline()
        d=k.split()

        if j+1==firstanswer:
            firstboard=d
        
        j=j+1
    hh=f.readline()
    if len(hh)>0:
        secondanswer=int(hh.strip())
    q=0
    while q<4:
        c=f.readline()
        d=c.split()
        
        if q+1==secondanswer:
            secondboard=d
        q=q+1

    overlaps=[]
    for x in firstboard:
        for y in secondboard:
            if x==y:
                overlaps.append(x)
    #print overlaps
    answer=''
    if len(overlaps)==1:
        answer=str(overlaps[0])
    elif len(overlaps)>1:
        answer= "Bad magician!"
    elif len(overlaps)==0:
        answer= "Volunteer cheated!"
    answer="Case #"+str(1+a)+": "+answer
    newfile.write(answer)
    newfile.write('\r\n')
        
    a=a+1

newfile.close()
