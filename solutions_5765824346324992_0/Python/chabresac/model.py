
debug = False
def readFile(filename):
    with open(filename, 'r') as myfile:
        # First line is the smax
        text = myfile.readline()[:-1]#
        i=1
        for line in myfile:
            # Read the line in a list
            line = line[:-1]
            if debug:
                print('-'*20)
                print(line)
            [B, N] = [int(e) for e in line.split(' ')]
            # Give the line without \n
            line = myfile.readline()[:-1]
            M = [int(e) for e in line.split(' ')]
            if debug:
                print(M)
            # solve the problem
            res = solve(B, N, M)
            print("Case #{}: {}".format(i, res))
            i += 1
            if debug:
                if i==10:
                    return 0
    return 0

def lcm(x, y):
    """This function takes two
        integers and returns the L.C.M."""
    # choose the greater number
    if( x > y):
        greater = x
    else:
        greater = y

    while(True):
        if((greater % x == 0) and (greater % y == 0)):
            lcm = greater
            break
        greater += 1
    return lcm

def lcm_l(L):
    res = L[0]
    for e in L[1:]:
        res = lcm(res,e)
    return res


def solve(B, N, M):
    global debug
    # reduce the problem
    c = lcm_l(M)
    d = sum([c//e for e in M])

    if debug:
        print("ppcm", c, "|||| clients par ppcm", d)

    if N > d:
        i = N - (N % d)
        if i == N:
            mx =  max(M)
            mxi = 0
            for j,e in enumerate(M):
                if e <= mx:
                    mx = e
                    mxi = j
            return mxi+1

    else:
        i = 0
    i+=1

    if debug:
        print("start :", i)

    ttl = []
    for e in range(B):
        ttl.append(0)
    res = 1
    clients = [0]*len(M)
    while i < N+1:
        free = False
        # take care of consumer i
        for j, t in enumerate(ttl):
        # free barber
            if t==0:
                free = True
                clients[j] = i
                ttl[j] += M[j]
                res = j + 1
                i += 1
                if debug:
                    print(clients)
                break
        if not free:
            for j in range(len(ttl)):
                ttl[j] -= 1
    return res


if __name__ == "__main__":
    filename = "test.txt"
    filename = "B-small-attempt6.in"
    readFile(filename)
