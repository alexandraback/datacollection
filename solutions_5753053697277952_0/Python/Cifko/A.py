f = open("A-small-attempt0.in","rt")

def sol():
  N = int(f.readline())
  P = map(int,f.readline().split(' '))
  X = sum(P)
  plan = []
  while X:
    m = max(P)
    i = P.index(m)
    Y = chr(65+i)
    P[i] -= 1
    X-=1
    if P.count(m) and X!=2:
      i = P.index(m)
      Y += chr(65+i)
      P[i] -= 1  
      X-=1
    plan += [Y]
  return " ".join(plan)

T = int(f.readline())

for t in range(T):
    print "Case #%d:" %(t+1),                           
    print sol()