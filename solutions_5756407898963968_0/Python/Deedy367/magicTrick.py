import sys

def same_row(i,j): return (i/9 == j/9)
def same_col(i,j): return (i-j) % 9 == 0
def same_block(i,j): return (i/27 == j/27 and i%9/3 == j%9/3)


def magicTrick(f):
  soln = ''
  cases = int(f.readline())
  for case in xrange(cases):
    row_one = int(f.readline())-1
    for i in xrange(4):
      row = f.readline()
      if i == row_one:
        first = row.split(' ')
        first = [int(x) for x in first]
    row_two = int(f.readline())-1
    for i in xrange(4):
      row = f.readline()
      if i == row_two:
        second = row.split(' ')
        second = [int(x) for x in second]
    intersect = [val for val in first if val in second]
    if len(intersect) == 0:
      soln += 'Case #{0}: Volunteer cheated!\n'.format(case+1)
    elif len(intersect) > 1:
      soln += 'Case #{0}: Bad magician!\n'.format(case+1)
    elif len(intersect) == 1:
      soln += 'Case #{0}: {1}\n'.format(case+1,intersect[0])
  return soln

def writeOutput(file, soln):
  file.write(soln)
  file.close()

if __name__ == '__main__':
  f = open(sys.argv[1])
  soln = magicTrick(f)
  f.close()
  g = open("output.txt", "w")
  writeOutput(g, soln)

