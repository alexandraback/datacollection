import fractions
import sys


def lcm(a,b):
  return a*b / fractions.gcd(a,b)

def mcm(l):
  m = 1
  for i in xrange(len(l)):
    m = lcm(m,l[i])
    
    
  cnt = 0
  for i in xrange(len(l)):
     cnt = cnt + m / l[i]

  
  return m,cnt

def solve():
  ans = 0
  
  B, N = map(int,raw_input().split())
  m = map(int, raw_input().split()) 
  
  sec,cnt = mcm(m)
  
  
  N %= cnt
  if(N==0):
    N = cnt
  
  barberos = zip([0]*B,xrange(B))
  
  while(N>0):
    barberos.sort()
    #~ print barberos
    barbero = barberos[0][1]
    barberos[0] = (barberos[0][0] + m[barbero] , barbero)
    N -= 1
    
  
  
  print barbero+1
  sys.stdout.flush()
  
  

t = int(raw_input())
for c in xrange(1,t+1):
  print 'Case #%d:' %(c),
  solve()
