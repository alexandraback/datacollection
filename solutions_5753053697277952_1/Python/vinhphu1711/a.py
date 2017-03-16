import itertools
import numpy as np

def check(arr):
    total = sum([i[1] for i in arr])
    for i in arr:
        if i[1] > total / 2.0:
            return False
    return True

T = int(raw_input())

A = 65
for t in range(T):
    N = int(raw_input())
    arr = []
    c = 0
    total = 0
    for i in raw_input().split():
        arr.append([c, int(i)])
        total += int(i)
        c += 1
    
    #print arr
    res = ''
    count_zero = 0
    length = len(arr)
    while count_zero < length:
        arr = sorted(arr, key=lambda x: x[1], reverse=True)

        first = arr[0]
        second = arr[1]

        if total == 3 and count_zero == length - 3: # take only first
            res += chr(A+first[0]) + ' '
            first[1] -= 1
            total -= 1
            if first[1] == 0:
                count_zero += 1
        else:
            res += chr(A+first[0]) + chr(A+second[0]) + ' '
            first[1] -= 1
            total -= 1
            if first[1] == 0:
                count_zero += 1
            
            second[1] -= 1
            total -= 1
            if second[1] == 0:
                count_zero += 1

        if not check(arr):
            print 'Mother: ', 'Case #%d' % (t+1)
        
    print 'Case #%d: %s' % (t+1, res)
    #exit()