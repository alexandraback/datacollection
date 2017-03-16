def w(o):
    print >>fout, o

def solve():
    case = "Case #%d: %d %s"
    T = int(reader.r()) + 1
    for t in xrange(1, T):
        y = 0
        z = 0
        N = int(reader.r())
        x = 0
        s = []
        b = 0
        for i in xrange(N):
            m = int(reader.r())
            if m < x:
                y += x - m

            s.append(m)
            if(x - m > b):
                b = x - m
            x = m
        x = 0
        for i in xrange(N-1):
            m = s[i]
            if m > b:
                z += b
            else:
                z += m
            x = m
        w(case % (t,y,z))

class reader:
    buffer = []
    @staticmethod
    def r():
        if not reader.buffer:
            reader.buffer = fin.readline().rstrip().split()
        temp = reader.buffer[0]
        reader.buffer = reader.buffer[1:]
        return temp
    @staticmethod
    def rl():
        return fin.readline().rstrip()

fin = open('test.in', 'r')
fout = open('test.out', 'w')
solve();
fin.close()
fout.close()

