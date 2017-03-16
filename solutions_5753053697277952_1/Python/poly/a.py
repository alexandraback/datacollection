import sys

def solve(n, p):
	first = True
	t = [(x,i) for i,x in enumerate(p)]
	t.sort(reverse=True)
	v = t[0][0]
	ans = ""
	while v > 0:
		if not first:
			ans = ans + " "
		else:
			first = False

		if t[1][0] == v and not (v == 1 and n == 3 and t[2][0] == 1):
			t[0] = (v-1, t[0][1])
			t[1] = (v-1, t[1][1])
			s = "%c%c" % (chr(65 + t[0][1]), chr(65 + t[1][1]))
		else:
			t[0] = (v-1, t[0][1])
			s = "%c" % (chr(65 + t[0][1]))
		ans = ans + s
		t.sort(reverse=True)
		v = t[0][0]
	return ans

T = input()
for i in range(T):
    n = input()
    p = map(int, raw_input().split())
    print "Case #%d: %s" % ((i+1), str(solve(n, p)))
