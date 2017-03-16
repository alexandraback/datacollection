from collections import defaultdict
import fileinput
stdin = fileinput.input()

def letter(i):
	return chr(ord('A') + i)

def solveCase():
	N = int(next(stdin))
	P = list(map(int,next(stdin).split()))
	t = sum(P)
	instr = []
	while t:
		s = sorted(range(N),key=lambda i:P[i],reverse=True)
		P[s[0]] -= 1
		t -= 1
		if 2*P[s[1]]>t:
			P[s[1]] -= 1
			t -= 1
			instr.append(letter(s[0])+letter(s[1]))
		else:
			instr.append(letter(s[0]))
	return " ".join(instr)

for case in range(int(next(stdin))):
	print("Case #{0}: {1}".format(case+1,solveCase()))