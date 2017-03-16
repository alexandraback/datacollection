T = int(raw_input())
for t in xrange(T):
   n = int(raw_input())
   X = map(int, raw_input().split())

   r1 = 0
   r2 = 0
   max_change = 0
   for i in xrange(len(X) - 1):
       if X[i + 1] < X[i]:
           r1 += -X[i + 1] + X[i]
       max_change = max(max_change, X[i] - X[i + 1])

   for i in xrange(len(X) - 1):
       r2 += min(max_change, X[i])

   print 'Case #%d: %d %d' % (t + 1, r1, r2)

