import copy
letters={0: 'A',
 1: 'B',
 2: 'C',
 3: 'D',
 4: 'E',
 5: 'F',
 6: 'G',
 7: 'H',
 8: 'I',
 9: 'J',
 10: 'K',
 11: 'L',
 12: 'M',
 13: 'N',
 14: 'O',
 15: 'P',
 16: 'Q',
 17: 'R',
 18: 'S',
 19: 'T',
 20: 'U',
 21: 'V',
 22: 'W',
 23: 'X',
 24: 'Y',
 25: 'Z'}
def Solve(senators):
    steps=[]
    while True:
        #print senators
        #find currently biggest party:
        ind1=senators.index(max(senators))
        #print ind1
        step=letters[ind1]
        senators[ind1]=senators[ind1]-1

        if sum(senators)<=0:
            steps.append(step)
            break
        #if we still have senators to evacuate, check if we causethe majority by evacuating another one:
        #creating copy of senators
        senators2=copy.deepcopy(senators)
        ind2=senators2.index(max(senators2))
        senators2[ind2]-=1
        #check if doing that caused majority:
        if sum(senators2)==0:
            ratio=0
        else:
            ratio=max(senators2)/sum(senators2)
        if ratio>0.5:
            steps.append(step)
            continue
        else:
            #print ind2
            senators=senators2
            step=letters[ind1]+letters[ind2]
            steps.append(step)
            if sum(senators)<=0:
                break
    return steps

with open("A-large.in") as handle,open("output.txt","w") as handle2:
    T=int(handle.readline().strip())
    for t in range(1,T+1):
        N=int(handle.readline().strip())
        senators=[]
        senators=map(int,handle.readline().strip().split(" "))
        res=Solve(senators)
        result="Case #%s: %s"%(t," ".join(res))
        print result
        handle2.write(result+"\n")