import heapq


fin = open('B-large.in','r')
fout = open('output.txt','w')
t = int(fin.readline())
for count in range(1, t + 1):
    [b,n] = [int(i) for i in fin.readline().split()]
    m = [int(i) for i in fin.readline().split()]
    speed = 0
    for i in range(0, b):
        speed += 1/m[i]
    approx = int(n / speed) - 100001
    print(approx)
    if approx < 0:
        approx = 0
    heap = []
    before = 0
    for i in range(0, b):
        before += int(approx / m[i]) + 1
    print(before)
    if before >= n:
        before = 0
        for i in range(0, b):
            heapq.heappush(heap, (0, i))
    else:
        for i in range(0, b):
            heapq.heappush(heap, (int(approx / m[i]) * m[i] + m[i], i))
    print(before)
    for i in range(0, n - 1 - before):
        current = heapq.heappop(heap)
        barber = current[1]
        heapq.heappush(heap, (current[0] + m[barber], barber))
    current = heapq.heappop(heap)
    fout.write('Case #'+str(count)+': '+ str(current[1] + 1) +'\n')
    print('Case #'+str(count)+': '+ str(current[1] + 1))
fin.close()
fout.close()
