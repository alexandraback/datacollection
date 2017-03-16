t = input()

def tot(r, c):
    return (4 * r * c - 2 * r - 2 * c) // 2

def checkboard(n, r, c):
    # number of neightbors for given size
    # 4 neighbors = # of cells in (side-2) board
    fours = (r-2) * (c-2)
    fours = fours // 2 + fours % 2
    # 3 neighbors = (side - 2) // 2
    threes = 0
    if r % 2 == 1 and c % 2 == 0:
        threes += r - 2
    else:
        threes += 2 * ((r // 2) - 1)
    if c % 2 == 1 and r % 2 == 0:
        threes += c - 2
    else:
        threes += 2 * ((c // 2) - 1)

    if r % 2 == 1 and c % 2 == 1:
        twos = 4
    else:
        twos = 2

    total = 0
    if n <= fours:
        return 4 * n
    total = 4 * fours
    n -= fours
    if n <= threes:
        return total + 3 * n
    total += 3 * threes
    n -= threes
    return total + 2 * n


def other(n, r, c):
    # top left corner not used
    #  even case is same by symmetry
    if r % 2 == 0 or c % 2 == 0:
        return checkboard(n, r, c)
    # dont count center for double odd
    fours = (r-2) * (c-2)
    fours = fours // 2
    # 3 neighbors = (side - 2) // 2
    threes = (r // 2)
    threes += (c // 2)
    threes *= 2
    twos = 0

    total = 0
    if n <= fours:
        return 4 * n
    total = 4 * fours
    n -= fours
    if n <= threes:
        return total + 3 * n
    total += 3 * threes
    n -= threes
    if n > 0:
        print 'FAILED'
        return None
    return total + 2 * n

def singleton(n, r, c):
    if (r * c) % 2 == 0 and n * 2 == r * c:
        return 2 * n - 1
    return 2 * n


for case in xrange(1, t+1):
    r, c, n = map(int, raw_input().split())
    val = None
    if n <= (r * c) // 2 + (r * c) % 2:
        val = 0
    else:
        n = r * c - n
        if min(r,c) == 1:
            val = singleton(n,r,c)
        else:
            val = max(checkboard(n,r,c), other(n,r,c))
        val = tot(r, c) - val
    print 'Case #%d: %d' % (case, val)

