import sys, re
import numpy as np



def solve(ws):
    def f(w):
        cs = []
        prev = None
        i = 0
        while i < len(w):
            if i == 0 or w[i] != w[i-1]:
                k = i+1
                while k < len(w) and w[k] == w[i]:
                    k += 1
                cs.append((w[i], k-i))
                i = k
            else:
                cs.append((w[i], 1))
                i += 1
        return cs
    ws = [f(w) for w in ws]
    if len(set([''.join(c for c, k in w) for w in ws])) > 1:
        return 'Fegla Won'
    else:
        M = np.array([[k for c, k in w] for w in ws])
        edits = 0
        cols = M.shape[1]
        rows = M.shape[0]
        for i in range(cols):
            emin = 2**30
            for j in range(np.min(M[:,i]), np.max(M[:,i])+1):
                D = np.zeros(rows, dtype=int) + j
                emin = min(emin, np.sum(np.abs(D - M[:,i])))
            edits += emin
        return edits

def main(filename):
    with open(filename) as f_in:
        total = int(f_in.readline())
        for i in range(1, total+1):
            N = int(f_in.readline())
            words = [None] * N
            for j in range(N):
                words[j] = f_in.readline().strip()
            #print guess1, row1, guess2, row2
            print( 'Case #{0}: {1}'.format(i, solve(words)))
            

if __name__ == "__main__":
    main(sys.argv[1])
