import sys, math
from fractions import gcd

def lcm(a, b):
	""" Computes the lowest common multiple
	"""
	return (a*b)/gcd(a,b)

def main(fin, fout):
	T = int(fin.readline())
	for t in range(T):
		B, N = map(int, fin.readline().strip().split())
		mList = [int(x) for x in fin.readline().strip().split()]
		# print B, N
		# print mList

		if N <= B:
			answer = N
		else:
			mlcm = 1
			for i in range(B):
				mlcm = lcm(mlcm, mList[i])
			# print "mlcm:", mlcm

			# Get the total number of people in one cycle:
			cylen = 0
			for i in range(B):
				cylen += mlcm / mList[i]
			# print "cycle length:", cylen
			N = N % cylen
			# print "New N",N
			order = []
			unique = []
			for m in mList:
				value = []
				for i in range(mlcm / m):
					value.append(m*i)
					unique.append(m*i)
				order.append(value)
			# print order
			unique = list(set(unique))
			unique.sort()
			# print unique

			barber = [0 for x in range(cylen)]
			# for i in range(B):
				# barber[i] = i
			value = min(mList)
			index = 0
			for time in unique:
				for i in range(B):
					if time in order[i]:
						order[i].pop(0)
						barber[index] = i + 1
						index += 1
			# print barber
			answer = barber[N - 1]
			print "Case #%d: " % (t+1),answer

		fout.write("Case #%d: %d\n" % (t+1, answer))

	return

if __name__ == '__main__':
	fin = open(sys.argv[1], "r")
	fout = open(sys.argv[2], "w")
	main(fin, fout)
