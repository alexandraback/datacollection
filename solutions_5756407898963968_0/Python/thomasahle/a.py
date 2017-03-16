import sys
read = lambda: list(map(int,sys.stdin.readline().split()))
T, = read()
for t in range(T):
    s = set()
    i, = read()
    s = s.union([read() for _ in range(4)][i-1])
    i, = read()
    s = s.intersection([read() for _ in range(4)][i-1])
    if len(s) == 0:
        ans = "Volunteer cheated!"
    if len(s) == 1:
        ans = str(s.pop())
    if len(s) > 1:
        ans = "Bad magician!"
    print("Case #{}: {}".format(t+1, ans))
