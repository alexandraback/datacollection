f=open("A-large.in","r")
g=open("repeatl.out","w")

T = int(f.readline())

for i in range(0,T):
  N = int(f.readline()) 
  L = [f.readline().split()[0] for j in range(0,N)]
  O = []
  check = []
  for w in L:
    aux = [1]
    c = [w[0]]
    for k in range(1,len(w)):
      if w[k] == w[k-1]:
        aux[-1] += 1
      else:
        aux.append(1)
        c.append(w[k])
    O.append(aux) 
    check.append(c)
  pos = 0
  for k in range(0,len(check)):
    if check[k] != check[0]:
      pos = 1

  if pos == 1:
    ans = 'Fegla Won'
  else:
    M = len(check[0])
    medio = N/2
    S = 0
    for l in range(0,M):
      auxS = 0 
      P = sorted([O[u][l] for u in range(0,N)])
      for k in range(0,N):
        auxS = auxS + abs(P[k] - P[medio])
      S = S + auxS
    ans = str(S)

  g.write("Case #"+str(i+1)+": "+ans+"\n")

  
  
  
