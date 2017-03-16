#coding: utf8


s = '''\
4
2
2 2
3
3 2 2
3
1 1 2
3
2 3 1
'''

input = iter(s.splitlines(keepends=True))
import sys
out = sys.stdout
#input = open('A-small-attempt0.in')
#out   = open('A-small-attempt0.out', 'w')

input = open('A-large.in')
out   = open('A-large.out', 'w')

#input = open('B-large.in')
#out   = open('B-large.out', 'w')
#input = open('D-large-practice.in')
#out   = open('D-large-practice.out', 'w')



from itertools import combinations, permutations, combinations_with_replacement, product
from collections import defaultdict
from copy import deepcopy



def solve(S):
	ans = []
	while sum(S):
		maxi = -1
		maxi2= -1
		for i,_ in enumerate(S):
			if maxi==-1 or S[maxi] < S[i]:
				maxi2 = maxi
				maxi = i
			elif maxi2 == -1 or S[maxi2] < S[i]:
				maxi2 = i
				
		S[maxi] -= 1
		if S[maxi2] and sum(S) // S[maxi2] < 2:
			ans += [(maxi,maxi2)]
			S[maxi2] -= 1
		else:	
			ans += [(maxi,-1)]
	return ' '.join([chr(ord('A')+n) + (chr(ord('A')+k) if k !=-1 else '') for n,k in ans])
	
		
		
	
	

CaseCnt = int(next(input))
for case in range(CaseCnt):
	N = int(next(input))
	*S, = map(int, next(input).split())
	ans = solve(S)
	
	#c = str(c).rjust(len(C), '0')
	#j = str(j).rjust(len(J), '0')
	
	print('Case #%d:'%(case+1), ans, file=out)
