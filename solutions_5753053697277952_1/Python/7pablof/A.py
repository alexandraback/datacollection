##f = open('A-small-attempt0.in')
f = open('A-large.in')
f2 = open('file.txt','w')
T = f.readline()
i = 0
for l in f:
    i += 1
    r = ""
    l = [int(x) for x in f.readline().split()]
    if (sum(l) % 2 != 0):
        a = l.index(max(l))
        r += chr(65 + a)
        l[a] -=1
        r += ' '
    while(sum(l) > 0):
        a = l.index(max(l))
        r += chr(65 + a)
        l[a] -=1
        if (sum(l) == 0):
            break
        a = l.index(max(l))
        r += chr(65 + a)
        l[a] -=1
        r += ' '

    print("Case #" + str(i) + ": " + r,file=f2)
f.close()
f2.close()
