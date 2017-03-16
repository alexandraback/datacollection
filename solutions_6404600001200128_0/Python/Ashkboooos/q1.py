

def main():
	file_name = 'A-small-attempt0.in'
	fh = open(file_name, 'rt')
	line = fh.readline()
	test_cases = int(line)
	result = ''

	for ind_line in xrange(1, test_cases+ 1):
		line1 = fh.readline().replace('\n','')
		line1 = fh.readline().replace('\n','')
		sp = line1.split()
		#print sp
		eaten = 0
		eaten2= 0 
		max_rate = 0
		for ind in xrange(len(sp) - 1):
			
			e =  int(sp[ind]) - int(sp[ind+1]) 
			eaten += max(0, e)
			if e > max_rate:
				max_rate = e
		
		for ind in xrange(len(sp) - 1):
			#e =  (int(sp[i] - int(sp[i-1]) ))
			if max_rate > int(sp[ind]):
				eaten2 += int(sp[ind])
			else:
				eaten2 += max_rate

		r = "Case #" + str(ind_line) + ": " + str(eaten) +  " " + str(eaten2) + '\n'
		result += r
		
	print result
	f = open('q1.out', 'w')
	f.write(result)
	f.close()
main()
