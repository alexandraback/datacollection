import sys

def get_row(row):
    r = 0
    for i in range(1,5):
        l = sys.stdin.readline().strip()
        if(i==row):
            r = l.split()
    return r


T = int(sys.stdin.readline().strip())
for trial in range(1, T+1):
  print 'Case #%d:' % trial,

  r1 = sys.stdin.readline().strip()
  row1 = get_row(int(r1))
  r2 = sys.stdin.readline().strip()
  row2 = get_row(int(r2))
  intersect = [x for x in row1 if x in row2]
  if(len(intersect)==0):
    print "Volunteer cheated!"
  elif(len(intersect)==1):
    print intersect[0]
  else:
    print "Bad magician!"
