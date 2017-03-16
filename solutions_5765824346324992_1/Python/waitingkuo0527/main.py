def gcd(x, y):
    if x % y == 0: return y
    return gcd(y, x%y)
def lcm(x, y):
    print('x, y, gcd', x, y, gcd(x, y))
    return int(int(x/ gcd(x, y)) * y)

def solve(B, N, M):
    """ solve the problem """

    #print( gcd(10, 3) )
    #print( gcd(10, 4) )
    #print( gcd(10, 8) )

    #l = 1
    #for m in M: l = lcm(l, m)
    #time_per_one_turn = l
    #people_per_one_turn = 0
    #for m in M: people_per_one_turn += int(l / m)

    #g = M[0]
    #for m in M: g = gcd(g, m)

    #N %= people_per_one_turn
    #if N == 0: 
    #    min_m = min(M)
    #    to_return = 0
    #    for i, m in enumerate(M):
    #        if m == min_m: to_return = i+1
    #    return to_return

    #timer = 0
    #_N = N
    #while True:
    #    free = []
    #    for i, m in enumerate(M):
    #        if timer % m == 0: free.append(i)

        #print(timer, free, _N)
    #    if len(free) >= _N: 
    #        ans_i = free[_N-1] + 1
    #        break
    #    else:
    #        _N -= len(free)
#
#        timer += g
#
#    if ans_i > B: 1/0

    timer_min = 0
    #timer_max = time_per_one_turn
    timer_max = max(M) * N

    while True:
        timer = int((timer_min + timer_max) / 2)
        #print(timer)
        finished = 0
        free = []
        for i, m in enumerate(M): 
            finished += int(timer/m) + 1
            if timer % m == 0:
                free.append(i)
        if finished < N:
            timer_min = timer
            #timer = int((timer_min + timer_max)/2)
        elif N <= finished - len(free):
            # finished - len(free) is the finished number before this round
            timer_max = timer
            #timer = int((timer_min + timer_max)/2)
        else:
            order = N - (finished - len(free))
            #print('======')
            #print('timer:', timer)
            #print('N:', N)
            #print('finished:', finished)
            #print('order:', order)
            #print(free, order)
            return free[order-1] + 1

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
