
T = int(raw_input())

for tc in range(1, T+1):
   B, N = tuple(int(v) for v in raw_input().split())
   vs = [int(v) for v in raw_input().split()]

   def numCut(time):
      result = 0
      for v in vs:
         result += 1 + (time / v)
      return result

   lo = 0
   hi = 10 ** 25
   while lo < hi:
      m = (lo+hi)/2
      if numCut(m) < N:
         lo = m+1
      else:
         hi = m
   #print lo, hi

   available = []
   for cur, v in enumerate(vs):
      if hi % v == 0:
         available.append(cur)
   curCut = N-numCut(hi)
   #print curCut
   #print available

   pos = len(available)+curCut-1
   output = 'Case #'+str(tc)+': '+str(available[pos]+1)
   print output
