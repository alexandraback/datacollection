

def solve(P):
    output = ''
    parties = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    while sum(P)>0:
        maxParties = []
        numSenators = 0
        for i in range(len(P)):
            if P[i] > numSenators:
                numSenators = P[i]
                maxParties = [i]
            elif P[i] == numSenators:
                maxParties += [i]
        if len(maxParties) == 1:
            output += ' {}'.format(parties[maxParties[0]])
            P[maxParties[0]] -= 1
        elif len(maxParties) > 1:
            if len(maxParties) % 2 == 0:
                output += ' {}{}'.format(parties[maxParties[0]],parties[maxParties[1]])
                P[maxParties[0]] -= 1
                P[maxParties[1]] -= 1
            else:
                output += ' {}'.format(parties[maxParties[0]])
                P[maxParties[0]] -= 1
    return output
    
for i in range(1,int(input())+1):
    N = int(input())
    P = list(map(int,input().split(' ')))
    print('Case #{}:{}'.format(i,solve(P)))