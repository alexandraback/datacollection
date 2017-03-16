import fractions
def trans(arr, m):
  for j in range(len(arr)):
    arr[j] = max(arr[j]-m, 0)
  return arr
f = open('B-small-attempt0.in')
o = open('output.txt', 'w')
n = int(f.readline())

def lcm(a,b):
  return a*b/fractions.gcd(a,b)

for i in range(n):
  b, z = [int(x) for x in f.readline().strip().split(" ")]
  arr = [int(x) for x in f.readline().strip().split(" ")]
  res = -1
  free = [True]*b
  mod = arr[0]
  for x in arr:
    mod = lcm(mod, x)
  
  new_mod = sum([mod / x for x in arr])
  #print new_mod
  z = z % new_mod
  if z == 0:
    z = new_mod
  q = []
  q = sorted(q, key=lambda x:x[0])
  while z > 0:
    #print z
    if True in free:
      for j in range(b):
        if free[j]:
          free[j] = False
          q.append((arr[j], j))
          z -= 1
        if z == 0:
          res = j
          break
    else:
      u = q.pop(0)
      free[u[1]] = True
      q = [(x[0]-u[0], x[1]) for x in q]
      while q and q[0][0] <= 0:
        u = q.pop(0)
        free[u[1]] = True
    if res != -1:
      break
    q = sorted(q)
  o.write('Case #'+str(i+1)+': '+str(res+1)+'\n')
  #print res+1