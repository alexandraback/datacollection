def count_unique(s):
	lst = []
	co = []
	lst.append(s[0])
	co.append(1)
	for i in range(1,len(s)):
		if s[i] == s[i-1]:
			co[-1] += 1
		else:
			lst.append(s[i])
			co.append(1)
	return ("".join(lst),co)

def solve():
	T = int(raw_input())
	for te in range(T):
		N = int(raw_input())
		strs = []
		tmps = ""
		fegla = False
		for i in range(N):
			s = raw_input()			
			if fegla == True:
				continue
			s = count_unique(s) # return a list of 1 string and 1 list
			#print s
			if tmps == "":
				tmps = s[0]
				strs.append(s)
			else:
				#print s[0]==tmps
				if s[0] == tmps:
					strs.append(s)
				else:
					fegla = True
		if fegla == True:
			#print strs[0]
			#print s[0]
			print "Case #%d: Fegla Won" % (te+1)
		else:
			#print strs[0]
			#print strs[1]
			nmove = 0
			for i in range(len(tmps)):
				nmin = -1
				for j in range(len(strs)):
					nlocal = 0
					for k in range(len(strs)):
						nlocal += abs(strs[k][1][i] - strs[j][1][i])
					if nmin == -1 or nlocal < nmin:
						nmin = nlocal
				nmove += nmin
			print "Case #%d: %d" % (te+1,nmove)
				


if __name__ == "__main__":
	solve()
