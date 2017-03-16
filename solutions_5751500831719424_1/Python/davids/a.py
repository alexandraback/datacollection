from __future__ import division

import sys, os

class Node:
	def __init__(self, val_, num_):
		self.children = []
		self.val = val_
		self.num = num_

	def __str__(self):
		return "%s%s" % (self.val,self.num)
	def __repr__(self):
		return "%s%s" % (self.val,self.num)

def str_to_nodes(in_):
	ret = []
	cur_val, cur_count = '', 0
	
	for i,c in enumerate(in_):
		if c != cur_val:
			if i == 0:
				cur_val = c
				cur_count = 1
			else:
				ret.append(Node(cur_val, cur_count))
				cur_val = c
				cur_count = 1
		else:
			cur_count += 1
	
	ret.append(Node(cur_val, cur_count))
	return ret
	
def cmp_nodes_imp(a,b):
	if len(a) != len(b):
		return False
	for i,c in enumerate(a):
		if a[i].val != b[i].val:
			return False
	return True

def cmp_nodes(a,b):
	if len(a) != len(b):
		return False
	for i,c in enumerate(a):
		if a[i].val != b[i].val or a[i].num != b[i].num:
			return False
	return True
	
	
def do_case(nodes):
	for i in range(1,len(nodes)):
		if not cmp_nodes_imp(nodes[i-1], nodes[i]):
			print nodes[0]
			print nodes[1]
			return "Fegla Won"
	
	ret = 0
	for i in range(len(nodes[0])):
		#pos = list(set(map(lambda l: l[i].num, nodes)))
		pos = range(1,101)
		best_val, best_diff = 0, 2**30
		for p in pos:
			s = sum(map(lambda l: abs(l[i].num - p), nodes))
			if s < best_diff:
				best_diff = s
				best_val = p
		ret += best_diff
	
	return ret
			
	
f = open(sys.argv[1], 'r')
out = open(sys.argv[2], 'w')

num_cases = int(f.readline())
for i in range(1,num_cases+1):
	num_strings = int(f.readline())
	strings = []
	for j in range(num_strings):
		strings.append(str_to_nodes(f.readline().rstrip()))
	  
	res = do_case(strings)
	print "Case #%d:" % (i), res
	out.write("Case #%d: %s\n" % (i, res))

	
	