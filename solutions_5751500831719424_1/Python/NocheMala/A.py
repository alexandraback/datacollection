import sys
import math
def most_common(lst):
    return max(set(lst), key=lst.count)
def Solve():
	N = int(my_file.readline())
	arr = []
	warr = []
	for i in range(N):
		st = my_file.readline()
		st = st[0:len(st)-1]
		ind = 0
		word = st[0]
		warr.append([word])
		arr.append([1])
		for j in range(1,len(st)):
			if word != st[j]:
				ind += 1
				arr[i].append(1)
				word = st[j]
				warr[i].append(word)
			else:
				arr[i][ind] += 1
	for i in range(N):
		for j in range(i,N):
			if warr[i] != warr[j]:
				return("Fegla Won")
	cnt = 0
	for i in range(len(arr[0])):
		ls = []
		add = 1000000
		for j in range(N):
			ls.append(arr[j][i])
		for k in ls:
			add = min(add,sum([abs(x-k) for x in ls]))
		cnt += add
	return str(cnt)


def printCase(caseNum,strs):
	sys.stdout.write("Case #"+str(caseNum)+": "+strs+"\n")
	my_file2.write("Case #"+str(caseNum)+": "+strs+"\n")

my_file = open('Input.txt',"r")
my_file2 = open('Output.txt', "w")
T = int(my_file.readline())
for case in range(1,T+1):
	printCase(case,Solve())
my_file.close()
my_file2.close()