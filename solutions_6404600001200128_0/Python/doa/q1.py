import sys

f = open(sys.argv[1],'r')
o = open(sys.argv[2],'w')

cases = int(f.readline().split()[0])

case = 1
while case<=cases:
    time = int(f.readline().split()[0])
    arr = f.readline().split()

    max_dec = 0

    result1 = 0
    prev = int(arr[0])
    for i in xrange(1,time):
        cur = int(arr[i])
        dif = prev-cur
        if dif>0:
            result1 += dif
            if dif > max_dec:
                max_dec = dif
        prev = cur

    result2 = 0
    for i in xrange(time-1):
        cur = int(arr[i])
        if cur < max_dec:
            result2 += cur
        else:
            result2 += max_dec

    o.write("Case #{}: {} {}\n".format(case, result1, result2))
    case += 1

o.close()
f.close()
