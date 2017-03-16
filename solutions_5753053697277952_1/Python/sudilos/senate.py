#!/usr/bin/env python
import sys

def arg_max(p):
	a = -1
	m = 0
	for i in range(len(p)):
		if p[i] > m:
			m = p[i]
			a = i
	return a

def amp(p, a):
	out = []
	for i in range(len(p)):
		if p[i] == a:
			out += [i]
	return out

def to_chr(c):
	return chr(ord('A') + c)

def equalise(n, p):
	out = []
	while(max(p) > 1):
		a = max(p)
		ap = amp(p, a)
		if(len(ap) == 1):
			out += [to_chr(ap[0])]
			p[ap[0]] -= 1
		else:
			out += [to_chr(ap[0]) + to_chr(ap[1])]
			p[ap[0]] -= 1
			p[ap[1]] -= 1

	if sum(p) % 2 == 1:
		a = arg_max(p)
		out += [to_chr(a)]
		p[a] -= 1

	while(sum(p) > 0):
		a1 = arg_max(p)
		p[a1] -= 1
		a2 = arg_max(p)
		p[a2] -= 1
		out += [to_chr(a1) + to_chr(a2)]

	#rem = []
	#for i in range(len(p)):
		#if p[i] == 1:
			#rem += [i]
		#if p[i] == 2:
			#rem += [i, i]

	
	#f = [to_chr(x) for x in out]
	#if len(rem) == 1:
		#f += [to_chr(rem[0])]
	#else:
		#f += [to_chr(rem[0]) + to_chr(rem[1])]

	return out


	


# Get input/output files and open them
if(len(sys.argv) != 3):
	print "Usage: [program]  <input> <output>"
	sys.exit(1)

f = open(str(sys.argv[1])) 
out = open(str(sys.argv[2]), "w")

# Remove the first line of the input (which contains the length)
lines = [l for l in f]
lines = lines[1:]

# For each input line, find the potter number
count = 0
while True:
	n = int(lines[count])
	p = [int(x) for x in lines[count + 1].split()]
	print n, p
	out.write("Case #" + str(count/2 + 1) + ": " + " ".join(equalise(n, p)) + "\n")
	count += 2
	if(count >= len(lines)):
		break
