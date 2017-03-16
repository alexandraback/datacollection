import functools

def gcd(a, b):
  """Return greatest common divisor using Euclid's Algorithm."""   
  while b:      
    a, b = b, a % b
  return a

def lcm(a, b):
  """Return lowest common multiple."""
  return a * b // gcd(a, b)

def lcmm(l):
  """Return lcm of args."""   
  return functools.reduce(lcm, l)


for tc in range(int(input())):
  numbarbers, place = [int(x) for x in input().split()]
  times = [int(x) for x in input().split()]
  progress = [0 for x in times]
  cycle = lcmm(times)
  time = 0
  #the game cycles regularly - all barbers are free at the same time sometimes
  servedpercycle = sum([cycle//t for t in times])
  place = place % servedpercycle
  if place == 0: place = servedpercycle
  #now we can just use brute force
  while place != 0:
  	next= min(progress)
  	nextindex = progress.index(next)
  	progress = [x-next for x in progress]
  	progress[nextindex] = times[nextindex]
  	place -= 1

  print ("Case #%d: %d" % (tc+1, nextindex+1))