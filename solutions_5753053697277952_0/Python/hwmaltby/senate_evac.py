#Henry Maltby
#Code Jam 2016

def senate_evac(lst):
    """
    Keeps parties as close to parity as possible. Solve time high but within
    constraints. Last two senators to leave always leave together.
    """
    exits = []
    while sum(lst) > 0:
        values = max_info(lst)
        if len(values) == 2:
            exits.append(chr(values[0] + 65) + chr(values[1] + 65))
            lst[values[0]] -= 1
            lst[values[1]] -= 1
        else:
            exits.append(chr(values[0] + 65))
            lst[values[0]] -= 1
    return ' '.join(exits)


def max_info(lst):
    """
    Returns the indices that obtain the max value of lst. (Assumed values pos.)
    """
    k = []
    maxm = -1
    for i in range(len(lst)):
        if lst[i] == maxm:
            k.append(i)
        if lst[i] > maxm:
            maxm = lst[i]
            k = [i]
    return k

def sum(lst):
    """
    Returns the sum of the values in a lst.
    """
    total = 0
    for i in lst:
        total += i
    return total

f = open('A-small.in')
g = open('A-small.out', 'w')

T = int(f.readline())
for i in range(T):
    N = int(f.readline())
    parties = [int(x) for x in f.readline().split(' ')]
    g.write("Case #" + str(i + 1) + ": " + senate_evac(parties) + "\n")
