import numpy as np


def read_n_int(n):
    ints = [int(s) for s in input().split(" ")]
    if len(ints) != n:
        raise ValueError('Expected %i ints, got %i' % (n, len(ints)))
    if n == 1:
        return ints[0]
    return ints


t = read_n_int(1)
for i in range(1, t + 1):
    n = read_n_int(1)
    s = np.asarray(read_n_int(n))
    total = np.sum(s)
    print("Case #%i:" % i, end='')
    while total > 0:
        amax = np.argmax(s)
        print(' ' + chr(ord('A') + amax), end='')
        s[amax] -= 1
        #print(s)
        total -= 1
        if total == 0:
            break
        # Get another candidate
        amax = np.argmax(s)
        # Check if it implies problem
        s[amax] -= 1
        # print(s, np.max(s), (total - 1) / 2)
        if np.max(s) > ((total - 1) / 2):
            # not possible
            s[amax] += 1
        else:
            total -= 1
            #print(s)
            print(chr(ord('A') + amax), end='')
    print('')
