from heapq import heappush, heappop
# heap = []
# data = [1, 3, 5, 7, 9, 2, 4, 6, 8, 0]
# for item in data:
#         heappush(heap, item)
#         ordered.append(heappop(heap))
T = int(raw_input())

for z in range(T):
	N = int(raw_input())
	P = map(int, raw_input().strip().split(" "))

	heap = []
	total = 0
	for index, num in enumerate(P):
		total += num
		heappush(heap, (-num, chr(ord('A')+index)))

	plan = ""
	while total > 0:
		(num, party) = heappop(heap)
		num += 1
		total -= 1
		plan += party
		if num < 0:
			heappush(heap, (num, party))

		flag = True
		if len(heap) == 2 and total == 2:
			flag = False

		if flag:
			(num, party) = heappop(heap)
			num += 1
			total -= 1
			plan += party
			if num < 0:
				heappush(heap, (num, party))

		plan += " "

	print "Case #%d: %s" % (z+1, plan.strip())
		
