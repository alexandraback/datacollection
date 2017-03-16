import numpy as np

def take_party(ps):
    i = np.argmax(ps)
    if ps[i] == 0:
        return None
    ps[i] -= 1
    return chr(65+i)

def check(ps):
    i = np.argmax(ps)
    return ps[i]*2 < sum(ps)

def solve(ps):
    answer = ''
    m = sum(ps)
    if m % 2 == 1:
        answer = take_party(ps) + ' '
        m -= 1

    while m > 0:
        p1 = take_party(ps)
        p2 = take_party(ps)
        answer += p1 + p2 + ' '
        m -= 2
    return answer.strip()

for c in range(input()):
    n = input()
    ps = map(int, raw_input().split())
    ans = solve(ps)
    print 'Case #{}: {}'.format(c+1, ans)
