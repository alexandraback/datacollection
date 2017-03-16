import heapq
f = open('1.in')
out = open('1-out', 'w')
t = int(f.readline())
case = 1
for i in range(t):
    d = int(f.readline())
    arr = [int(x) for x in f.readline().strip().split()]
    print d
    print arr
    maxim = 0
    sum1 = 0
    sum2 = 0
    for i in range(d-1):
        diff = arr[i] - arr[i+1]
        if diff > maxim:
            maxim = diff
        if diff > 0:
            sum1 = sum1 + diff
    for i in range(d-1):
        diff = arr[i] - arr[i+1]
        if arr[i] < maxim:
            sum2 = sum2 + arr[i]
        else:
            sum2 = sum2 + maxim
    
    print sum1
    print sum2
    print '***'
    out.write('Case #' + str(case) + ': ' + str(sum1) + ' ' + str(sum2) + '\n')
    case = case + 1
out.close()
