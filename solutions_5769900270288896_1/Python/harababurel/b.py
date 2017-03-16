for t in range(0, input()):
    r, c, n = map(int, raw_input().split())

    free = 0
    shared = [0 for i in range(0, 5)]

    for i in range(0, r):
        onRow = c//2
        if c % 2 == 1 and i % 2 == 0:
            onRow += 1
        free += onRow

    if r % 2 == 0 or c % 2 == 0:
        shared[2] = 2

    shared[0] = free
    shared[3] = 2 * (c//2) + 2 * (r//2)
    shared[3] -= shared[2]
    shared[4] = r*c - sum(shared)

    sol = 0
    for i in range(0, 5):
        if n <= 0: break
        if n < shared[i]:
            shared[i] = n
        if n >= shared[i]:
            sol += shared[i] * i
            n -= shared[i]

    print "Case #%i: %i" % (t+1, sol)
