import numpy as np

#f = open('A-large.in.txt', 'r')
#fr = open('A-large.out.txt', 'w')
f = open('A-small-attempt0.in', 'r')
fr = open('A-small-attempt0.out', 'w')
line = f.readline()
ntot = int(line.split()[0])
for i in range(ntot):
    line = f.readline()
    n = int(line.split()[0])
    line = f.readline()
    mylist = map(int, line.split()[:])
#    print n
#    print mylist
    lres = 0
    rres = 0
    largestInterval = 0
    for j in range(n-1):
        if mylist[j+1] < mylist[j]:
            lres = lres - mylist[j+1] + mylist[j]
            if largestInterval < (mylist[j] - mylist[j+1]):
                largestInterval = (mylist[j] - mylist[j+1])
    for j in range(n-1):
        rres = rres + min(mylist[j], largestInterval)
#    print lres, rres, largestInterval 
    fr.write('Case #'+ str(i+1) + ': ' + str(lres) + ' ' + str(rres) + '\n')
f.close()
fr.close()