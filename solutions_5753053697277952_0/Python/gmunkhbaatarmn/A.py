import sys
sys.stdin = open("input.txt")
sys.stdout = open("output.txt", "w+")


def solve(N, P):
    result = []
    counts = [[p, chr(ord("A") + i)] for i, p in enumerate(P)]


    while sorted(counts)[-1][0] > 0:
        item = ""

        counts = list(reversed(sorted(counts)))
        item += counts[0][1]
        counts[0][0] -= 1

        counts = list(reversed(sorted(counts)))
        item += counts[0][1]
        counts[0][0] -= 1

        if not check(counts) or counts[0][0] < 0:
            item = item[:1]
            counts[0][0] += 1

        result.append(item)

    return " ".join(result)


def check(counts):
    counts = list(reversed(sorted(counts)))
    return counts[0][0] <= sum(c[0] for c in counts[1:])


for T in range(1, int(raw_input()) + 1):
    N = int(raw_input())
    P = map(int, raw_input().split())
    answer = solve(N, P)

    print "Case #%s: %s" % (T, answer)
