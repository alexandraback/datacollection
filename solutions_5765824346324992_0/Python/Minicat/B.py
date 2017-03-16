# fi = open("B-sample.in", "r")
# fo = open("B-sample.out", "w")
fi = open("B-small-attempt1.in", "r")
fo = open("B-small-attempt1.out", "w")

T = int(fi.readline())

# http://stackoverflow.com/questions/185781/finding-the-lcm-of-a-range-of-numbers
def lcm(a,b):
    gcd, tmp = a,b
    while tmp != 0:
        gcd,tmp = tmp, gcd % tmp
    return a*b/gcd

for case in xrange(1, T+1):
    B, N = [int(x) for x in fi.readline().split()]
    b_time = [int(x) for x in fi.readline().split()]

    # LCM: 
    period = reduce(lcm, b_time)

    # Generate table for 1 period
    table = []
    # Entries: tuple of (time, barber) to tiebreak on barber (and retrieve result!)
    for barber in xrange(1, B+1):
        time = b_time[barber-1] # since barber count starts at 1
        table += [(i*time, barber) for i in xrange(0, period/time)]
    # sort it
    table.sort()
    # you dont actually need the times anymore (i think)
    table = [x[1] for x in table]

    # k so people get served in "periods" of len(table)
    period_size = len(table)

    # mod it
    you = N % period_size

    # But if you're like, the period size, this causes problems.
    if you == 0:
        you = period_size

    # and this should be your time
    your_barber = table[you - 1] # excellent variable naming

    out = "Case #{}: {}".format(case, your_barber)
    print out
    fo.write(out+"\n")

fi.close()
fo.close()
