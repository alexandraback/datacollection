IN = open("in", 'r')
OUT = open("out", 'w')

n = IN.readline()

from fractions import gcd
def lcm(numbers):
    return reduce(lambda x, y: (x*y)/gcd(x,y), numbers, 1) 

for x in xrange(0, int(n)):
  B = map(int, IN.readline().strip().split(' ')) 
  barbers = map(int, IN.readline().strip().split(' ')) 
  barbersCopy = barbers[:]
  barbCount = B[0]
  people = B[1]
  rate = 1 # min(barbers)
  waiting = True
  ans = 0

  ppr = 0

  mcm = lcm(barbers)
  for i in range(0,barbCount):
    ppr += mcm/barbers[i]
    
  
  if waiting:
    people = people % ppr
    if people == 0:
      people = ppr
      
  
  if waiting:   
     if people <= barbCount:
        ans = people
        waiting = False
     else:
        people -= barbCount       


  while waiting:
    for n in range(0,barbCount):
      barbersCopy[n] -= rate
      
      if barbersCopy[n]<=0:

        barbersCopy[n] = barbers[n]
        people -=1
        if people == 0:
          ans = n+1
          waiting = False
          break
  print ans
  outS = "Case #" + str(x+1) + ": " + str(ans) + "\n"
  OUT.write(outS)
        

OUT.close()
IN.close()
