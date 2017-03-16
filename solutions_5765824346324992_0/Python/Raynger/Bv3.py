def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

def lcm(a, b):
    return int((a * b) / gcd(a, b))

for c in range(int(input())):
    B, N = list(map(int, input().split()))
    time = list(map(int, input().split()))
    current = 0
    
    x = []
    pq = []
    
    for i in range(B):
        x.append(i+1)
        pq.append(time[i])
    
    rep = 1    
    for i in range(len(time)):
        rep = lcm(time[i], rep)
    
    #print(x)
    for i in range(rep-1):
        for j in range(B):
            pq[j] -= 1
            if pq[j] == 0:
                x.append(j+1)
                pq[j] = time[j]
    num = N % len(x)
    a = x[num-1]
                
    print("Case #{}: {}".format(c+1, a))
                