n = 4

t = int(input())
for tt in range(t):
    print('Case #%s: ' % (tt+1), end='')

    g1, g2 = [], []
    a1 = int(input())-1
    for i in range(4):
        g1.append(input().split())
    a2 = int(input())-1
    for i in range(4):
        g2.append(input().split())
    
    s = set(g1[a1]) & set(g2[a2])
    if len(s)==0:
        print('Volunteer cheated!')
    elif len(s)>1:
        print('Bad magician!')
    else:
        for x in s:
            print(x)
        
        

