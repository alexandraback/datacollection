def allsame(l):
    for each in l:
        if each != l[0]:
            return False
    return True

def allzero(l):
    for each in l:
        if each != 0:
            return False
    return True

f = open("Asmall.in",'r')
t = int(f.readline().strip())
abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
for case in range(t):
    output = []
    n = int(f.readline().strip())
    senators = f.readline().strip()
    senators = senators.split()
    s = []
    for each in senators:
        s.append(int(each))

    while not allsame(s):
        toremove = s.index(max(s))
        output.append(abc[toremove])
        s[toremove] -= 1

    # now all same
    while s[-1] != 0:
        if len(s)%2 == 1:
            output.append(abc[len(s)-1])
            s[-1] -= 1
            length = len(s)-1
        else:
            length = len(s)

        i = 0
        while i < length:
            output.append(abc[i]+abc[i+1])
            s[i] -= 1
            s[i+1] -= 1
            i += 2

    

    print "Case #" + str(case+1) + ": " + ' '.join(output)
f.close()
