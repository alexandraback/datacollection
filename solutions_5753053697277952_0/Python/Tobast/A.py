import sys
def absmaj(parties):
    senNum = sum(parties)
    for part in parties:
        if part > senNum/2:
            return True
    return False

def argmax(t, exc=None):
    m = 0
    for i in range(len(t)):
        if t[i] >= t[m] and (exc == None or exc != i):
            m = i
    return m

def partName(x):
    return chr(x+ord('A'))
    
def solve():
    nbPart = int(input())
    parties = [ int(x) for x in input().strip().split(' ') ]
    
    plan = []
    while sum(parties) > 0:
        ev1 = argmax(parties)
        ev2 = argmax(parties, ev1)
        parties[ev1] -= 1
        parties[ev2] -= 1
        if absmaj(parties):
            parties[ev2] += 1
            if absmaj(parties):
                print("ERROR: strategy not working.")
                sys.exit(1)
            else:
                plan.append(partName(ev1))
        else:
            plan.append(partName(ev1)+partName(ev2))
    
    out = ''
    for x in plan:
        out += x+' '
    return out[:-1]

T = int(input())
for c in range(T):
    print("Case #{}: {}".format(c+1,solve()))
