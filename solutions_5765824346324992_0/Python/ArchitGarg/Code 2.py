from fractions import gcd

lines=[]
file1=open('B-small-attempt2.in')
for line in file1:
    lines.append(line)
file1.close

def lcm(a,b):
    return (a*b)/gcd(a,b)
def LCM(Array):
    temp=1
    for i in range(0,len(Array)):
        temp=lcm(temp,Array[i])
    return temp
def People(L,Array):
    s=0
    for i in range(0,len(Array)):
        s+=(L/Array[i])
    return s
T=int(lines[0])
ctr=1
f=open('Output.out','w')
while ctr<=T:
    B,N=[int(x) for x in lines[(2*ctr) - 1].split()]#raw_input().split()]
    Inp=[int(x) for x in lines[2*ctr].split()]#raw_input()
    Cur=[0]*B
    Used=0
    i=0
    L=LCM(Inp)
    pe=People(L,Inp)
    if N%pe==0:
        N=pe
    else:
        N=N%pe
    while i<N:
        found=0
        for j in range(0,B):
            if Cur[j]==0:
                Cur[j]=Inp[j]
                Used=j+1
                found=1
                break
        if found==0:
            M=min(Cur)
            for j in range(0,B):
                Cur[j]-=M
            i-=1
        i+=1



    f.write("Case #%d: %d" %(ctr,Used))#print "Case #%d: YES" %(ctr)
    ctr+=1
    if ctr<=T:
        f.write("\n")
f.close()
