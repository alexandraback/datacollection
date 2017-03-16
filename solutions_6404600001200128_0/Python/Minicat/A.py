fi = open("A-small-attempt1.in", "r")
fo = open("A-small-attempt1.out", "w")

T = int(fi.readline())

for case in xrange(1, T+1):

    N = int(fi.readline())
    mush = [int(x) for x in fi.readline().split()]

    # A: Eat any number at any time
    # Min at any time: strictly decreasing
    total_a = 0
    curr = mush[0]
    biggest_gap = 0 # this is for part B
    for m in mush[1:]:
        if m < curr:
            # ate some
            total_a += (curr - m)
        # for part B
        if curr - m > biggest_gap:
            biggest_gap = curr - m
        # update. 
        curr = m

    # B: Eat at a constant rate
    # 10 second gaps - assume the rate is the biggest gap
    total_b = 0
    rate = biggest_gap
    # you eat at the rate whenever you have to (decrease)
    # assume enough mushrooms get added back on later
    # make sure you dont go into negative mushrooms
    for i in xrange(0, len(mush) - 1):
        # no negative mushrooms
        total_b += mush[i] if mush[i] < rate else rate

    out = "Case #{}: {} {}".format(case, total_a, total_b)
    print out
    fo.write(out+"\n")




fi.close()
fo.close()
