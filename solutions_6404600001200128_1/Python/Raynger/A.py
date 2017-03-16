for c in range(int(input())):
    N = int(input())
    v = list(map(int, input().split()))
    
    a = 0
    prev = v[0]
    for i in range(1, len(v)):
        current = v[i]
        if prev > current:
            a += prev - current
        prev = current
    
    
    max_rate = 0
    prev = v[0]
    for i in range(1, len(v)):
        current = v[i]
        rate = max(prev - current, 0)
        max_rate = max(rate, max_rate)
        prev = current
    
        #print(max_rate)
    b = 0
    for i in range(len(v)-1):
        current = v[i]
        if current - max_rate <= 0:
            b += current
        else:
            b += max_rate
    
    
    print("Case #{}: {} {}".format(c+1, a, b))
                