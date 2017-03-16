IN = open("in", 'r')
OUT = open("out", 'w')

n = IN.readline()

for x in xrange(0, int(n)):
  MNum = int ( IN.readline().strip() ) 
  mushroms = map(int, IN.readline().strip().split(' ')) 
  miMush = 0
  rateMush = 0 
  difMin = 0
  difMinold = 0

  
  for n in range(1,MNum):
    difMin = mushroms[n-1]-mushroms[n]
    if difMin>0:
      miMush += difMin
    if difMin > difMinold:
      difMinold = difMin
      
      
  for i in range(1,MNum):
    if difMinold >  mushroms[i-1]:
      rateMush += mushroms[i-1]
    else:
      rateMush += difMinold

  outP = "Case #" + str(x+1) + ": " + str(miMush)+ ' '+ str(rateMush) + "\n"
  OUT.write(outP)
  print outP
OUT.close()
IN.close()
