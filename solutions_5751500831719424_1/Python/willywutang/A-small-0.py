def reader(inFile):
    n = inFile.getInt()
    strings = []
    for k in xrange(0,n):
        strings.append(inFile.readline())
    return strings

def solver(case):
    strings = case
    n = len(strings)
    k_mat = [ [] for i in xrange(0,n)] # each row is a list of keys
    v_mat = [ [] for i in xrange(0,n)] # each row is a list of values
    for i in xrange(0,n): # string index
        s = strings[i]
        m = len(s)
        p = 0 # index in ith values list
        for j in xrange(0,m): # character index
            if j == 0:
                k_mat[i].append(s[j])
                v_mat[i].append(1)
            else:
                if s[j] == s[j-1]:
                    v_mat[i][p] += 1
                else:
                    p += 1
                    k_mat[i].append(s[j])
                    v_mat[i].append(1)

        # if k_mat[i] != k_mat[i-1], preempt early, its impossible
        if i > 0:
            if "".join(k_mat[i]) != "".join(k_mat[i-1]):
                return "Fegla Won"

    # compute medians 
    q = len(v_mat[0])
    v = np.array(v_mat)
    medians = np.median(v, axis=0)

    # compute the sum of deviations from the median, in each column, and sum it up
    moves = 0
    for j in xrange(0,q):
        for i in xrange(0,n):
            moves += abs(v[i,j] - medians[j])

    return int(moves) 

# brute-forcing
def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return chain.from_iterable(combinations(s, r) for r in range(len(s)+1))   

# graphs 
def build_graph(edges):
    G = nx.Graph()
    for e in edges:
        [a,b] = e
        G.add_node(a)
        G.add_node(b)
        G.add_edge(a,b)
    return G
def degree_histogram(G):
    hist = Counter(nx.degree(G).values())   
    return hist

# binary search: find item in sorted list
def binary_search_aux(data,target,lo,hi):
    while lo <= hi:
        mid = (lo+hi)/2
        if data[mid] > target: # go down
            hi = mid-1
        elif data[mid] < target: # go up
            lo = mid+1
        else:
            return mid
    return False
def binary_search(data,target):
    return binary_search_aux(data,target,0,len(data)-1)

# binary search: find zero of a continuous function
def find_zero(f,lo,hi,k_max):
    """
    f = univariate function to find the zero of
    lo = lower bound on x 
    hi = upper bound on x
    k_max = number of iterations
    """
    k = 0
    while k < k_max:
        mid = float(lo+hi)/2
        if f(mid) > 0:
            hi = mid
        elif f(mid) < 0:
            lo = mid
        else:
            break
        k += 1
    return mid

if __name__ == "__main__":
    from GCJ import GCJ
    from itertools import chain, combinations, permutations, combinations_with_replacement
    from collections import Counter, defaultdict
    import networkx as nx
    import numpy as np
    import copy
    import random
    import datetime
    from math import log, sqrt, factorial, ceil
    from sympy import factorint, primerange, prime, divisors, nextprime, isprime, gcd
    from numpy import convolve
    from fractions import Fraction
GCJ(reader,solver,".","A").run()
