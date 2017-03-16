

def run(s):
    plan = []
    ss = list(s)
    while max(s) != min(s):
        maxi = 0
        for i in range(len(s)):
            if s[i] > s[maxi]:
                maxi = i
        plan.append(chr(ord('A') + maxi))
        s[maxi] -= 1
    while min(s) != 0:
        if len(s) == 2:
            plan.append('AB')
        elif len(s) == 3:
            plan.append('A')
            plan.append('BC')
        for i in range(len(s)):
            s[i] -= 1
    for p in plan:
        for e in p:
            ss[ord(e) - ord('A')] -= 1
        a = sum(ss)
        for k in ss:
            if k + k > a:
                print('XXX', ss, ' '.join(plan))
    return ' '.join(plan)


if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        N = int(input())
        s = list(map(int, input().split(' ')))
        print('Case #{}: {}'.format(t + 1, run(s)))
