t=input()
for c in range(1, t+1):
  r = input()
  r -= 1
  a = []
  for i in range(4):
    a.append(map(int,raw_input().split()))
  u = set(a[r])
  r = input()
  r -= 1
  a = []
  for i in range(4):
    a.append(map(int,raw_input().split()))
  v = set(a[r])
  res = 'Volunteer cheated!'
  if len(u & v) == 1:
    res = str((u & v).pop())
  if len(u & v) > 1:
    res = 'Bad magician!'
  print 'Case #%d: %s' % (c, res)
