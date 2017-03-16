t=int(raw_input())
f=open('a.txt','w')
for _ in xrange(1,t+1):
   b,n=map(int,raw_input().split())
   l=map(int,raw_input().split())
   for i in xrange(10):
      l=l+l
   o=[ 10**15, b+1]
   for a in xrange(1,b+1):
      L=1
      h=10**30
      while L<=h:
         mid=(L+h)/2
         d=0
         for i in xrange(a):
            d+=(mid+l[i]-1)/l[i]
         for i in xrange(a,b):
            d+=(mid-1+l[i]-1)/l[i]
         if d<n:
            L=mid+1
         else:
            h=mid-1
      if o[0]>h+1:
         o[0]=h+1
         o[1]=a
   f.write('Case #%d: %d\n' %(_,o[1]))
f.close()
