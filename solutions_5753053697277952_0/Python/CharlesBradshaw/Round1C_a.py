fin= open("A-small-attempt0 (5).in",'r')
fout=open("round1C_A.out",'w')
T = int(fin.readline())
for t in range(T):
    n=int(fin.readline())
    A = [int(i) for i in fin.readline().split()]    #%print stri
    biggestVal = 0;
    biggestIndex=0;
    secondBiggestVal = 0;
    secondBiggestIndex=0;
    for i in range(len(A)):
        if A[i]>=biggestVal:
                secondBiggestVal = biggestVal;
                secondBiggestIndex=biggestIndex;
                biggestVal = A[i];
                biggestIndex=i;
        elif A[i] >=secondBiggestVal:
                secondBiggestVal = A[i];
                secondBiggestIndex=i;
        print biggestVal,biggestIndex,secondBiggestVal,secondBiggestIndex
    plan = [];
    
    while A[biggestIndex]> A[secondBiggestIndex]:
        plan = plan + [chr(ord('A')+biggestIndex)]
        A[biggestIndex]-=1;
    for i in range(len(A)):
        if i != biggestIndex and i!=secondBiggestIndex:
             plan = plan + [chr(ord('A')+i)]*A[i]
    plan = plan + [chr(ord('A')+biggestIndex)+chr(ord('A')+secondBiggestIndex)]*A[biggestIndex]
    print "Case #"+str(t+1)+': ' +' '.join(plan)+'\n'
    fout.write("Case #"+str(t+1)+': ' +' '.join(plan)+'\n')
fout.close()
fin.close()
