f = open("A-large.in","rt")
O = open("A-large.out", "wt")

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
    S = "Case #%d: " %(t+1)                           
    S += sol()
    O.write(S)
    O.write("\n")
    print S