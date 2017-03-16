from parser import parse, split

def helper(test):
	a, b = test
	seta = a[1][a[0]-1]
	setb = b[1][b[0]-1]
	common = [x for x in setb if x in seta]
	if len(common) == 1:
		return common[0]
	elif len(common) > 1:
		return 'Bad magician!'
	else:
		return 'Volunteer cheated!'

# schema here
schema = [(),[2,[int,4,[split(int)]]]]

num_tests, tests = parse(schema)
for case,test in enumerate(tests):
	sol = helper(test)
	print 'Case #{}: {}'.format(case+1, sol)
