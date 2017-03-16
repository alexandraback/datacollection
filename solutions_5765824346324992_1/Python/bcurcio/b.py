import fractions
import sys


def can(t,l):
  ans = 0
  
  for e in l:
    ans+= t/e + 1 
  
  return ans

def solve():
  ans = 0
  
  B, N = map(int,raw_input().split())
  m = map(int, raw_input().split()) 
  
  if(N<=B):
    print N
    return 0
    
  inf = 0
  sup = 100000 * (10**9+1)
  

  
  while(inf+1!=sup):
    mid = (inf + sup) / 2
    #~ print mid,can(mid,m)
    if(can(mid,m) >= N ):
      sup = mid
    else:
      inf = mid
  
  barbero = 0
  
  #~ print inf,can(inf,m)
  
  N -= can(inf,m)
  
  barberos = []
  
  for i in xrange(len(m)):
    barberos.append([((inf/m[i])+1) * m[i],i])
    
  #~ print barberos
    
  while(N>0):
    barberos.sort()
    barbero = barberos[0][1]
    barberos[0] = (barberos[0][0] + m[barbero] , barbero)
    N -= 1
    
  
  
  print barbero+1
  
  
  
  

t = int(raw_input())
for c in xrange(1,t+1):
  print 'Case #%d:' %(c),
  solve()
