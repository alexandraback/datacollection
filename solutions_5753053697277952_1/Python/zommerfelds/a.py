import heapq

cases = int(input())
for c in range(cases):
    n = int(input())
    p = list(map(int, input().split()))
    q = []
    for i, x in enumerate(p):
        heapq.heappush(q, [-x, i])
    
    instructions = []
    while q:
        s = heapq.nsmallest(3, q)
        if (len(s) == 2 and s[0][0] == s[1][0]) or (len(s) == 3 and s[0][0] == s[1][0] and s[0][0] != s[2][0]):
            x1 = heapq.heappop(q)
            x2 = heapq.heappop(q)
            instructions.append((x1[1], x2[1]))
            x1[0] += 1
            x2[0] += 1
            if x1[0] != 0:
                heapq.heappush(q, x1)
            if x2[0] != 0:
                heapq.heappush(q, x2)
        else:
            x1 = heapq.heappop(q)
            instructions.append((x1[1],))
            x1[0] += 1
            if x1[0] != 0:
                heapq.heappush(q, x1)
    
    text = ' '.join(''.join(chr(ord('A') + e) for e in i) for i in instructions)
    print('Case #{}: {}'.format(c + 1, text))
