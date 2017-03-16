NNN = int(raw_input())
for nnn in xrange(1, NNN+1):
  print "Case #%d:" % (nnn),
  row = [0]*2
  mat = [[[0]*4 for x in xrange(4)] for y in xrange(2)]
  for i in xrange(2):
    row[i] = int(raw_input()) - 1
    for j in xrange(4):
      mat[i][j] = [int(x) for x in raw_input().split()]

  ans = [mat[1][row[1]][i] for i in xrange(4) if mat[1][row[1]][i] in mat[0][row[0]]]
  if len(ans) == 0:
    print "Volunteer cheated!"
  elif len(ans) > 1:
    print "Bad magician!"
  else:
    print ans[0]
