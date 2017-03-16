import string

def GCD(a,b):
	if a == 0:
		return b
	return GCD(b%a, a)

def gcd(lst):
	lst = sorted(lst)
	return reduce(lambda x,y: GCD(x,y), lst)

def solve(N, times):
	print "Solving {}-th person, barbertimes are {}".format(N, times)
	barbers = []
	for time in times:
		def barber(inc):
			i = 0
			while True:
				yield i
				i += inc
		barbers.append(barber(time))
	nexttimes = [barber.next() for barber in barbers]

	rt = gcd(times)
	N %= rt
	personNum = 0
	if N == 0: return 1
	while personNum < N:
		nextbarber = nexttimes.index(min(nexttimes))
		#print "nexttimes are {}, person {} goes to barber {}".format(nexttimes, j+1, nextbarber+1)
		nexttimes[nextbarber] = barbers[nextbarber].next()
		if min(nexttimes) == max(nexttimes):
			N = personNum + N % personNum
		personNum += 1

	return nextbarber+1

def test(inputs, ans):
	b = solve(*inputs)
	if (b != ans):
		print "Failed test! Inputs {} should give answer of {} not {}".format(' '.join(inputs), ans, b)

def main():

    outfile = open('a.out','w')
    T = int(string.strip(raw_input()))    

    for k in xrange(1,T+1):
        print k
        s = map(int,string.strip(raw_input()).split())
        B, N = s
        times = map(int,string.strip(raw_input()).split())

        answer = solve(N, times) # add appropriate arguments
        outfile.write('Case #%d: %s\n' % (k,answer))

if __name__ == '__main__':
    main()