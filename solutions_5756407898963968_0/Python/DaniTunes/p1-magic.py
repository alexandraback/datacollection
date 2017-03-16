import sys

data = sys.stdin.readlines()
n = int(data[0])
#print n
for i in range(n):
    k = 10*i+1
    r1 = int(data[k+0])
    r2 = int(data[k+5])
    s1 = [map(int, x.split()) for x in data[k+1:k+5]]
    s2 = [map(int, x.split()) for x in data[k+6:k+10]]
    a = s1[r1-1]
    b = s2[r2-1]
    z = list(set(a) & set(b))
    print "Case #%d:" % (i+1),
    if len(z) == 1:
	print z[0]
    elif len(z) > 1:
	print "Bad magician!"
    else:
	print "Volunteer cheated!"
