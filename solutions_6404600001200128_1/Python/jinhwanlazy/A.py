def solve(N, lst):
    ans1 = 0
    for i in range(N-1):
        if lst[i] > lst[i+1]:
            ans1 += lst[i] - lst[i+1]

    speed = 0
    for i in range(N-1):
        speed = max(speed, lst[i]-lst[i+1])
    ans2 = 0
    for i in range(N-1):
        ans2 += min(speed, lst[i])

    return ' '.join((str(ans1), str(ans2)))

if __name__ == '__main__':
    for case in range(int(input())):
        N = int(input())
        lst = list(map(int, input().split()))
        print("Case #%d: %s" % (case+1, solve(N, lst)))

