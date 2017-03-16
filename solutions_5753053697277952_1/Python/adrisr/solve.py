
def valid(parties):
    total = sum(parties)
    majority = total/2
    return all(p<=majority for p in parties)

def pending(parties):
    return any(p>0 for p in parties)

def name(idx):
    return chr(ord('A') + idx)

def step(parties):
    N = len(parties)
    for i in range(N):
        if parties[i]>0:
            for j in range(i,N):
                if parties[j]>0:
                    newp = list(parties)
                    newp[i] -= 1
                    newp[j] -= 1
                    if newp[i]>=0 and newp[j]>=0 and valid(newp):
                        parties = newp
                        return (parties,name(i) + name(j))
            else:
                newp = list(parties)
                newp[i] -= 1
                if newp[i]>=0 and valid(newp):
                        parties = newp
                        return (parties,name(i))
                
    raise Exception('fucked up ' + ' '.join(map(str,parties)))

def solve(parties):
    result = []
    while pending(parties):
        (parties,r) = step(parties)
        result.append(r)
    return result

NUM_CASES = int(input())
for case_num in range(NUM_CASES):
    num_parties = int(input())
    parties = list(map(int,input().split()))
    result = solve(parties)
    print('Case #{0:d}: {1:s}'.format(case_num+1,' '.join(result)))

