import numpy as np
from math import ceil
import math, functools

def parse(input_file, output_file):
    with open(input_file) as f:
        n_cases = int(f.readline().split()[0])
        data = dict()
        bs = [0] * n_cases
        ns = [0] * n_cases
        for i in range(n_cases):
            line = f.readline().split()
            bs[i] = int(line[0])
            ns[i] = int(line[1])
            data[i] = [int(x) for x in f.readline().split()]
    f = open(output_file, 'w')
    for i in range(n_cases):
        ans1 = solve1(bs[i], ns[i], data[i])
        line = "Case #"+str(i+1)+": "+str(ans1)
        print(line)
        f.write(line+'\n')
    return

def test(queue, height):
    for (x,y) in zip(queue[:-1], queue[1:]):
        if height[x] > height[y]:
            return False
        if height[x] == height[y] and x>y:
            return False
    #print("tested true")
    return True

#pre_lcm(3,8,[4,2,1])

def solve1(b, n, mks):
    n = pre_lcm(b, n, mks)
    #print(n)
    if n <= b:
        return n
    number = b
    height = np.array(mks.copy())
    queue = np.argsort(mks, kind='mergesort')
    while number < n:
        height0 = height[queue[0]]
        height1 = height[queue[1]]
        #if not height0 <= height1:
            #raise ValueError("!!!")
        if height0 == height1:
            multiple = 1
        else:
            multiple = ceil((height1-height0)/mks[queue[0]])
        height[queue[0]] += multiple*mks[queue[0]]
        #if not height[queue[0]] >= height1:
            #raise ValueError("!!!!!")
        number += multiple
        if number >= n:
            return queue[0]+1
        if np.random.random() > 0.5:
            height -= height1

        pos = 0
        while pos < b-1:
            current_height = height[queue[pos]]
            next_height = height[queue[pos+1]]
            if current_height > next_height:
                queue[pos], queue[pos+1] = queue[pos+1], queue[pos]
                pos += 1
                continue
            if current_height == next_height and queue[pos] > queue[pos+1]:
                queue[pos], queue[pos+1] = queue[pos+1], queue[pos]
                pos += 1
                continue
            break

        #if not test(queue, height):
            #raise ValueError("not sorted")

    raise ValueError('the end?')
    return -1

def gcd(a, b):
    """Return greatest common divisor using Euclid's Algorithm."""
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

def lcmm(*args):
    """Return lcm of args."""
    return functools.reduce(lcm, args)

def lcmmm(args):
    if len(args)== 2:
        return lcm(args[0], args[1])
    else:
        return lcm(args[0], lcmm(args[1:]))

def pre_lcm(b,n,mks):
    m = lcmm(*mks)
    sum = 0
    for i in mks:
        sum += m//i
    if n%sum == 0:
        return sum
    else:
        return n%sum



input_file = "./2015-1A/B_test.txt"
input_file = "./2015-1A/B-small-attempt0.in"
input_file = "./2015-1A/A-large.in"
output_file = "./2015-1A/B-test.txt"
output_file = "./2015-1A/B-out-0.txt"

input_file = "./2015-1A/B-small-attempt1.in"
output_file = "./2015-1A/B-out-1.txt"
parse(input_file, output_file)
