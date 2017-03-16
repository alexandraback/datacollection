def barber(B, N, M):
	# import pdb; pdb.set_trace()
	if B <= N:
		total = 1
		for x in M:
			total *= x
		lost = 0
		for x in M:
			lost += LCMBarbers(M) // x
		N = N % lost
		if N == 0:
			N = lost
		# print(LCMBarbers(M))
	from copy import deepcopy
	barbers = [0] * B#deepcopy(M)
	pos = N
	mine = -1
	while pos > 0:
		# print(pos)
		while lowestBarber(barbers) != -1:
			if pos == 1:
				return lowestBarber(barbers) + 1
			avail = lowestBarber(barbers)
			barbers[avail] += M[avail]
			pos -= 1
		barbers = reduceAll(barbers)
	return 'OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO'

def GCD(a, b):
    while b:      
        a, b = b, a % b
    return a

def LCM(a, b):
    return a * b // GCD(a, b)


def LCMBarbers(barbers):
	lcm = 1
	for n in range(len(barbers)):
		lcm = LCM(lcm, barbers[n])
	return lcm


def reduceAll(barbers):
	nonzero = getNonZeroMin(barbers)
	for n in range(len(barbers)):
		if barbers[n] >= nonzero:
			barbers[n] -= nonzero
		else:
			barbers[n] = 0
	return barbers


def getNonZeroMin(barbers):
	nonzero = 123456789123456789
	for n in range(len(barbers)):
		if barbers[n] != 0 and barbers[n] < nonzero:
			nonzero = barbers[n]
	if nonzero == 123456789123456789:
		return 0
	return nonzero


def lowestBarber(barbers):
	for n in range(len(barbers)):
		if barbers[n] == 0:
			return n
	return -1


def strArrayToIntArray(strarr):
	tmp = strarr.split()
	nums = []
	for i in range(len(tmp)):
		nums.append(int(tmp[i]))
	return nums


def main():
	file1 = open('B-small-attempt4.in','r')
	file2 = open('outfile.txt','w')
	caseNumber = int(file1.readline())
	cases = file1.read().split('\n')
	for x in range(0, caseNumber * 2, 2):
		print(x)
		file2.write("Case #" + str((x+2)//2) + ": " + str(barber(int(cases[x].split()[0]), int(cases[x].split()[1]), strArrayToIntArray(cases[x+1]))) + "\n")
main()