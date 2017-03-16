def proc(s):
    ans = []
    c = 0
    i = 0
    while c < len(s):
        if i >= len(s):
            ans.append( (s[c], i-c) )
            return ans
        elif s[c] != s[i]:
            ans.append( (s[c], i-c) )
            c = i
        else:
            i += 1

def solve(lines):
    nstrs = len(lines)
    lines = [proc(l.strip()) for l in lines]
    if not min([ len(lines[0]) == len(l) for l in lines]):
        return "Fegla Won"
    else:
        c = 0
        for i in xrange(len(lines[0])):
            keys = [l[i] for l in lines]
            if len(dict(keys)) != 1:
                return "Fegla Won"
            else:
                top = max([p[1] for p in keys])
                c += min([sum([abs(t-p[1]) for p in keys]) for t in xrange(top+1)])
        return c

f = file('a.in', 'r')
lines = f.readlines()
n = int(lines[0])
f.close()

c = 1
g = file('a.out', 'w')
for i in xrange(n):
    nstrs = int(lines[c])
    ans = solve(lines[c+1:c+1+nstrs])
    c += nstrs + 1
    g.write("Case #{}: {}\n".format(i+1, ans))
g.close()
