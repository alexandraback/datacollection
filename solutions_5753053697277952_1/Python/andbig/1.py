import string

def evacall(ae):
    s=""
    for pn,pc in ae:
        for i in range(pc/2):
            s+= pn + pn + " "
        if pc % 2 == 1:
            s+=pn + " "
    return s

def getans(el):
    # Receives [(A,4),(Z,3)..]
    el.sort(reverse=True, key=lambda tup: tup[1])
    fbn,fbc = el[0]
    sbn,sbc = el[1]
    el = el[2:]
    s=""
    excess=fbc-sbc
    for i in range(excess/2):
        s+= fbn + fbn + " "
    if excess % 2 == 1:
        s+=fbn + " "
    # fbn = sbn
    s += evacall(el)
    for i in range(sbc):
        s+= fbn + sbn + " "
    if len(s) > 1 and s[-1]==' ':
        s=s[:-1]
    return s
	
def glfs(s):
	return s.split(' ')

def gilfs(s):
	return [int(x) for x in glfs(s)]

fileName = "A-large.in"
f = open(fileName)

l=f.readline()
l=f.readline()

inputs=[]
while l:
    l=f.readline()
    li=gilfs(l)
    inp=zip(string.ascii_uppercase,li)
    #print inp
    inputs.append(inp)
    l=f.readline()
    
f.close()

outfile="tst1.out"
of=open(outfile,"wb")
testCount=1

for inputEl in inputs:
    ans = getans(inputEl)
    of.write("Case #" + str(testCount) + ": " + str(ans)+'\n')
    testCount += 1

of.close()

