def Solve():
  possible = []
  for i in xrange(2):
    correctRow = int(input())
    for j in xrange(1, 5):
      row = map(int, raw_input().split(' '))
      if j == correctRow:
        possible.append(set(row))
  result = possible[0].intersection(possible[1])
  
  if len(result) == 0: print "Volunteer cheated!"
  elif len(result) >= 2: print "Bad magician!"
  else: print next(iter(result))


if __name__ == '__main__':
  q = int(raw_input())
  for i in xrange(1, q+1):
    print "Case #%d:" % (i),
    Solve()
