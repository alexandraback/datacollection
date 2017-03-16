import sys

def read_rows():
    return [[int(x) for x in sys.stdin.readline().split()] for _ in range(4)]

def solve(T):
    n1 = int(sys.stdin.readline())
    cand1 = read_rows()[n1-1]
    n2 = int(sys.stdin.readline())
    cand2 = read_rows()[n2-1]
    cand = set(cand1) & set(cand2)

    if len(cand) == 1:
        print("Case #{}: {}".format(T, list(cand)[0]))
    elif cand:
        print("Case #{}: Bad magician!".format(T))
    else:
        print("Case #{}: Volunteer cheated!".format(T))


T = int(sys.stdin.readline())

for t in range(1, T+1):
    solve(t)

