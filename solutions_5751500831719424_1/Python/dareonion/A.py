#!/usr/bin/env python
import itertools
import sys

def main():
    fname, gname = sys.argv[1:3]
    with open(fname) as f, open(gname, 'w') as g:
        T = int(f.readline().strip())
        for case_num in range(1, T+1):
            N = int(f.readline().strip())
            strs = []
            for _ in range(N):
                strs.append(f.readline().strip())

            result = get_result(strs)

            g.write('Case #{}: {}\n'.format(case_num, result))
            
    return 0

def collapse(s):
    return ''.join(k for k, _ in itertools.groupby(s))

def lengths(s):
    return [len(tuple(iterable))
            for _, iterable in itertools.groupby(s)]

def get_score(bank):
    bank = sorted(bank)
    l = len(bank)
    best_score = None
    for runlen in bank:
        next_score = sum(abs(tmp_runlen-runlen) for tmp_runlen in bank)
        # try runlen
        if best_score is None or next_score < best_score:
            best_score = next_score
    return best_score

def get_result(strs):
    uniques = {collapse(s) for s in strs}
    if len(uniques) != 1:
        return "Fegla Won"

    runlens = map(lengths, strs)
    score = sum(get_score(bank) for bank in zip(*runlens))
    
    return score

if __name__ == "__main__":
    status = main()
    sys.exit(status)
