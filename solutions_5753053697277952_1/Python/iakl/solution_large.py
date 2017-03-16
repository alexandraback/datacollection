input_file = "A-large.in"
output_file = "A-large.out"

in_f = open(input_file)
T = -1
N = -1
tcs = []
for l in in_f:
    sl = l.strip()
    if len(sl) == 0:
        continue
    if T == -1:
        T = int(sl)
        continue
    if N == -1:
        N = int(sl)
    else:
        sl = sl.split(' ')
        tc = []
        for i in range(0, N):
            tc.append(int(sl[i]))
        tcs.append(tc)
        N = -1
    
in_f.close()

out_f = open(output_file, "w")
def OutputTestCase(tcn, x):
    s = ""
    L = len(x)
    for i in range(0, L):
        if i > 0:
            s = s + ' '
        s = s + x[i]
    out_f.write("Case #" + str(tcn) + ": " + s + "\n")

def Ch(i):
    return chr(ord('A') + i)

def Swap(arr, i, j):
    v = arr[i]
    arr[i] = arr[j]
    arr[j] = v

def SolveTestCase(tc):
    l = []
    N = len(tc)
    s = 0
    for i in range(0, N):
        l.append([tc[i], i])
        s += tc[i]
    l.sort(reverse = True)
    r = []
    while s > 0:
        nxt = ""
        nxt += Ch(l[0][1])
        l[0][0] -= 1
        s -= 1
        if s > 0:
            p = 0
            while p < N - 1 and l[p][0] < l[p + 1][0]:
                Swap(l, p, p + 1)
                p += 1
        if s > 0 and N > 1 and s - 1 >= 2 * max(l[1][0], l[0][0] - 1):
            nxt += Ch(l[0][1])
            l[0][0] -= 1
            s -= 1
            if s > 0:
                p = 0
                while p < N - 1 and l[p][0] < l[p + 1][0]:
                    Swap(l, p, p + 1)
                    p += 1
        r.append(nxt)
    return r
    
#print tcs
for i in range(0, T):
    print "Case #" + str(i + 1)
    r = SolveTestCase(tcs[i])
    #print r
    OutputTestCase(i + 1, r)

out_f.close()

