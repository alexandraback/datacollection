t = int(raw_input())
for case in range(1, t + 1):
	n = int(raw_input())
	ps = map(int, raw_input().split())
	names = [chr(65 + i) for i in range(n)]
	queue = zip(ps, names)
	queue = map(list, queue)
	queue.sort()
	plan = []
	while queue[-1][0]:
		if queue[-1][0] == queue[-2][0]:
			if (queue[-1][0] != 1 or 
					len(queue) < 3 or
					queue[-3][0] == 0):
				plan.append(queue[-1][1] + queue[-2][1])
				queue[-1][0] -= 1
				queue[-2][0] -= 1
			else:
				plan.append(queue[-1][1])
				queue[-1][0] -= 1
		else:
			plan.append(queue[-1][1])
			queue[-1][0] -= 1
		queue.sort()
	ans = " ".join(plan)
	print "Case #%i: %s" %(case, ans)

      
        
