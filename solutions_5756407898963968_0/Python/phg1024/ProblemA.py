__author__ = 'Peihong'

def findanswer(A, B):
    #print A, B
    res = []
    for x in A:
        for y in B:
            if x == y:
                res.append(x)
    return res


if __name__ == "__main__":
    f = open('A-small-attempt0.in', 'r')
    fout = open('A-small-attempt0.out', 'w')
    cases = int(f.readline())
    for i in range(cases):

        initorder = []
        # initial configuration
        # read the row index
        rIdx1 = int(f.readline())
        # read the configuration
        for j in range(4):
            initorder.append(map(int, f.readline().split()))

        finalorder = []
        # final configuration
        # read the row index
        rIdx2 = int(f.readline())
        # read the configuration
        for j in range(4):
            finalorder.append(map(int, f.readline().split()))

        # compare the numbers
        numbers = findanswer(initorder[rIdx1-1], finalorder[rIdx2-1])

        if len(numbers) > 1:
            print 'Case #%d: %s' % (i+1, 'Bad magician!')
            fout.write('Case #%d: %s\n' % (i+1, 'Bad magician!'))
        elif len(numbers) == 1:
            print 'Case #%d: %s' % (i+1, numbers[0])
            fout.write('Case #%d: %s\n' % (i+1, numbers[0]))
        else:
            print 'Case #%d: %s' % (i+1, 'Volunteer cheated!')
            fout.write('Case #%d: %s\n' % (i+1, 'Volunteer cheated!'))
    f.close()
    fout.close()

