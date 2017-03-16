def separate(s):
	l = []
	last = s[0]
	num = 0
	for k in s:
		if(k != last):
			l.append((last,num))
			last = k
			num = 1
		else:
			num+=1
	l.append((last,num))
	return l

def find_mid(l):
	n = len(l)
	if(n%2==1):
		return [sorted(l)[n/2]]
	else:
		return sorted(l)[n/2:n/2+2]

input = open("A-small-practice.in", "rb")
output = open("A-small-output.txt", "wb")
t = int(input.readline().strip("\n\r"))
for i in range(t):
	flag = 0
	n = int(input.readline().strip("\n\r"))
	l = []
	move = 0
	for j in range(n):
		line = input.readline().strip("\r\n")
		l.append(separate(line))
	string_ref = [s[0] for s in l[0]]
	for k in l:
		if([s[0] for s in k] != string_ref):
			flag = 1
			break
	if(flag != 1):
		for p in range(len(l[0])):
			mid = find_mid([k[p][1] for k in l])
			temp = []
			for n in mid:
				temp.append(sum([abs(k[p][1] - n) for k in l]))
			move+=min(temp) 
	if(flag == 1):
		output.write("Case #" + str(i + 1) + ": " + "Fegla Won" + "\n")
	else:
		output.write("Case #" + str(i + 1) + ": " + str(move) + "\n")
input.close()
output.close()








