import sys

def method1(seq):
	ans = 0
	for i in range(1,len(seq)):
		if(seq[i]<seq[i-1]):
			ans = ans + (seq[i-1]-seq[i])
	return ans

def method2(seq):
	maxdiff = 0
	ans = 0
	for i in range(1,len(seq)):
		tmp = seq[i-1] - seq[i]
		if tmp > maxdiff:
			maxdiff = tmp

	for i in range(0,len(seq)-1):
		if seq[i] < maxdiff:
			ans = ans + seq[i]
		else:
			ans = ans + maxdiff

	return ans


inputfile = open('A-large.in')
outputfile = open('A-large.out','w')
T = inputfile.readline()
for x in range(int(T)):
	N = inputfile.readline()
	seq = inputfile.readline()
	seq = seq.split()
	for i in range(0,len(seq)):		
		seq[i] = int(seq[i])
	print method1(seq),method2(seq)


	outputfile.write("Case #"+str(x+1)+": "+str(method1(seq))+" "+str(method2(seq))+"\n")
inputfile.close()
outputfile.close()