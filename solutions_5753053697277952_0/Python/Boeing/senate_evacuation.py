#!/bin/python
import sys
import numpy as np
if __name__ == '__main__':
    input_name = sys.argv[1] 
    output_name = sys.argv[2] if len(sys.argv) > 2 else input_name.split('.')[0] + '.out'
    f = open(input_name, 'r')
    f2 = open(output_name, 'w')
    nb_cases = int(f.readline().strip())
    party = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
    for i in range(1, nb_cases+1):
        print 'case ' + str(i)
        f2.write('Case #' + str(i) + ': ') 
        N = f.readline().strip()
        P = np.asarray(map(int, f.readline().strip().split(' ')), dtype = int)
        while np.sum(P) > 0:
           idx = np.argwhere(P == np.amax(P)).reshape(1, -1)[0]
           if P[idx[0]] == 1 and len(idx) % 2 == 1:
               idx = idx[:1]
           else:
               idx = idx[:2]
           if len(idx) == 1:
               P[idx[0]] -= 1
               f2.write(party[idx[0]] + ' ')
           else:
               P[idx[0]] -= 1
               P[idx[1]] -= 1
               f2.write(party[idx[0]] + party[idx[1]] + ' ')
        f2.write('\n')
    f.close()
    f2.close()
