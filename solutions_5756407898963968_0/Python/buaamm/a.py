# -*- coding: utf-8 -*-
# Google Code Jam
# Create Date: 2014-04-10
# Created by: buaamm
#--------------------------------------------------------------------
import sys
import os

def nextint():
	return (int)(fr.readline())

def next():
	return fr.readline()

def write(s):
	fw.write(s)
	
def writeline(s):
	fw.write(s + "\n")

def repeat(s, r):
	for i in range(r):
		fw.write(s)

def reprep(s, len, r):
	for i in range(r):
		repeat(s, len)
		write("\n")
		
		
def draw_single(n,m):
	write("c")
	repeat("*", m-1)
	write("\n")
	reprep("*", m, n-1)
def draw_line(a,b):
	repeat(".", a)
	repeat("*", b)
	write("\n")

#--------------------------------------------------------------------
def solve():
	cards = [0]*4
	row1 = nextint()
	for i in range(4):
		cards[i] = map(int, next().strip().split())
	back = cards[row1-1]
	arr = [0]*18
	for item in back:
		arr[item] = 1
	row2 = nextint()
	for i in range(4):
		cards[i] = map(int, next().strip().split())
	back2 = cards[row2-1]
	cnt = 0
	ans = -1
	for item in back2:
		if arr[item] == 1:
			cnt += 1
			ans = item
	if cnt == 0:
		write("Volunteer cheated!\n")
	elif cnt > 1:
		write("Bad magician!\n")
	else:
		write("%d\n" % ans)

	
#--------------------------------------------------------------------
if __name__ == "__main__": ##__name__: [filename].py
	print "Hello, Main."
else:
	global fr, fw
	#fr = open('mm.in', 'r')
	#fw = open('mm.out', 'w')
	#prob_name = "A-small-practice"
	prob_name = "A-small-attempt0"

	fr = open(prob_name + '.in', 'r')
	fw = open(prob_name + '.out', 'w')
	cas = (int)(fr.readline())
	for cs in range(cas):
		write("Case #%d: " % (cs+1) )
		solve()
	fr.close()
	fw.close()
#--------------------------------------------------------------------


