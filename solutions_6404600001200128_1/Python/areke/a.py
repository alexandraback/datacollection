f = open("/Users/sangypae/Desktop/gcj/a/A-large.in", 'r')
contents = f.read()
cases = int(contents.split("\n")[0])
contents = contents.split("\n")[1:]
for i in range(cases):
	n = contents[2*i]
	l = map(int, contents[2*i+1].split(" "))
	m = 0
	s1 = 0
	for a in range(len(l)):
		if a < (len(l)-1):
			dif = l[a]-l[a+1]
			if dif > m:
				m = dif
			if dif > 0:
				s1 += dif
	s2 = 0
	for a in range(len(l)):
		if a < (len(l)-1):
			if l[a] > m:
				s2 += m
			else:
				s2 += l[a]





	g = open("/Users/sangypae/Desktop/gcj/a/a-output.txt", 'a')
	g.write("Case #" + str(i+1)+": " + str(s1) + " " + str(s2) + "\n")
	g.close()