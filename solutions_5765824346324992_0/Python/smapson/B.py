import math
import heapq

def mod(a,b):
  a %= b
  a += b
  return a%b

t = int(raw_input())
for testcase in range(t):
  [b, n] = [int(x) for x in raw_input().split()]
  line = [int(x) for x in raw_input().split()]
  cut_per_second = sum(float(1)/x for x in line) + 0.0001
  lower = math.floor(float(n)/cut_per_second) #still at least getting his hair cut
  lower = int(lower) - max(line) #definitely hasnt started haricut
  if lower < 0: lower = 0
  already_cut = sum((lower+x-1)/x for x in line)
  hairq = [(mod(-lower,line[index]),index) for index in range(b)]
  heapq.heapify(hairq)
  for _ in range(n - already_cut - 1):
    (time,index) = heapq.heappop(hairq)
    heapq.heappush(hairq,(time+line[index],index))
  (time,index) = heapq.heappop(hairq)
  print "Case #%s: %s"%(testcase+1, index+1)
