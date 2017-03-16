fin, fout = open('magic_trick.in'), open('magic_trick.out', 'w')

def get_set():
	l = []
	g = int(fin.readline())
	for i in range(4):
		l.append([int(w) for w in fin.readline().split()])
	return set(l[g - 1])

t = int(fin.readline())
answer = 'Case #{0}: {1}'
for i in range(t):
	s1 = get_set()
	s2 = get_set()
	s = s1 & s2
	if len(s) == 1:
		print(answer.format(i + 1, s.pop()), file=fout)
	elif len(s) > 1:
		print(answer.format(i + 1, 'Bad magician!'), file=fout)
	else:
		print(answer.format(i + 1, 'Volunteer cheated!'), file=fout)
fin.close()
fout.close()

