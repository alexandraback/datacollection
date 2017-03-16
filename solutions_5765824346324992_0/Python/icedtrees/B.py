cases = int(input())
for case in range(cases):
    B, q = map(int, input().split())
    m = list(map(int, input().split()))
    if q - B <= 0:
        print("Case #{}: {}".format(case+1, q))
        continue
    q = q - B - 1 
    upper = 1
    while True:
        times = sum(upper // mi for mi in m)
        if times > q:
            break
        upper *= 2
    lower = upper // 2
    while lower + 1 < upper:
        mid = (lower + upper) // 2
        times = sum(mid // mi for mi in m)
        if times > q:
            upper = mid
        else:
            lower = mid
    #print("lower is", lower)
    times = sum(lower // mi for mi in m)
    req = max(0, q - times)
    barbers = sorted((m[i] - (lower % m[i]), i) for i in range(B))
    #print(times, barbers)
    print("Case #{}: {}".format(case + 1, barbers[req][1]+1))
