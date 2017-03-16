from multiprocessing import Pool, Manager
from copy import deepcopy
from itertools import *
from fractions import gcd

def gcd_cache(a, b, d):
    if (a, b) not in d:
        d[(a, b)] = gcd(a, b)
    return d[(a, b)]

def lcm(a, b, d):
    return (a * b) / gcd_cache(a, b, d)

def solve(solve_input):
    solve_input, memoize_dict = solve_input
    N, barbers = solve_input

    lcm_barbers = reduce(lambda a, b: lcm(a, b, memoize_dict), barbers)

    total_number_of_customers_in_cycle = sum(map(lambda x: lcm_barbers / x, barbers))

    final_order_in_cycle = N % total_number_of_customers_in_cycle

    barber_order = range(len(barbers)+1)

    print lcm_barbers, total_number_of_customers_in_cycle, final_order_in_cycle

    answer = 0
    if final_order_in_cycle > 0 and final_order_in_cycle <= len(barbers):
        answer = barber_order[final_order_in_cycle]
    else:
        i = min(barbers)
        last_customers_done = map(lambda x: (i - 1) / x, barbers)
        while i < lcm_barbers:
            customers_done = map(lambda x: i / x, barbers)

            new_customers_at_minute = map(lambda x: x[1] - x[0], zip(last_customers_done, customers_done))
            barber_order_at_minute = [j+1 for j, e in enumerate(new_customers_at_minute) if e == 1]

            barber_order += barber_order_at_minute

            last_customers_done = customers_done
            i += 1

        if final_order_in_cycle == 0:
            answer = barber_order[-1]
        else:
            answer = barber_order[final_order_in_cycle]

    return answer

def solve_file(filename, use_threadpool):
    fin = open(filename + '.in', 'r')
    fout = open(filename + '.out', 'w')
    #data read
    inputs = []
    T = int(fin.readline())
    for case in xrange(T):
        B, N = map(int, fin.readline().strip().split(' '))
        barbers = map(int, fin.readline().strip().split(' '))
        inputs.append((N, barbers))
    #solve
    answers = []
    if use_threadpool:
        manager = Manager()
        memoize_dict = manager.dict()
        inputs_with_dict = map(lambda x: (x, memoize_dict), inputs)
        thread_pool = Pool(10)
        answers = thread_pool.map(solve, inputs_with_dict)
    else:
        memoize_dict = dict()
        inputs_with_dict = map(lambda x: (x, memoize_dict), inputs)
        answers = map(solve, inputs_with_dict)
    #output
    for i in xrange(1, len(answers) + 1):
        fout.write(("Case #%d: " % i) + str(answers[i-1]) + "\n")

    fin.close()
    fout.close()

if __name__ == "__main__":
    solve_file("B-small-attempt1", True)
