import sys
import copy
def gongyueshu(m,n):
    if m<n:
        small = m
    else:
        small = n
    for i in range (small,0,-1):
        if m % i == 0 and n %i == 0:
            return i
def gongbeishu(m,n):
    gongyue = gongyueshu(m,n)
    return (m*n)/gongyue

def minfac(seq):
	ans = 1
	for x in seq:
		ans = gongbeishu(ans,x)
	return ans

def hum(seq):
	aa = minfac(seq)
	ans = 0
	for a in seq:
		ans = ans + (aa/a)
	return ans

inputfile = open('B-small-attempt3.in')
outputfile = open('A-large.out','w')
T = inputfile.readline()
for x in range(int(T)):
	data = inputfile.readline()
	data = data.split()
	B = int(data[0])
	N = int(data[1])
	seq = inputfile.readline()
	seq = seq.split()
	for i in range(0,len(seq)):		
		seq[i] = int(seq[i])
 	mfac = hum(seq)
 	point = []
 	avai = [0 for i in range(B)]
	remain = [0 for i in range(B)]
	cc = 0
 	while len(point) < mfac:
 		for i in range(0,B):
			if avai[i] == 0:
				point.append(i)
				remain[i] = seq[i]
				avai[i] = 1
		#minus min cost
		mintime = min(remain)
		for i in range(0,B):
			remain[i] = remain[i] - mintime
			if remain[i] == 0:
				avai[i] = 0


	ans = point[N%mfac-1]+1
	print ans
	outputfile.write("Case #"+str(x+1)+": "+str(ans)+"\n")
inputfile.close()
outputfile.close()