import sys

stdin = sys.stdin.readlines()
cases = int(stdin.pop(0))
for case in xrange(1,cases+1):
    answer = None
    row = int(stdin.pop(0))
    possibilities = []
    for i in xrange(4):
        thisrow = stdin.pop(0)
        if i+1 == row:
            possibilities = thisrow.strip('\n').split(' ')
    row = int(stdin.pop(0))
    for i in xrange(4):
        thisrow = stdin.pop(0)
        if i+1 == row:
            otherpossibilities = thisrow.strip('\n').split(' ')
            for possibility in possibilities:
                if possibility in otherpossibilities:
                    if not answer:
                        answer = possibility
                    else:
                        answer = "Bad magician!"
    if not answer:
        answer = "Volunteer cheated!"
    print "Case #"+str(case)+": "+answer
