import sys

def gcd(x,y):
    while y:
        x, y = y, x%y
    return x

def lcm(x,y):
    r = x * y // gcd(x,y)
    return r

def lcm_arr(arr):
    return reduce(lcm, arr)

f = open(sys.argv[1],'r')
o = open(sys.argv[2],'w')

cases = int(f.readline().split()[0])

case = 1
while case<=cases:
    line = f.readline().split()
    bar = int(line[0])
    index = int(line[1])
    arr = f.readline().split()
    nums = [int(num) for num in arr]
    _lcm = lcm_arr(nums)
    
    d = dict()
    d[0] = [b for b in xrange(1,bar+1)]
    for i,num in enumerate(nums):
        x = num
        while x < _lcm:
            if x not in d:
                d[x] = [i+1]
            else:
                d[x].append(i+1)
            x += num
    
    total_customers = 0
    times = []
    for k,v in d.items():
        times.append((k,v))
        total_customers += len(v)
    times.sort()

    ntimes = len(times)
    index %= total_customers
    if index == 0:
        index = total_customers

    result = 0
    prev = 0
    for t,bars in times:
        if prev+len(bars) >= index:
            bars.sort()
            i = 1
            while prev+i < index:
                i += 1
            result = bars[i-1]
            break            
        prev += len(bars)

    o.write("Case #{}: {}\n".format(case, result))
    case += 1

o.close()
f.close()
