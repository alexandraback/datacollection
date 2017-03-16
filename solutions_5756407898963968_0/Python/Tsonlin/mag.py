if __name__ == '__main__':
    with open('input', 'r') as f:  
        T = int(f.readline())
        for t in xrange(1, T+1):
            r1 = int(f.readline())
            s1 = set()
            for i in xrange(1, 5):
                tmp = f.readline()
                if i == r1: s1.update([int(e) for e in tmp.split()])

            r2 = int(f.readline())
            s2 = set()
            for i in xrange(1, 5):
                tmp = f.readline() 
                if i == r2: s2.update([int(e) for e in tmp.split()])

            s = s1.intersection(s2)
            n = len(s)

            print 'Case #%d:' % t,
            if n == 1:
                print list(s)[0]
            elif n == 0:
                print 'Volunteer cheated!'
            else:
                print 'Bad magician!'

