__author__ = 'Shailesh'

with open("../files/A-small-attempt0.in", 'r') as input, open("../files/output.txt", 'w') as output:
    t = int(input.readline())
    s = set()
    for i in xrange(t):
        answer = "Case #" + str(i+1) + ": "
        first, second = [], []
        n1 = int(input.readline())
        for j in xrange(4):
            data = input.readline()
            if j+1 == n1:
                first = map(int, data.split())
        n2 = int(input.readline())
        for j in xrange(4):
            data = input.readline()
            if j+1 == n2:
                second = map(int, data.split())

        result = set(first) & set(second)
        if not result:
            output.write(answer + "Volunteer cheated!\n")
        elif len(result) > 1:
            output.write(answer + "Bad magician!\n")
        else:
            output.write(answer + str(result.pop()) + "\n")