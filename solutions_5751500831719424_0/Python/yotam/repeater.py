#!/usr/bin/env python
import sys

fin = sys.stdin
fout = sys.stdout
ferr = sys.stderr

def ew(s):
    ferr.write("%s\n" % s)
    # pass

def get_io(argv):
    fin = sys.stdin
    fout = sys.stdout
    ifn = ofn = "-"
    if len(argv) == 2:
        bfn = sys.argv[1]
        ifn = bfn + '.in'
        ofn = bfn + '.out'
    if len(argv) > 2:
        ifn = argv[1]
        ofn = argv[2]
    if ifn != '-':
        fin = open(ifn, "r")
    if ofn != '-':
        fout = open(ofn, "w")
    return (fin, fout)

def get_numbers():
    line = fin.readline()
    return map(int, line.split())

def get_number():
    return get_numbers()[0]

def get_line():
    line = fin.readline()
    if len(line) > 0 and line[-1] == '\n':
        line = line[:-1]
    return line

def get_string():
    line = fin.readline()
    return line.strip()

class Repeater:

    def __init__(self, fin):
        self.n = get_number()
        self.fegla = []
        self.canons = []
        for k in range(self.n):
            s = get_string()
            self.fegla.append(s)
            self.canons.append(self.canonize(s))
        # ew("fegla=%s\n,  canons=%s" % (self.fegla, self.canons))


    def canonize(self, s):
        canon = ""
        last = ""
        for c in s:
            if last != c:
                canon += c
                last = c
        return canon
        

    def solve(self):
        ret = "0"
        match = True
        i = 1
        canon0 = self.canons[0]
        while match and i < self.n:
            match = (canon0 == self.canons[i])
            i += 1
        if match:
            ret = "%d" % self.min_moves()
        else:
            ret = "Fegla Won"
        return ret
    
    def min_moves(self):
        moves = 0
        pos = self.n * [0]
        counts = self.n * [None]
        for c in self.canons[0]:
            nums = self.n * [0]
            for fi in range(self.n):
                fegla = self.fegla[fi]
                counti = 0
                p = pos[fi]
                while p < len(fegla) and fegla[p] == c:
                    p += 1
                    counti += 1
                pos[fi] = p
                counts[fi] = counti
            moves += self.single_min_moves(counts)
        return moves

    def single_min_moves(self, counts):
        m = min(counts)
        M = max(counts)
        best = (M + 1)*len(counts) # infinity
        besti = -1
        for k in range(m, M + 1):
            moves = 0
            for count in counts:
                moves += abs(count - k)
            # ew("k=%d, moves=%d" % (k, moves))
            if best > moves:
                best = moves
                besti = k
        # ew("single_min_moves: counts=%s, m=%d, M=%d, besti=%d, ret=%d" % 
        #    (counts, m, M, besti, best))
        return best
    

def single_min_moves(counts):
    m = min(counts)
    M = max(counts)
    best = (M + 1)*len(counts) # infinity
    besti = -1
    for k in range(m, M + 1):
        moves = 0
        for count in counts:
            moves += abs(count - k)
        ew("k=%d, moves=%d" % (k, moves))
        if best > moves:
            best = moves
            besti = k
    ew("single_min_moves: m=%d, M=%d, besti=%d" % (m, M, besti))
    return best
    
    
if __name__ == "TEST__main__":
    counts = get_numbers()
    r = single_min_moves(counts)
    ew("single_min_moves(%s) = %d" % (counts, r))
    sys.exit(0)

if __name__ == "__main__":
    (fin, fout) = get_io(sys.argv)
    n_cases = get_number()
    for ci in range(n_cases):
        repeater = Repeater(fin)
        r = repeater.solve()
        fout.write("Case #%d: %s\n" % (ci + 1, r))

    fin.close()
    fout.close()
    sys.exit(0)
