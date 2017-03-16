lines=[]
file1=open('A-small-attempt0.in')
for line in file1:
    lines.append(line)
file1.close


T=int(lines[0])
ctr=1
f=open('Output.out','w')
while ctr<=T:
    N=int(lines[(2*ctr) - 1])#raw_input().split()]
    Inp=[int(x) for x in lines[2*ctr].split()]#raw_input()    Temp_Max=Inp[0]
    Store=0
    for i in range(0,N-1):
        if Inp[i]>Inp[i+1]:
            Store+=Inp[i]-Inp[i+1]
    #Store is the first output
    Max_Eat=0
    for i in range(N-1):
        if Inp[i]>Inp[i+1] and Max_Eat<Inp[i]-Inp[i+1]:
            Max_Eat=Inp[i]-Inp[i+1]
    S=0
    for i in range(0,N-1):
        S+=min(Max_Eat,Inp[i])
    Score2=S

    f.write("Case #%d: %d %d" %(ctr,Store,Score2))#print "Case #%d: YES" %(ctr)
    ctr+=1
    if ctr<=T:
        f.write("\n")
f.close()
