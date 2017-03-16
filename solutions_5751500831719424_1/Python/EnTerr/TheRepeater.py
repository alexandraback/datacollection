#
# Google Code Jam 2014
# Roaund 1B: A. The Repeater
# submission by EnTerr
#

'''
Input
The first line of the input gives the number of test cases, T. T test cases follow. 
Each test case starts with a line containing an integer N which is the number of strings. 
Followed by N lines, each line contains a non-empty string (each string will consist of 
lower case English characters only, from 'a' to 'z').

Output
For each test case, output one line containing "Case #x: y", where x is the test case 
number (starting from 1) and y is the minimum number of moves to make the strings 
identical. If there is no possible way to make all strings identical, print 
"Fegla Won" (quotes for clarity).

Limits
1 <= T <= 100.
1 <= length of each string <= 100.

Small dataset   N = 2.
Large dataset   2 <= N <= 100.

Sample

--- Input 
5
2
mmaw
maw
2
gcj
cj
3
aaabbb
ab
aabb
2
abc
abc
3
aabc
abbc
abcc

---Output 
Case #1: 1
Case #2: Fegla Won
Case #3: 4
Case #4: 0
Case #5: 3

'''



import sys
from time import clock

f = open(sys.argv[1])
def input(): return f.readline().strip();

def theRepeater(strs):
    n = len(strs)
    res = 0
    while True:
        firsts = set(s[:1] for s in strs)
        #print firsts
        if len(firsts) != 1:
            return 'Fegla Won'
        ch = firsts.pop()
        if ch == '': break
        k = 1
        while k > 0:
            k = 0
            for i in range(n):
                if strs[i][:1] == ch:
                    strs[i] = strs[i][1:]
                    k += 1
            res += min(k, n-k)
    return res

#clk = clock()

for caseNo in xrange(1, int(input())+1):
    N = int(input())
    strs = [input() for _ in range(N)]
    print "Case #%d:" % caseNo, theRepeater(strs)
    
#print >>sys.stderr, 'time= %.1f seconds' % (clock()-clk )

