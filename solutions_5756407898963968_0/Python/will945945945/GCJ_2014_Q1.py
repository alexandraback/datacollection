
F = open('/Users/poy/Downloads/A-small-attempt0.in.txt')

A = F.read()
A = A.split('\n')[1:-1]


X = []

for i in xrange(len(A)):
    if i % 10 == 0:
        X += [[  int(A[i]) , map(lambda x: x.split(' '),A[i+1:i+5]) , int(A[i+5]) , map(lambda x: x.split(' '),A[i+6:i+10]) ]]

def fcn(a,A,b,B):
    candicate = A[a-1]
    Ans = []
    for i in B[b-1]:
        if i in candicate:
            Ans.append(i)

    if len(Ans) == 0:
        return 'Volunteer cheated!'
    elif len(Ans) == 1:
        return str(Ans[0])
    else:
        return 'Bad magician!'
        
    
Ans = []

for i in X:
    Ans.append(fcn(i[0],i[1],i[2],i[3]))

E = open('/Users/poy/Desktop/output.txt','w')

for i in xrange(len(Ans)):
    E.write('Case #' + str(i+1) +': '+Ans[i]+'\n')

E.close()























