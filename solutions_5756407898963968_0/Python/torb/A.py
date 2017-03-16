from sys import stdin


T = int(stdin.readline().strip())
for tc in xrange(1, T+1):
  possible = range(1, 17)
  a = int(stdin.readline().strip())
  cards = [[int(x) for x in stdin.readline().strip().split()] for i in xrange(4)]
  for i, line in enumerate(cards):
    for n in line:
      if i != a-1:
        possible[n-1] = 0
  a = int(stdin.readline().strip())
  cards = [[int(x) for x in stdin.readline().strip().split()] for i in xrange(4)]
  for i, line in enumerate(cards):
    for n in line:
      if i != a-1:
        possible[n-1] = 0
  res = filter(lambda x: x if x else 0, possible)
  if len(res) == 1:
    result = str(res[0])
  elif len(res) == 0:
    result = "Volunteer cheated!"
  else:
    result = "Bad magician!"
  print "Case #%d: %s" % (tc, result)
