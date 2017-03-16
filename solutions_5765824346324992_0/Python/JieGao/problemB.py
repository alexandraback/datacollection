import math
import time
import sys
from collections import OrderedDict

if __name__ == '__main__':
    
    # Start timer
    start = time.time()

    if len(sys.argv) != 3:
        print 'Usage: python problemB.py <input_file> <output_file>'
        sys.exit(0)
    
    input_file = sys.argv[1]
    output_file = sys.argv[2]

    lines = [line.strip() for line in open(input_file)]
    total = lines.pop(0)
    par = lines[0:][::2]
    mk = lines[1:][::2]

    results = []
    for i in range(len(mk)):
        print "Processing case", i+1
        B = int(par[i].split()[0])
        N = int(par[i].split()[1])
        mk[i] = [int(m) for m in mk[i].split()]
        barber_idx = 0
        if N <= B:
            barber_idx = N
            results.append(barber_idx)
            continue
        if min(mk[i]) == max(mk[i]):
            barber_idx = N%B
            if barber_idx == 0:
                barber_idx = B
            results.append(barber_idx)
            continue
        current = {}
        current[0] = list(xrange(B))
        barber_list = []
        for j in xrange(N):
            min_key = min(current.keys())
            barber = current[min_key].pop(0)
            barber_list.append(barber)
            if not current[min_key]:
                current.pop(min_key,None)
            new_key = mk[i][barber] + min_key
            if new_key in current:
                current[new_key].append(barber)
                current[new_key] = sorted(current[new_key])
            else:
                current[new_key] = [barber]
            if len(current) == 1:
                barber_idx = (N-1)%len(barber_list)
                barber_idx = barber_list[barber_idx] + 1
                results.append(barber_idx)
                break
        if barber_idx == 0:
            results.append(barber+1)
        else:
            continue
    print results

    # output
    f = open(output_file, 'w')
    for i in range(len(results)):
        f.write('Case #' + str(i+1) + ': ' + str(results[i]) +'\n')
    f.close()

    # Stop timer
    end = time.time()
    print "Total time use:", end-start, "s"