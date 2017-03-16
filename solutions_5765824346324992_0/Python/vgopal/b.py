from Queue import PriorityQueue


def solve(B, N, M):
    if N <= B:
        return N
    queue = PriorityQueue()
    for i in range(B):
        queue.put((M[i], i))
    i = B + 1
    repeat_count = 1
    last_time = None
    while i < N:
        (time, barber) = queue.get()
        if last_time == time:
            repeat_count += 1
            if repeat_count == B:
                new_n = (N % (i - B)) or (i - B)
                return solve(B, new_n, M)
        else:
            repeat_count = 1

        last_time = time
        queue.put((M[barber] + time, barber))
        i += 1

    return queue.get()[1] + 1


input_file = open('b-small-1.in')
cases = int(input_file.readline().strip())
case = 0
while case < cases:
    case += 1
    B, N = [int(c) for c in input_file.readline().strip().split(' ')]
    M = [int(c) for c in input_file.readline().strip().split(' ')]
    print "Case #{}: {}".format(case, solve(B, N, M))
