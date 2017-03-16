#Harsh Vardhan :)
for t in range(input()):

  b,n = map(int,raw_input().split())
  m = map(int,raw_input().split())

  for i in range(10):
          m = m+m

  def solve(res):
          low=1
          high=10**30
          while low<=high:
                  mid=(low+high)/2
                  ans=0
                  for i in range(res):
                          ans += (mid+m[i]-1)/m[i]
                  for i in range(res,b):
                          ans += (mid-1+m[i]-1)/m[i]
                  if ans < n :
                          low = mid+1
                  else:
                          high = mid-1
          return high+1

  res = [10**15, b+1]
  for ans in range(1,b+1):
          x = solve(ans)
          if res[0] > x :
                  res[0] = x
                  res[1] = ans

  print 'Case #%d: %d' % ( t+1, res[1] )

