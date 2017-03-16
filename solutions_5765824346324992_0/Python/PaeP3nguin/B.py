#! python3
from functools import reduce
import pdb

def gcd(a, b):
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def lcmm(*args):
    return reduce(lcm, args)

def main():
    with open("B-small-attempt1.in") as in_file:
        with open("B-small-attempt1.out", "w") as fout:
            cases = int(in_file.readline())
            for x in range(cases):
                line_1 = in_file.readline().replace('\n', '').split(' ')
                barber_num = int(line_1[0])
                place = int(line_1[1])

                barber_times = in_file.readline().replace('\n', '').split(' ')
                barber_times = [int(x) for x in barber_times]

                barber_chosen = 1

                lctime = lcmm(*barber_times)


                min_time = 0
                cust_served = 0
                for time in barber_times:
                    cust_served += lctime // time
                    if time > min_time:
                        min_time = time

                place = ((place - 1) % cust_served) + 1
                #pdb.set_trace()

                if place is not 0:
                    if place <= barber_num:
                        barber_chosen = place
                    else:
                        barber_chosen = find_barber(barber_num, lctime, barber_times, place)

                fout.write("Case #{0}: {1}\n".format(x + 1, barber_chosen))

def find_barber(barber_num, lctime, barber_times, place):
    place -= barber_num
    for time in range(1, lctime + 1):
        for i in range(barber_num):
            if time % barber_times[i] is 0:
                place -= 1
                if place is 0:
                    return i + 1

if __name__ == "__main__":
    main()
