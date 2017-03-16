#!/usr/bin/env python
# -*- coding: UTF-8 -*-

from __future__ import division
import sys

class InputFile:
	def __init__(self, fd):
		self.fd = fd
	def readInt(self):
		return int(self.fd.readline())
	def readIntegers(self):
		return tuple([int(x) for x in self.fd.readline().split()])
	def readFloats(self):
		return tuple([float(x) for x in self.fd.readline().split()])
	def readIntegersList(self):
		return [int(x) for x in self.fd.readline().split()]
	def readString(self):
		return self.fd.readline()[:-1]

def parse(string):
	current_group = None
	counter = None
	result = []

	for char in string:
		if current_group == None:
			current_group = char
			counter = 1
		elif current_group == char:
			counter += 1
		elif current_group != char:
			result.append((current_group, counter))
			current_group = char
			counter = 1

	result.append((current_group, counter))
	return result

def compatible(string1, string2):
	if len(string1) != len(string2):
		return False

	for (a,b) in zip(string1, string2):
		if a[0] != b[0]:
			return False

	return True

def calculate_cost(group):
	group.sort()

	if len(group) %2 == 0:
		# Uno dei due centrali
		k = len(group)/2 -1 # o +1
	else:
		# Il centrale
		k = (len(group)-1)/2
	num = group[int(k)]

	cost = sum([abs(x-num) for x in group])
	return cost

def solve(strings):
	parsed = []

	for s in strings:
		newparsed = parse(s)
		if len(parsed) > 0:
			if not compatible(parsed[0], newparsed):
				return "Fegla Won"
		
		parsed.append(newparsed)

	cost = 0
	
	for i in range(len(parsed[0])):
		group = [s[i][1] for s in parsed]
		cost += calculate_cost(group)

	return cost
	


inputfile = InputFile(sys.stdin)
T = inputfile.readInt()
for test in range(1,T+1):
	N = inputfile.readInt()
	
	strings = []
	for i in range(N):
		strings.append(inputfile.readString())

	result = solve(strings)
	
	print "Case #{test}: {result}".format(test=test, result=result)

