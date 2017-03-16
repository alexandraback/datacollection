import numpy as np

fin = open('ain.txt', 'r')
fout = open('aout.txt', 'w')

T = int(fin.readline())

def solve():
    N = int(fin.readline())
    if N == 0:
        return "uhhh"
    parties = [int(i) for i in fin.readline().split()]

    sol = ""

    remaining = sum(parties)

    while remaining > 0:
        index = parties.index(np.amax(parties))
        sol += chr(ord("A") + index)
        parties[index] -= 1
        remaining -= 1

        for i in parties:
            if 2*i > remaining:
                index = parties.index(np.amax(parties))
                sol += chr(ord("A") + index)
                parties[index] -= 1
                remaining -= 1

        sol += " "
    
    return sol[:-1]

for i in range(T):
    fout.write("Case #" + str(i+1) + ": " + str(solve()) + "\n")

fin.close()
fout.close()
