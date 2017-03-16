T = int(raw_input().strip())

for cas in range(1,T+1):
  print "Case #" + str(cas) + ":",
  N = int(raw_input().strip())
  tmp = raw_input().strip().split()
  S = []
  for i in range(len(tmp)):
    S.append( (int(tmp[i]),chr(ord('A') + i)) )
  S.sort()
  S = S[::-1]

  #print S

  #major two
  if(S[0][0] != S[1][0]):
    maxLeft = S[0][0] - S[1][0]
    time = maxLeft/2
    for i in range(time):
      print S[0][1] + S[0][1],
    if(maxLeft%2 == 1):
      print S[0][1],
    S[0] = (S[1][0],S[0][1])

  #print S

  while(len(S) != 2):
    left = S[2][0] 
    time = left/2
    for i in range(time):
      print S[2][1] + S[2][1],
    if(left%2 == 1):
      print S[2][1],
    S.pop(2)
  
  #print S

  #only two eaqual left
  eachLeft = S[0][0]
  pair = S[0][1] + S[1][1]
  for i in range(eachLeft):
    print pair,
  print ''
