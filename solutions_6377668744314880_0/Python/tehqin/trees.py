
from itertools import combinations

T = int(raw_input())

def sub(a, b):
   return (a[0]-b[0], a[1]-b[1])

def cross(a, b):
   return a[0]*b[1]-a[1]*b[0]

def cross3(p, a, b):
   return cross(sub(a, p), sub(b, p))

def convexHull(vs):
   H = [('$','$')] * (len(vs)*3+3)
   k = 0
   n = len(vs)
   def compareFunc(a, b):
      if a[0] == b[0]:
         return a[1]-b[1]
      return a[0]-b[0]
   vs = sorted(vs, cmp=compareFunc)
   for i in range(n):
      while k >= 2 and cross3(H[k-2], H[k-1], vs[i]) < 0:
         k -= 1
      H[k] = vs[i]
      k += 1
   for i in range(n-2, -1, -1):
      while k >= 2 and cross3(H[k-2], H[k-1], vs[i]) < 0:
         k -= 1
      H[k] = vs[i]
      k += 1
      
   return H[:k]

for tc in range(1, T+1):
   N = int(raw_input())
   vs = []
   for i in range(N):
      vs.append(tuple(int(v) for v in raw_input().split()))
   
   toId = {}
   for i, v in enumerate(vs):
      toId[v] = i
   
   result = [N] * N
   for k in range(N):
      for term in combinations(vs, N-k):
         hull = convexHull(list(term))
         for v in hull:
            curId = toId[v]
            result[curId] = min(result[curId], k)
  
   print 'Case #'+str(tc)+':'
   for r in result:
      print r
