import sys, math
inp = open("in.txt")
out = open("out.txt","w+")
sys.stdout = out
tc = 0

class ImpossibleError(Exception):
	pass

t = int(inp.readline())

def print_case(case, result):
    debug("Case #%d: %s" % (case, str(result)))
    print "Case #%d: %s" % (case, str(result))

def debug(message):
	if len(sys.argv) > 1 and sys.argv[1] == "silent":
		return
	sys.stdout = sys.__stdout__
	print message
	sys.stdout = out

alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def take_max(parties):
    m = max(parties, key=lambda x: x[0])
    m[0] -= 1
    if m[0] == 0:
        parties.remove(m)
    return m[1]

debug(t)
for tc in xrange(t):
    p = int(inp.readline())
    a = [int(x) for x in inp.readline().split()]
    s = sum(a)
    parties = [[a[i], alphabet[i]] for i in xrange(p)]
    result = []
    
    if s % 2 == 1:
        letter = take_max(parties)
        result.append(letter)
    
    debug(parties)
    
    while len(parties) > 0:
        l1 = take_max(parties)
        l2 = take_max(parties)
        result.append(l1 + l2)
        debug(parties)
    
    print_case(tc+1, " ".join(result))