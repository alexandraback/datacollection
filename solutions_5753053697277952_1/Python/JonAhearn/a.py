import string
alphabet = list(string.ascii_uppercase)

T = int(input())

for test in range(T):
    partydict = dict()
    N = int(input())
    P = list(map(int,input().split()))
    seats = sum(P)        
    
    for i in range(N):
        partydict[alphabet[i]] = P[i]

    answers = []
        
    if (seats % 2) == 1:
        ranked_parties = sorted(partydict, key=partydict.get, reverse=True)
        answers.append(ranked_parties[0])
        partydict[ranked_parties[0]] -= 1
        seats -= 1
    
    while seats > 0:
        ranked_parties = sorted(partydict, key=partydict.get, reverse=True)
        answers.append(ranked_parties[0] + ranked_parties[1])
        partydict[ranked_parties[0]] -= 1
        partydict[ranked_parties[1]] -= 1
        seats -= 2
    
    print('Case #' + str(test+1) + ': ' + ' '.join(answers))