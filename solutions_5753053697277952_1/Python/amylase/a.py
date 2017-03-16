from string import ascii_uppercase
from heapq import nlargest


def choose(xs):
    if sum(xs) % 2 == 1:
        m = -1, -1
        for i, x in enumerate(xs):
            if m < (x, i):
                m = x, i
        xs[m[1]] -= 1
        return ascii_uppercase[m[1]]
    choice = nlargest(2, [(x, i) for i, x in enumerate(xs)])
    xs[choice[0][1]] -= 1
    xs[choice[1][1]] -= 1
    return ascii_uppercase[choice[0][1]] + ascii_uppercase[choice[1][1]]


def solve():
    n = raw_input()
    xs = map(int, raw_input().strip().split())
    ans = []
    while sum(xs) > 0:
        ans.append(choose(xs))
    return ' '.join(ans)


if __name__ == '__main__':
    n = int(raw_input())
    for i in range(n):
        print("Case #{}: {}").format(i+1, solve())