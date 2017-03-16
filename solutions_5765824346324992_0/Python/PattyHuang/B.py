import sys
import operator
[T, B, N] = [0, 0, 0]
cnt = 0
def gcd(num1,num2):
    if num2 == 0: 
        return num1 
    else: 
        return gcd(num2,num1%num2)
def lcm(num1,num2): 
    tmp = gcd(num1,num2) 
    return num1*num2/tmp 
	
for line in sys.stdin:
	if T == 0:
		T = int(line.split("\n")[0])
	elif B == 0 and N == 0:
		B = int(line.split("\n")[0].split(' ')[0])
		N = int(line.split("\n")[0].split(' ')[1])
	else:
		counting_time = [0]
		counting_time = counting_time * B
		number = 0
		mi = map(int, line.split("\n")[0].split(' '))
		if N < B:
			number = N
		else:
			tmp = 1
			reduce = 0
			for i in mi:
				tmp = lcm(tmp,i)
			for i in mi:
				reduce += tmp / i
			N = N % reduce
			if N == 0:
				N = reduce
			for i in range(0, N):
				min_index, min_value = min(enumerate(counting_time), key=operator.itemgetter(1))
				counting_time = list(map(lambda x: x-min_value ,counting_time)) 
				counting_time[min_index] += mi[min_index]
		cnt = cnt+1
		[B, N] = [0, 0]
		print "Case #{0}: {1}".format(cnt, min_index+1)