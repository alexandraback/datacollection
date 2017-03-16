
inf = open('1.in')
numtests = int(inf.readline())

for testindex in xrange(numtests):
  frow = int(inf.readline()) - 1
  
  fdeck = []  
  for rowi in xrange(4):
     row = [int(x) for x in inf.readline().split(' ')]
     fdeck.append(row)
     
  srow = int(inf.readline()) - 1
  
  sdeck = []  
  for rowi in xrange(4):
     row = [int(x) for x in inf.readline().split(' ')]
     sdeck.append(row)

  possible = list(set(fdeck[frow]) & set(sdeck[srow]))
  
  if len(possible) == 1: 
    print 'Case #{0}: {1}'.format(testindex+1, possible[0])
  elif len(possible) > 1:
    print 'Case #{0}: Bad magician!'.format(testindex+1)
  else:
    print 'Case #{0}: Volunteer cheated!'.format(testindex+1)