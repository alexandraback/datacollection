from fractions import gcd


def myBarber(barbers, position):
    period = periodOfNoWait(barbers)
    cuts_per_period = sum([period//rate for rate in barbers])
    skip = (position-1)//cuts_per_period
    position -= skip*cuts_per_period

    wait = [0]*len(barbers)
    barber = 0
    for customer in range(1, position+1):
        wait, barber = serve(barbers, wait)
    return barber+1


def serve(barbers, wait):
    while 0 not in wait:
        wait = [w-1 for w in wait]
    barber = 0
    for barber, time_remaining in enumerate(wait):
        if time_remaining is 0:
            wait[barber] = barbers[barber]
            break
    return wait, barber


def periodOfNoWait(barbers):
    p = 1
    for barber in barbers:
        p = lcm(p, barber)
    return int(p)


def lcm(a, b):
    return (a * b) / gcd(a, b)

# filename = '.\data\default'
filename = '.\data\B-small-attempt1'
output = ''
with open(filename+'.in', 'r') as file:
    case_num = 0
    _ = file.readline()  # Number of cases
    line = file.readline()  # Number of plates with pancakes
    while line is not '':
        case_num += 1
        txt = line.strip('\n').split(' ')
        B, N = list(map(int, txt))
        txt = file.readline().strip('\n').split(' ')
        M = list(map(int, txt))
        print('case', case_num)
        output += 'Case #{}: {}\n'.format(case_num, myBarber(M, N))
        line = file.readline()

with open(filename+'.out', 'w') as file:
    file.write(output)