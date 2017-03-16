
fin_name = 'A-small-attempt1.in'
#fin_name = 'sample_input.in'
f_in = open( fin_name, 'r' )

case_count = int( f_in.readline() )
cases = [None]*case_count
for i in range(case_count):
	arg_count = int( f_in.readline() )
	cases[i] = [ int(arg) for arg in f_in.readline().split() ]

#my_input = '10 5 15 5'
#mushrooms =  [ int(arg) for arg in my_input.split() ]

def method1( x_ary ):
	total = 0
	prev_xo = None
	for xo in x_ary:
		if prev_xo is not None and xo < prev_xo:
			total += ( prev_xo - xo )
		prev_xo = xo
	return total

def getDiffs( x_ary ):
	diffs = [None]*( len(x_ary)-1 )
	for i in range(1, len(x_ary)):
		diffs[i-1] = x_ary[i] - x_ary[i-1]

	return diffs

def method2( x ):
	mostEatenPerInterval = -min( getDiffs( x ) )
	if mostEatenPerInterval < 0: return 0
	
	eatingRate = mostEatenPerInterval

	total = 0
	for i in range(0, len(x)-1):
		if x[i] > eatingRate:
			total += eatingRate
		else:
			total += x[i]
			#total += eatingRate

	return total


	

fout_name = fin_name + '.out'
fout = open( fout_name, 'w' )


#print method1( mushrooms ), method2( mushrooms )
for case_index, case in enumerate(cases):
	case_num = case_index + 1
	toWrite = 'Case #%d: %d %d\n' % ( case_num, method1(case), method2(case) )
	#print '%4d: %60s; %d, %d' % ( case_num, case, method1(case), method2(case) )
	fout.write( toWrite )
