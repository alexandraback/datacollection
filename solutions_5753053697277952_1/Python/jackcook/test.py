import sys

fp = file(sys.argv[1])
t = int(fp.next())

of = file("out.txt", 'w+')

for i in range(t):
    n = int(fp.next())
    p = [int(x) for x in fp.next().split()]

    evac = ""

    while sum(p) > 0:
        if sum(p) % 2 == 0:
            m = p.index(max(p))
            evac += chr(ord('A') + m)
            p[m] -= 1
            m = p.index(max(p))
            evac += chr(ord('A') + m)
            p[m] -= 1
        else:
            m = p.index(max(p))
            evac += chr(ord('A') + m)
            p[m] -= 1
        evac += " "

    of.write("Case #%d: %s\n" % (i + 1, evac))

of.close()
