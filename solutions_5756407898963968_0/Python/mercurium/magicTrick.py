import string

magicInput = open("A-small-attempt0.in", 'r')
data = string.split(magicInput.read().strip(), '\n')
numCases = int(data[0])
index = 1
for i in xrange(1, 1+numCases):
    row1, row2 = int(data[index]), int(data[index+5])
    cards = set( [int(x) for x in string.split(data[index + row1], ' ')])
    cards = cards.intersection( set([int(x) for x in string.split(data[index + row2 + 5], ' ') ]) )
    index += 10
    if len(cards) == 1:
        print "Case #" + str(i) + ":", cards.pop()
    elif len(cards) == 0:
        print "Case #" + str(i) + ": Volunteer cheated!"
    else:
        print "Case #" + str(i) + ": Bad magician!"

