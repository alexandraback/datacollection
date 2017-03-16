'''
Problem A. Magic Trick

Small input
6 points	

Problem

Recently you went to a magic show. You were very impressed by one of 
the tricks, so you decided to try to figure out the secret behind it!

The magician starts by arranging 16 cards in a square grid: 4 rows of
cards, with 4 cards in each row. Each card has a different number from
1 to 16 written on the side that is showing. Next, the magician asks a
volunteer to choose a card, and to tell him which row that card is in.

Finally, the magician arranges the 16 cards in a square grid again, 
possibly in a different order. Once again, he asks the volunteer which
row her card is in. With only the answers to these two questions, the 
magician then correctly determines which card the volunteer chose. 
Amazing, right?

You decide to write a program to help you understand the magician's 
technique. The program will be given the two arrangements of the 
cards, and the volunteer's answers to the two questions: the row 
number of the selected card in the first arrangement, and the row 
number of the selected card in the second arrangement. The rows are 
numbered 1 to 4 from top to bottom.

Your program should determine which card the volunteer chose; or if 
there is more than one card the volunteer might have chosen (the 
magician did a bad job); or if there's no card consistent with the
volunteer's answers (the volunteer cheated).

Solving this problem

Usually, Google Code Jam problems have 1 Small input and 1 Large input. 
This problem has only 1 Small input. Once you have solved the Small 
input, you have finished solving this problem.

Input

The first line of the input gives the number of test cases, T. T test
cases follow. Each test case starts with a line containing an integer: 
the answer to the first question. The next 4 lines represent the first
arrangement of the cards: each contains 4 integers, separated by a 
single space. The next line contains the answer to the second 
question, and the following four lines contain the second arrangement 
in the same format.

Output

For each test case, output one line containing "Case #x: y", where x 
is the test case number (starting from 1).

If there is a single card the volunteer could have chosen, y should be
the number on the card. If there are multiple cards the volunteer 
could have chosen, y should be "Bad magician!", without the quotes. If
there are no cards consistent with the volunteer's answers, y should
be "Volunteer cheated!", without the quotes. The text needs to be 
exactly right, so consider copying/pasting it from here.

Limits

1 <= T <= 100.
1 <= both answers <= 4.
Each number from 1 to 16 will appear exactly once in each arrangement.

Sample

Input
       
3
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3
1 2 5 4
3 11 6 15
9 10 7 12
13 14 8 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
2
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Output
	
Case #1: 7
Case #2: Bad magician!
Case #3: Volunteer cheated!
'''

from collections import deque
#from decimal import Decimal
from sys import stdin, stderr
import copy
import fractions
import heapq
import itertools
import math
#import networkx as nx
import random
import re
import sys

sys.setrecursionlimit(100)

isa = isinstance
INF = 1 << 66

def solve(a,A,b,B):
    C = set(A[a-1]) & set(B[b-1])
    if len(C) == 1:
        ans = C.pop()
    elif len(C) == 0:
        ans = 'Volunteer cheated!'
    else:
        ans = 'Bad magician!'
    return ans

def check_test(A, B, data='', case=[0]):
    print
    print "test %d:" % case[0]
    print A
#   if abs(A-B) > 1e-9:
    if A != B:
        if data:
            print data
        print '>>>', A
        print '<<<', B
        print "!!!!!!!! FAIL !!!!!!!!"
    else:
        print ":::::::) OK"
    case[0] += 1

def unit_test():
    print
    a,A,b,B, ans = (
        2, ((1,2,3,4), (5,6,7,8), (9,10,11,12), (13,14,15,16),),
        3, ((1,2,5,4), (3,11,6,15), (9,10,7,12), (13,14,8,16),),
        7 )
    check_test(solve(a,A,b,B), ans)

def output():
    for case in xrange(1, int(stdin.next()) + 1):
        a = int(stdin.next())
        A = list()
        for _ in range(4):
            L = [int(i) for i in stdin.next().strip().split()]
            A.append(L)
        b = int(stdin.next())
        B = list()
        for _ in range(4):
            L = [int(i) for i in stdin.next().strip().split()]
            B.append(L)
        # print >>stderr, '--', case
        # if case in [12]:
        #     print >>stderr, A
        #     break
        # print >>stderr, A
        ans = solve(a,A,b,B)
        print 'Case #%d:' % case, ans
        print >>stderr, 'Case #%d:' % case, ans

if __name__ == '__main__':
#    unit_test()
    output()
