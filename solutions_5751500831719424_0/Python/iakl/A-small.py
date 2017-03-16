# IO file paths
file_in = "A-small-attempt0.in"
file_out = "A-small-attempt0.out"

import math

# Solves the deceitful war problem
def Solve(N, inp):
    lost = "Fegla Won"
    sinp = Simplify(N, inp)
    for ss in sinp:
        if sinp[0] != ss:
            return lost
    key = sinp[0]
    count = 0
    for i in range(0, len(key)):
        count = count + CountSteps(N, inp, key, i)
    return str(count)

def Simplify(N, inp):
    sinp = []
    for i in range(0, N):
        prev = ''
        ss = ""
        for ch in inp[i]:
            if '' == ch or '\n' == ch:
                continue
            if  '' == prev:
               ss = ss + ch
            else:
                if prev != ch:
                    ss = ss + ch
            prev = ch
        sinp.append(ss)
    return sinp

def CountSteps(N, inp, key, i):
    nums = []
    kch = key[i]
    for j in range(0, N):
        prev = ''
        pos = 0
        chcount = 0
        for ch in inp[j]:
            if '' != prev:
                if ch != prev:
                    pos = pos + 1
            prev = ch
            if pos == i:
                if ch == kch:
                    chcount = chcount + 1
                else:
                    break
        nums.append(chcount)
    return CountMin(N, nums)

def CountMin(N, nums):
    res = -1
    snums = sorted(nums)
    nmin = snums[0]
    nmax = snums[len(snums) - 1]
    for num in range(nmin, nmax + 1):
        c = 0
        for nn in snums:
            c = c + int(abs(nn - num))
        if -1 == res or c < res:
            res = c
    return res

# Reads the input data and runs the test cases
def Run():
    fin = open(file_in, 'r')
    fout = open(file_out, 'w')

    lines = []
    for l in fin:
        lines.append(l)

    i = 0
    T = int(lines[0])
    i = i + 1
    for t in range(0, T):
        N = int(lines[i].rstrip())
        i = i + 1
        inp = []
        for _ in xrange(0, N):
            l = lines[i]
            i = i + 1
            inp.append(l)
        result = Solve(N, inp)
        fout.write("Case #" + str(t + 1) + ": " + result + '\n')
        
    fin.close()
    fout.close()
    

def main():
    Run()

if __name__ == "__main__":
    main()
