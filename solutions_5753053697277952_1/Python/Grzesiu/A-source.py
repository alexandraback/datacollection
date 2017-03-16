import imp, sys

sys.modules["utils"] = __mod = imp.new_module("utils")
exec """#!/usr/bin/python

from itertools import chain, repeat, izip

def line(*args):
	L = raw_input().strip().split()
	L = izip( L, chain( args, repeat(str) ) )
	return [ type(data) for data, type in L ]	
	
def iline(): return map( int, raw_input().strip().split() )
def fline(): return map( float, raw_input().strip().split() )""" in vars(__mod)

#!/usr/bin/python

from utils import iline

def test():
    iline()
    nums = iline()
    
    yield
    
    total = sum(nums)
    nums = [ [count, chr(ord('A')+i), i] for i, count in enumerate(nums) ]
    
    answer = ''
    while total > 0:
        count, c, i = max(nums)
        answer += c
        nums[i][0] -= 1
        total -= 1
        
        if total%2 == 0:
            answer += ' '
    print answer
        
        
        
        
if __name__ == '__main__':
    T = input()
    for i in xrange(1, T+1):
        print 'Case #%d:' % i,
        solver = test()
        if hasattr(solver, 'next'):
            list(solver)
        elif callable(solver):
            solver()

