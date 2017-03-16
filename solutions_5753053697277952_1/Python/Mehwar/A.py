import sys
cin = sys.stdin.readline
def readlist():
  return map(int, cin().split())
INF = sys.maxsize
NINF = -sys.maxsize - 1
#----------------------------------------------------------------------
from collections import defaultdict, Counter
import operator

T = int(cin())
for _t in xrange(T):
  N = int(cin())
  P = readlist()
  dic = {}
  for i, p in enumerate(P):
    dic[chr(65 +i)] = p

  ans = []
  while True:
    b = True
    for v in dic.values():
      if v: b = False
      break
    if b: break
    items = list(reversed(sorted(dic.items(), key=lambda x: x[1])))
    ans.append(items[0][0])
    dic[items[0][0]] -= 1
    ii = list(reversed(sorted(dic.items(), key=lambda x: x[1])))
    maxi = ii[0][1]
    rest = 0
    for x in ii[1:]:
      rest += x[1]
    if maxi > rest:
      ans[-1] +=  items[1][0]
      dic[items[1][0]] -= 1


  print "Case #{}: {}".format(_t + 1, ' '.join(ans))
