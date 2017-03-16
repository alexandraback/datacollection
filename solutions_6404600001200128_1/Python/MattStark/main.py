import sys
lines = open(sys.argv[1] + ".in", "rU").read().split("\n")
t, lines = int(lines[0]), lines[1:]

outfile = open(sys.argv[1] + ".out", "w")

for i in range(t):
    a = list(map(int, lines[i * 2 + 1].split()))
    b = [max(0, a[i] - a[i + 1]) for i in range(len(a) - 1)]
    out = max(b)
    out = sum(min(i, out) for i in a[:-1])
    print("Case #{}: {} {}".format(i + 1, sum(b), out), file=outfile)

