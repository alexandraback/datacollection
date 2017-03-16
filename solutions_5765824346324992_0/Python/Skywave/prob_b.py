def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:
        a, b = b, a % b
    return a


def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)


def lcmm(args_list):
    """Return lcm of args."""
    result = args_list[0]

    for arg in args_list:
        result = lcm(result, arg)

    return result

in_file = open('B-small-attempt0.in', 'r')
out_file = open('out.txt', 'w')

total_case_count = int(in_file.readline())

for i in range(total_case_count):
    barber_count, line_count = [int(x) for x in in_file.readline().split()]
    barber_time = [int(x) for x in in_file.readline().split()]
    barber_time_min = min(barber_time)
    line_count -= 1

    loop_time = lcmm(barber_time)
    loop_count = 0

    for time in barber_time:
        loop_count += loop_time / time

    loop_count = int(loop_count)
    line_count %= loop_count

    max_time = barber_time_min * (line_count + 1)

    barbers = list()
    for j in range(barber_count):
        time = barber_time[j]
        total_time = 0

        while total_time <= max_time:
            barbers.append((total_time, j))
            total_time += time

    time_list = list()
    comparison = [None] * barber_count

    barbers = sorted(barbers, key=lambda x: (x[0], x[1]))
    out_file.write('Case #{}: {}\n'.format(i + 1, barbers[line_count][1] + 1))



in_file.close()
out_file.close()