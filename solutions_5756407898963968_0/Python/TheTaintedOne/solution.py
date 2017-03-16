import sys
import itertools

lines = sys.stdin.readlines()

ntests = int(lines[0])

currline = 1
for t in range(1, ntests+1):
    a1 = int(lines[currline])-1
    a2 = int(lines[currline+5])-1

    set1 = set([int(x) for x in lines[currline+1+a1].split()])
    set2 = set([int(x) for x in lines[currline+6+a2].split()])

    answer = set1.intersection(set2)

    # print set1, set2, answer

    currline += 10

    if len(answer)==1:
        print "Case #"+ str(t) + ": " + str(answer.pop())
    elif len(answer)==0:
        print "Case #"+ str(t) + ": Volunteer cheated!"
    else:
        print "Case #"+ str(t) + ": Bad magician!"
