

if __name__=='__main__':
    T = int(input())
    for i in range(1,T+1):
        ans = 'Case #'+str(i)+': '
        fG = int(input())
        fA = []
        for j in range(4):
            inp = input().split(' ')
            fA.append([int(a) for a in inp])
        sG = int(input())
        sA = []
        for j in range(4):
            inp = input().split(' ')
            sA.append([int(a) for a in inp])
        cands = []
        for x in fA[fG-1]:
            if x in sA[sG-1]:
                cands.append(x)

        if len(cands)==1:
            ans += str(cands[0])
        elif len(cands)==0:
            ans += 'Volunteer cheated!'
        else:
            ans += 'Bad magician!'
        print(ans)
