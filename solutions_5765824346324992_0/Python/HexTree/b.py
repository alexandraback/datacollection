
def removed(M, time):
    num_removed = 0
    for x in M:
        num_removed += (time/x) + 1
    return num_removed

def next_barber(M, time, pos):
    array = []
    for i in range(len(M)):
        barber = i
        wait = (M[i] - (time%M[i]))
        array.append([wait, barber])
    array.sort()
    print array, pos
    return array[pos][1]+1

def bin_search(M, N, mini, maxi):
    if mini == maxi:
        return mini
    mid = (mini + maxi) / 2
    num_removed = removed(M, mid)
    if mini == maxi - 1:
        if removed(M, maxi) <= N-1:
            return maxi
        return mini
    elif num_removed <= N-1:
        return bin_search(M, N, mid, maxi)
    else:
        return bin_search(M, N, mini, mid-1)

g = open("data1.txt", 'w')
with open("data.txt", 'r') as f:
    T = int(f.readline())
    for r in range(T):
        B, N = [int(x) for x in f.readline().split()]
        M = [int(x) for x in f.readline().split()]
        max_wait = 100000000000
        time = bin_search(M, N, 0, max_wait)
        barber = next_barber(M, time, N-removed(M, time)-1)
        #print time, barber, removed(M, time), removed(M, time+1)
        g.write("Case #%d: %d\n" % (r+1, barber))
f.close()
g.close()