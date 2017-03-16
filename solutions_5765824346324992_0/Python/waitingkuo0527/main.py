def gcd(x, y):
    if x % y == 0: return y
    return gcd(y, x%y)
def lcm(x, y):
    return int(x * y / gcd(x, y))

def solve(B, N, M):
    """ solve the problem """

    #print( gcd(10, 3) )
    #print( gcd(10, 4) )
    #print( gcd(10, 8) )
    l = 1
    for m in M: l = lcm(l, m)
    time_per_one_turn = l
    people_per_one_turn = 0
    for m in M: people_per_one_turn += int(l / m)

    g = M[0]
    for m in M: g = gcd(g, m)

    N %= people_per_one_turn
    if N == 0: N = people_per_one_turn
    #print(people_per_one_turn)

    timer = 0
    _N = N
    while True:
        free = []
        for i, m in enumerate(M):
            if timer % m == 0: free.append(i)

        #print(timer, free, _N)
        if len(free) >= _N: 
            ans_i = free[_N-1] + 1
            break
        else:
            _N -= len(free)

        timer += g

    if ans_i > B: 1/0

    return ans_i



def parse():
    """ parse input """

    B, N = [int(i) for i in input().split()]
    M = [int(i) for i in input().split()]

    return B, N, M


def main():
    
    T = int(input())

    # solve
    for t in range(1, T+1):
        params = parse()
        result = solve(*params)
        print('Case #%d: %s' % (t, result))
        #if t ==7: break


if __name__ == '__main__':

    main()
