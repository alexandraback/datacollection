from fractions import gcd
def min_barber(barbers_cater, barber):
	l = len(barber)
	#min_b = 10000
	#min_b_i = -1
	barber_time = [barbers_cater[i] * barber[i] for i in xrange(l) ] 
	min_b_i = barber_time.index(min(barber_time)) 
	#for i in xrange(l):
	#	e = barbers_cater[i] * barber[i]
	#	if e < min_b:
	#		min_b = e
	#		min_b_i = i
	return min_b_i
#def lcm(arr, g):
	#g  = reduce(gcd, arr)
def lcm(a, b):
    """Return lowest common multiple."""
    return a * b // gcd(a, b)

def lcmm(*args):
    """Return lcm of args."""   
    return reduce(lcm, args)
def round(arr, l):
	r = 0
	for a in arr:
		r += l / a 
	return r
def main():
	#file_name = 'sample2.out'
	file_name = 'B-small-attempt1.in'
	fh = open(file_name, 'rt')
	line = fh.readline()
	test_cases = int(line)
	result = ''
	for ind_line in xrange(1, test_cases+ 1):
		line1 = fh.readline().replace('\n','')
		sp = line1.split()
		b, nth = int(sp[0]), int(sp[1])
		line1 = fh.readline().replace('\n','')
		sp = line1.split()
		barbers_cater = []
		for s in sp:
			barbers_cater.append(int(s))
		barbers = [0] * b
		total = nth
		#if nth <=3:
		least_cm = lcmm(* barbers_cater)
		round_n = round(barbers_cater, least_cm)
		nth2 = nth % round_n
		if nth2 == 0:
			nth2 = round_n
		#print nth2
		for i in xrange(nth2):
			min_i = min_barber(barbers_cater, barbers)
			barbers[min_i] += 1
					
		r = "Case #" + str(ind_line) + ": " + str(min_i + 1) + '\n'
                result += r

	print result
        f = open('q2.out', 'w')
        f.write(result)
        f.close()
main()
