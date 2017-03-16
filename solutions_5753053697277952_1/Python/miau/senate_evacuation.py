from heapq import heappop, heappush

def main():
    cases = int(input())
    for case in range(cases):
        n = int(input())
        ps = map(int, input().split())
        result = solve(n, ps)
        print("Case #%d: %s" % (case + 1, result))

def solve(n, ps):
    result = []
    h = []
    for i, p in enumerate(ps):
        heappush(h, (1000 - p, chr(ord("A") + i)))

    while len(h) > 0:
        # print(h, result)
        cs = ""
        n, c = heappop(h)
        if (len(h) == 0):
            result.append(c)
            break
        cs = c
        if n + 1 != 1000:
            heappush(h, (n + 1, c))

        # print(h, result)
        n, c = heappop(h)
        if len(h) == 1 and n == 1000 - 1:
            heappush(h, (n, c))
            result.append(cs)
            continue
        cs += c
        if n + 1 != 1000:
            heappush(h, (n + 1, c))
        result.append(cs)
    return " ".join(result)

main()
