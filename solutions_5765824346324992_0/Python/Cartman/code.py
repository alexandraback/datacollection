def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def gcdd(*args):
    return reduce(gcd, args)

def lcm(a, b):
    return a * b // gcd(a, b)

def lcmm(*args):
    return reduce(lcm, args)

for case in range(int(raw_input())):
    b, n = map(int, raw_input().split(' '))
    times = map(int, raw_input().split(' '))

    gcd_times = gcdd(*times)
    lcm_times = lcmm(*times)
    nr_per_cycle = sum([lcm_times / times[i] for i in range(b)])
    n_reduced = n % nr_per_cycle
    if n_reduced == 0:
        n_reduced = nr_per_cycle

    count = 0
    minutes = 0
    barber = 0
    while True:
        for i in range(b):
            time = times[i]
            if (minutes % time) == 0:
                barber = i+1
                count += 1
            if count == n_reduced:
                break
        if count == n_reduced:
            break
        minutes += gcd_times

    print 'Case #'+ str(case+1) + ': ' + str(barber)
