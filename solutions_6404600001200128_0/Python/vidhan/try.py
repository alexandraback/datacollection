t=int(raw_input())
f=open('a.txt','w')
for _ in xrange(1,t+1):
   n=int(raw_input())
   l=map(int,raw_input().split())
   ans1,ans2,mx=0,0,0
   for i in xrange(1,n):
      if l[i]-l[i-1]<0:
         ans1+=l[i-1]-l[i]
      mx=max(mx,l[i-1]-l[i])
   for i in xrange(n-1):
      if l[i]>=mx:
          ans2+=mx
      else:
          ans2+=l[i]
   f.write('Case #%d: %d %d\n' %(_,ans1,ans2))
f.close()
