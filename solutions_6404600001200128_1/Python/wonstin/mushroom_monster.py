import string

def solve(s):
	print "Solving {}".format(s)
	# get first method ans
	tot1 = 0
	for i in range(len(s)-1):
		if s[i] > s[i+1]:
			tot1 += s[i] - s[i+1]

	# get second method ans
	tot2 = 0
	rate = max([s[i]-s[i+1] for i in range(len(s)-1)])/10.0
	for i in range(len(s)-1):
		tot2 += min(rate*10, s[i])

	return "{} {}".format(tot1, int(tot2))

def test(inputs, ans):
	b = solve(*inputs)
	if (b != ans):
		print "Failed test! Inputs {} should give answer of {} not {}".format(' '.join(inputs), ans, b)

def main():

    outfile = open('a.out','w')
    T = int(string.strip(raw_input()))    

    for k in xrange(1,T+1):
        print k
        N = int(raw_input())
        s = map(int,string.strip(raw_input()).split())

        answer = solve(s) # add appropriate arguments
        outfile.write('Case #%d: %s\n' % (k,answer))

if __name__ == '__main__':
    main()