#!/usr/bin/python
def out(t,n):
	tmp = []
	for i in range(n-2):
		for j in range(t):
			tmp.append(chr(65+i))
	ll = chr(65+n-2)+chr(65+n-1)
	for i in range(t):
		tmp.append(ll)
	return tmp

fin = open('A-large.in')
T = int(fin.readline())
for ii in range(T):
	dic = {}
	N = int(fin.readline().strip())
	tmp = fin.readline().strip().split(' ')
	for i in range(N):
		dic[i] = int(tmp[i])
	result = []
	while True:
		it = sorted(dic.items(), lambda x, y: cmp(x[1], y[1]), reverse=True)
		keyfi = it[0][0]
		keyen = it[-1][0]
		if dic[keyen] == dic[keyfi]:
			result += out(dic[keyfi], N)
			break
		else:
			dic[keyfi] -= 1
			result.append(chr(keyfi+65))
	tres = ""
	for k in result:
		tres = tres + ' ' + k
	print "Case #%s:%s" % (ii + 1, tres)
fin.close()