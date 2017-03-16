def output(t, res):
    casestr = "Case #" + str(t+1) +": "
    if len(res) > 1:
        status = "Bad magician!"
    elif len(res) == 1:
        status = str( res.pop() )
    else:
        status = "Volunteer cheated!"
    outputLine = casestr+status
    fw.write(outputLine + "\n")

def possibleCards():
    a = int( lines.pop(0) )
    cards = []
    for i in xrange(4):
        if i == a-1:
            cards = set( map( int, lines.pop(0).split(' ') ) )
        else:
            lines.pop(0)

    return cards




##################################
#name = 'a-practice'
name = 'a-small'

f = open(name + '.in', 'r')
fw = open(name + '.out', 'w')
lines = f.readlines()
T = int( lines.pop(0) )

for t in xrange(T):
    output(t, possibleCards() & possibleCards() )
