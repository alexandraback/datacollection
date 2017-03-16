import sys

def read_board():
    r = int(sys.stdin.readline())

    ans = None

    for i in range(1, 5):
        nums = map(int, sys.stdin.readline().split())

        if i == r:
            ans = set(nums)

    return ans

def solve():
    a = read_board()
    b = read_board()

    res = a & b
    if len(res) == 0:
        return 'Volunteer cheated!'
    elif len(res) > 1:
        return 'Bad magician!'
    else:
        res = res.pop()
        return str(res)

T = int(sys.stdin.readline())
for t in xrange(T):
    print 'Case #%d: %s' % (t+1, solve())
