fname = "A-small-attempt0.in"

M = 4

def main():
  with open(fname) as f:
    for i in xrange(int(f.readline())):
      row1 = int(f.readline())
      mat1 = [map(int, f.readline().split()) for j in xrange(M)]
      want1 = mat1[row1-1]
      row2 = int(f.readline())
      mat2 = [map(int, f.readline().split()) for j in xrange(M)]
      want2 = mat2[row2-1]
      
      sect = set(want1) & set(want2)
      x = len(sect)
      if x == 0:
        res = "Volunteer cheated!"
      elif x == 1:
        res = (set(want1) & set(want2)).pop()
      else:
        res = "Bad magician!"
      print 'Case #%s: %s' % (i + 1, res)
  
main()