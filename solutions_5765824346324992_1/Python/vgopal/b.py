# from Queue import PriorityQueue

def num_served(B, N, M, t):
    people = 0
    done = 0
    for m in M:
        people += t / m
        if t % m == 0:
            done += 1
        else:
            people += 1
    return (people, done)


def kth_barber(M, t, k):
    for i, m in enumerate(M):
        if t % m == 0:
            k -= 1
            if k == 0:
                return i


def solve(B, N, M):
    if N <= B:
        return N

    t = 0
    while True:
        (people, done) = num_served(B, N, M, t)
        if people >= N:
            break
        if t == 0:
            t += 1
        else:
            t *= 2

    lower = t / 2 - 1
    higher = t + 1
    t = (higher + lower) / 2
    while True:
        people, done = num_served(B, N, M, t)
        if people < N <= people + done:
            break
        elif N > people + done:
            lower = t + 1
            t = max(lower, (higher + t) / 2)
        else:
            higher = t - 1
            t = min((lower + t) / 2, higher)

    k = (N - people)
    barber = kth_barber(M, t, k)
    return barber + 1


input_file = open('b-large.in')
cases = int(input_file.readline().strip())
case = 0
while case < cases:
    case += 1
    B, N = [int(c) for c in input_file.readline().strip().split(' ')]
    M = [int(c) for c in input_file.readline().strip().split(' ')]
    print "Case #{}: {}".format(case, solve(B, N, M))
