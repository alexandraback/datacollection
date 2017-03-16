
'''
Created on Apr 12, 2013

@author: herman
'''


infile = open("input.txt","r")
outfile = open("output.txt","w")

trials = int(infile.readline())

def perform(answer,arrange):
    possible = []
    for j in xrange(2):
        possible.append([])
        for i in xrange(4):
            possible[j].append(arrange[j][answer[j]-1][i])
    
    intersect = list(set(possible[0]) & set(possible[1]))
    if len(intersect) == 0:
        return 'Volunteer cheated!'
    elif len(intersect) > 1:
        return 'Bad magician!'
    else:
        return str(intersect[0])


for i in xrange(trials):
    answer,arrange = [],[]
    for j in xrange(2):
        answer.append(int(infile.readline()))
        arrange.append([[int(n) for n in infile.readline().split()] for j in xrange(4)])

    s = "Case #%d: %s\n" % (i+1,perform(answer,arrange))
    outfile.write(s)
    print s
    
infile.close()
outfile.close()
