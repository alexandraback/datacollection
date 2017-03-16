T = raw_input()
for t in range(int(T)):
  N = int(raw_input())
  d = []
  for n in range(N):
    d.append(list(raw_input()))
  now = d[0][0]
  FG = 1

  for i in d:
    if i[0] != now:
      FG = 0
      # print 'jizz'
  C = 0
  while FG == 1 and d[0] != []:
    now = d[0][0]

    for i in d:
      if i == [] or i[0] != now :
        FG = 0    
    # print now
    have = []
    for i_i, i in enumerate(d):
      if len(i) == 0:
        FG = 0
      tmp = 0
      while tmp < len(i) and i[tmp] == now :
        # print i
        tmp += 1
      # print tmp
      have.append(tmp)
      d[i_i] = i[tmp:]
    # print sorted(have)    
    for i in have:
      C += abs(i - sorted(have)[int(len(have)/2.)])
  # print d  
  for i in d:
    if i != []:
      FG = 0
  if FG == 0:
    ans = 'Fegla Won'
  else:
    ans = str(C)
    pass
  print 'Case #%d: %s' % (t+1, ans)
  

  
  