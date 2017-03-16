def gcd(a, b):
    while b:      
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

def lcmOfList(l): 
    return reduce(lcm, l)

def getAns(mod, barbers, m):
	minute = 0
	while mod > 0:
		for i in range(len(barbers)):
			if minute % barbers[i] == 0:
				mod -= 1
				if mod == 0:
					return i + 1
		minute += 1

f = open("/Users/sangypae/Desktop/gcj/b/B-small-attempt0.in", 'r')
contents = f.read()
cases = int(contents.split("\n")[0])
contents = contents.split("\n")[1:]
for i in range(cases):
	b, n = contents[2*i].split(" ")
	n = int(n)
	b = int(b)
	m = map(int, contents[2*i+1].split(" "))
	lc = lcmOfList(m)
	s = 0
	for a in range(len(m)):
		s += lc/m[a]
	mod = n % s


	if mod == 0:
		mod = s
	barbers = m[:]
	ans = getAns(mod, barbers, m)
	
			






	g = open("/Users/sangypae/Desktop/gcj/b/b-output.txt", 'a')
	g.write("Case #" + str(i+1)+": " + str(ans) + "\n")
	g.close()