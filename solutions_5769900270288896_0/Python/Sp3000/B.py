import itertools

def unhap(comb, r, c):
    unhappiness = 0

    for i in range(r*c):
        if i % c > 0 and comb[i] == comb[i-1] == 1:
            unhappiness += 1

        if i % c < c-1 and comb[i] == comb[i+1] == 1:
            unhappiness += 1

        if i//c > 0 and comb[i] == comb[i-c] == 1:
            unhappiness += 1

        if i//c < r-1 and comb[i] == comb[i+c] == 1:
            unhappiness += 1

    return unhappiness//2 # Double counted

    
def optimal(r, c, n):
    best = None
    config = None
    
    for comb in itertools.product([0, 1], repeat=r*c):
        if sum(comb) != n:
            continue

        unhappiness = unhap(comb, r, c)
        
        if best is None or unhappiness < best:
            best = unhappiness
            config = comb

    # for i in range(r):
    #    print(*[".#"[b] for b in config[i*c:(i+1)*c]], sep="")

    return best


with open("B-small-attempt0.in") as infile:
    with open("B.out", "w") as outfile:
        ncases = int(next(infile))

        for case in range(1, ncases + 1):
            r, c, n = map(int, next(infile).split())

            print("Case #{}: {}".format(case, optimal(r, c, n)), file=outfile)
