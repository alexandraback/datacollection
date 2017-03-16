def gl(f, splitchar=' '):
    return map(f, raw_input().split(splitchar))

def g(f):
    return f(raw_input())

def all(strs):
    for i in xrange(len(strs)-1):
        if strs[i] != strs[i+1]:
            return False
    return True
            

def fil(inp):
    curr=''
    out=''
    for l in inp:
        if l == curr:
            continue
        curr = l
        out += l
    return out

def num(inp):
    out =[]
    count = 1
    curr =inp[0]
    for i in xrange(1,len(inp)):
        if inp[i] != curr:
            out.append(count)
            count = 1
            curr = inp[i]
            continue
        count += 1
        curr = inp[i]
    out.append(count)
    return out

t=g(int)
for ind in xrange(t):
    n=g(int)
    strs=[g(str) for _ in xrange(n)]
    ans = map(lambda x: fil(x), strs)
    print "Case #%d:"%(ind+1),
    if not all(ans):
        print "Fegla Won"
        continue
    nums=map(lambda x: num(x), strs)
    count = 0
    for i in xrange(len(nums[0])):
        vals=sorted(map(lambda x: x[i], nums))
        med=vals[len(vals)/2]
        add = sum(map(lambda x: abs(x-med), vals))
        count += add
    print count
