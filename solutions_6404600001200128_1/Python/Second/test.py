#encoding=utf8
filename = "A-large.in"
raw_data = ''
with open(filename, 'r') as f:
	raw_data = f.read().split('\n')

test_count = int(raw_data.pop(0))
for test in range(test_count):
	allcounts = int(raw_data.pop(0))
	alllist = map(int,raw_data.pop(0).split())
	# print allcounts,alllist
	sublist = [alllist[i]-alllist[i-1] for i in range(1,allcounts)]
	gap = min(sublist)
	abs_gap = abs(gap) if gap<0 else 0
	# print sublist,abs_gap
	a_count = abs(sum([x for x in sublist if x<0]))
	b_count = 0
	for x in range(allcounts):
		if abs_gap >= alllist[x]:
			b_count += alllist[x]
		else:
			# print b_count,
			b_count += abs_gap
		if x == (allcounts-2):
			# print 'break :',x
			break
	print 'Case #%d: '%(test+1),a_count,b_count

