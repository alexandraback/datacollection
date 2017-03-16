
import sys

T = int(sys.stdin.readline())

def read_board():
    ret = []
    for i in range(0, 4):
        ret.append([int(n) for n in sys.stdin.readline()[:-1].split(' ')])
    return ret

def size(s):
    ret = 0
    for i in s:
        ret += 1
    return ret

for i in range(1, T+1):
    guess1 = int(sys.stdin.readline())
    board1 = read_board()
    guess2 = int(sys.stdin.readline())
    board2 = read_board()

    p1 = set(board1[guess1 - 1])
    p2 = set(board2[guess2 - 1])
    p = p1.intersection(p2)
    n = size(p)

    if n == 1:
        print "Case #{}: {}".format(i, p.pop())
    elif n > 0:
        print "Case #{}: Bad magician!".format(i)
    else:
        print "Case #{}: Volunteer cheated!".format(i)
