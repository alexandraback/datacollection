def solve():
    n = int(raw_input())
    l = [int(x) for x in raw_input().split()]
    assert len(l) == n
    diffs = [max(l[i]-l[i+1], 0) for i in range(n-1)]
    ans1 = sum(diffs)
    maxdiff = max(diffs)
    ans2 = sum(min(maxdiff, l[i]) for i in range(n-1))
    return ans1, ans2

for i in range(int(raw_input())):
    ans = solve()
    print "Case #%d: %d %d" % (i+1, ans[0], ans[1])
