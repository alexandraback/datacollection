def median(numbers):
	sorts = sorted(numbers)
	return sorts[len(sorts) // 2]

def calculate_transform(string):
	current = None
	count = 0
	result = []
	for character in list(string):
		if current is not None and not character == current:
			result.append({'character': current, 'count': count})
			count = 0
		current = character
		count += 1
	result.append({'character': current, 'count': count})

	return result

def calculate(strings):
	transforms = []
	for string in strings:
		transforms.append(calculate_transform(string))
	length = len(transforms[0])
	for transform in transforms:
		if len(transform) != length:
			return None

	position = 0
	actions = 0
	while position < length:
		counts = []
		previous = None
		for transform in transforms:
			if previous is not None and transform[position]['character'] != previous:
				return None
			previous = transform[position]['character']
			counts.append(transform[position]['count'])

		#print('Position: ' + str(position))
		#print(counts)

		best = median(counts)
		difference = 0
		for count in counts:
			difference += abs(best - count)
		actions += difference

		position += 1

	return actions

t = int(input())
for i in range(t):
	n = int(input())
	strings = []
	for j in range(n):
		strings.append(input())
	result = calculate(strings)
	if result is None: print('Case #%s: Fegla Won' % (i + 1))
	else: print('Case #%s: %s' % (i + 1, result))