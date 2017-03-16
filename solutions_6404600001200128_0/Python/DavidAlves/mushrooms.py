T = int(raw_input())

for t in range(1, T+1):
    raw_input() #discard count
    arr = map(int, raw_input().split())

    eaten = 0
    count = arr[0]
    for i in arr[1:]:
        if i < count:
            eaten += count - i
        count = i
    y = eaten

    minrate = 0
    count = arr[0]
    for i in arr[1:]:
        if i < count:
            rate = count - i
            minrate = max(minrate, rate)
        count = i

    z = sum(min(minrate, i) for i in arr[:-1])

    print 'Case #{}: {} {}'.format(t, y, z)


