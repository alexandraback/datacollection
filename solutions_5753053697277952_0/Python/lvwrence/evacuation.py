import string
num2alpha = dict(zip(range(0, 26), string.ascii_uppercase))

def evacuation(parties):
    order = []

    while any(party != 0 for party in parties):
        maxes = get_maxes(parties)
        for i in maxes:
            parties[i] -= 1

        steps = ''.join(num2alpha[max] for max in maxes)
        order.append(steps)

    return ' '.join(order)

def get_maxes(parties):
    # get maxes
    max_party = max(parties)

    # need to get a smarter way
    maxes = [i for i, j in enumerate(parties) if j == max_party]
    if max_party == 1:
        # if they're all ones, we need to be careful with this and make sure we don't end up removing
        # with one left over.
        if len(maxes) % 2 == 0:
            # even number of 1's left: we're good
            return maxes[:2]
        else:
            # otherwise, pick off the first one
            return [maxes[0]]
    else:
        return maxes[:2]



if __name__ == '__main__':
    # raw_input() reads a string with a line of input, stripping the '\n' (newline) at the end.
    # This is all you need for most Google Code Jam problems.
    t = int(raw_input())  # read a line with a single integer
    for i in xrange(1, t + 1):
        n = int(raw_input())
	lst = [int(s) for s in raw_input().split(" ")]  # read a list of integers , each party
	print "Case #{}: {}".format(i, evacuation(lst))
	# check out .format's specification for more formatting options
