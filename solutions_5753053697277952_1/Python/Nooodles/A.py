### Google code jam 2016
### Online round 1C
### Problem B

def Chr(i):
    return chr(65+i);

Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1),

    N = int(raw_input());
    Pi = map(int, raw_input().split());
    while (sum(Pi) > 2):
        idx = Pi.index(max(Pi));
        Pi[idx] -= 1;

        idx2 = Pi.index(max(Pi));
        Pi[idx2] -= 1;

        if (max(Pi)*2 <= sum(Pi)):
            print Chr(idx) + Chr(idx2),
        else:
            print Chr(idx),
            Pi[idx2] += 1;

    Pair = [];
    for j in range(N):
        if Pi[j] == 1:
            Pair.append(j);
    L = '';
    for e in Pair:
        L += Chr(e);
    print L;
        
