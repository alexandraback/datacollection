import re

with open('A-small-attempt1.in') as f:
	data = f.readlines()

T = int(data[0])
results = ''
for i in range(T):
	k = i * 10 + 1
	result = 'Case #' + str(i+1) + ': '
	n1 = int(data[k])
	m1 = []
	for j in range(4):
		s = data[k+j+1]
		m1.append(re.findall(r'\d+', s))
	n2 = int(data[k+5])
	m2 = []
	for j in range(4):
		s = data[k+j+6]
		m2.append(re.findall(r'\d+', s))
	r1 = m1[n1-1]
	r2 = m2[n2-1]
	state = 0
	y = -1
	for c1 in r1:
		for c2 in r2:
			if state != 2:
				if state == 1:
					if c1 == c2:
						state = 2
				else:
					if c1 == c2:
						y = c1
						state = 1
	if state == 0:
		result += 'Volunteer cheated!'
	elif state == 1:
		result += str(y)
	else:
		result += 'Bad magician!'
	result += '\n'
	results += result

with open('A-small-attempt1.out', 'w') as f:
	f.write(results)