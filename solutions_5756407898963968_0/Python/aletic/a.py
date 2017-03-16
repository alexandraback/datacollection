



n = int(raw_input())
for c in xrange(1,n+1):
  a1 = int(raw_input()) - 1
  m = [map(int, raw_input().split()) for i in xrange(4)]
  a2 = int(raw_input()) - 1
  m2 = [map(int, raw_input().split()) for i in xrange(4)]
  result = filter(None,[x if x in m2[a2] else None for x in m[a1]])
  print 'Case #{}:'.format(c),
  if len(result) == 1:
    print result[0]
  elif len(result) > 1:
    print 'Bad magician!'
  else:
    print 'Volunteer cheated!'
    