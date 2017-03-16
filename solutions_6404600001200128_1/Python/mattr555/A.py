cases = int(input())

for case in range(cases):
    first, second = 0, 0
    n = int(input())
    l = list(map(int, input().split(' ')))

    rate = 0

    for i in range(1, n):
        diff = l[i-1] - l[i]
        if diff > 0:
            first += diff

        if diff > rate:
            rate = diff

    for i in l[:-1]:
        if rate > i:
            second += i
        else:
            second += rate

    #print('rate', rate)
    print('Case #{}: {} {}'.format(case+1, first, second))
