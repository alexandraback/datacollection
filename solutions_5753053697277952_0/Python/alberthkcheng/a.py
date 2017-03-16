t = int(raw_input())

def get_sequence(n, p):
	eva_order = []
	# print sum(p)
	while sum(p) > 3:
		max1 = p.index(max(p))
		p[max1] -= 1
		max2 = p.index(max(p))
		p[max2] -= 1
		chr(65)
		eva_order.append(chr(65+max1) + chr(65+max2))

	if sum(p) == 3:
		# three ppl left
		max1 = p.index(max(p))
		p[max1] -= 1
		eva_order.append(chr(65+max1))
		max1 = p.index(max(p))
		p[max1] -= 1
		max2 = p.index(max(p))
		p[max2] -= 1
		eva_order.append(chr(65+max1) + chr(65+max2))

	else:
		# two ppl left
		max1 = p.index(max(p))
		p[max1] -= 1
		max2 = p.index(max(p))
		p[max2] -= 1
		eva_order.append(chr(65+max1) + chr(65+max2))

	return eva_order


for i in range(t):
	n = int(raw_input())
	p = map(int, raw_input().split(" "))
	print "Case #" + str(i+1) + ": " + " ".join(get_sequence(n, p))