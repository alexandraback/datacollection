def gcd(a, b):
    while b:      
        a, b = b, a % b
    return a


def lcm(a, b):
    return a * b // gcd(a, b)


def many_lcm(*args):
    ans = lcm(args[0], args[1])
    for a in args[2:]:
        ans = lcm(ans, a)
    return ans


def run_tick(barbers):
    return [max(b - 1, 0) for b in barbers]


def find_free_barber(barbers):
    if 0 in barbers:
        return barbers.index(0)
    else:
        return None


def add_customer(barbers, speeds):
    i = find_free_barber(barbers)
    if i is not None:
        barbers[i] = speeds[i]
    return barbers


def find_barber(customers, barbers, speeds):
    while customers > 1:
        while find_free_barber(barbers) is not None and customers > 1:
            barbers = add_customer(barbers, speeds)
            customers -= 1
        # print(barbers)
        if customers == 1:
            break
        barbers = run_tick(barbers)
    f = find_free_barber(barbers)
    while f is None:
        f = find_free_barber(barbers)
        barbers = run_tick(barbers)
        
    return f


def speedy_customers(speeds, customers):
    low_common = many_lcm(*speeds)
    served = 0
    for s in speeds:
        served += low_common // s
    ans = customers % served
    if ans == 0:
        return served
    else:
        return ans


tests = int(input())
for i in range(tests):
    barbers, position = [int(j) for j in input().split()]
    speeds = [int(j) for j in input().split()]
    position = speedy_customers(speeds, position)
    # print(position)
    ans = find_barber(position, [0 for _ in range(barbers)], speeds)
    print("Case #{}: {}".format(i + 1, ans + 1))