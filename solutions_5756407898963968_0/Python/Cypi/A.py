def readint(): return int(raw_input())
def readarray(f): return map(f, raw_input().split())

_T = readint()
for _t in range(_T):
  print 'Case #%i:'%(_t+1),

  r1 = readint()
  G1 = []
  for i in range(4):
    G1.append(readarray(int))
  r2 = readint()
  G2 = []
  for i in range(4):
    G2.append(readarray(int))
  P1 = set(G1[r1-1])
  P2 = set(G2[r2-1])
  P = P1 & P2

  if len(P) == 0:
    print 'Volunteer cheated!'
  elif len(P) > 1:
    print 'Bad magician!'
  else:
    print list(P)[0]
