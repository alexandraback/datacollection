f = open('B-small-attempt0.in')
fw = open('B-small-attempt0.out', 'w')

def gcd(a, b):
	while b:      
		a, b = b, a % b
	return a

def lcm(a, b):
	return a * b / gcd(a, b)

cases = int(f.readline())
for case in range(cases):
	B, N = map(int, f.readline().split())
	Mk = map(int, f.readline().split())
	
	lcm_num = 1
	for k in Mk:
		lcm_num = lcm(lcm_num, k)

	total_repeat = 0
	for k in Mk:
		total_repeat += lcm_num / k


	N -= 1
	N = N % total_repeat

	barber_get = []
	time_left = list(Mk)
	min_time = 500000000
	min_index = None
	for i in range(len(Mk)):
		barber_get.append(i)
		if Mk[i] < min_time:
			min_time = Mk[i]
			min_index = i

	for i in range(len(Mk), N+1):
		barber_get.append(min_index)
		prev_min_time = min_time
		min_time = 500000000
		time_left[min_index] = Mk[min_index] + prev_min_time
		for j in range(len(time_left)):
			time_left[j] = time_left[j] - prev_min_time
			if time_left[j] < min_time:
				min_time = time_left[j]
				min_index = j

	fw.write('Case #' + str(case + 1) + ': ' + str(barber_get[N]+1) + '\n')

fw.close()
f.close()
