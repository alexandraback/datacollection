data = open("input/problemb.txt")
nb_cases = int(data.readline())



for z in xrange(nb_cases):
    print "Case #%d:" % (z + 1),
    # print
    B, N = [int(x) for x in data.readline().split(" ")]
    M = [int(x) for x in data.readline().split(" ")]

    max_m = max(M)
    period = max_m
    cont = True
    while cont:
        cont = False
        for j in xrange(B):
            if (period % M[j]) != 0:
                period += max_m
                cont = True
                break

    # print M, period

    # clients_per_period = 0
    # for j in xrange(B):
    #     clients_per_period += period / M[j]
    #
    #
    # before_me = (N-1) % clients_per_period
    # waiting_array = []
    # for j in xrange(B):
    #     for k in xrange(period / M[j]):
    #         waiting_array.append([M[j] * k, j])
    # waiting_array.sort()
    # print waiting_array[before_me][1] + 1
