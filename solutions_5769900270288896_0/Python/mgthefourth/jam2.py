import itertools

#bruteforce for up to 16 tennants maximum of less than a million cases



#calculate occupied neighbours
def neighbours(x, y, residents):
 return sum([0 + ((x+i, y+j) in residents) for i in (-1, 0, 1) for j in (-1, 0, 1) if (i!=j and (i==0 or j==0))])


#returns unhappiness
def unhappiness(residents):
  return sum([neighbours(x, y, residents) for (x, y) in residents])/2


#all possible combinations of people
def arrangements(available, tennants):
  return list(itertools.combinations((available), tennants))

#generate available places
def available(r, c):
  return set([(a,b) for a in range(r) for b in range(c)])

for tc in range(int(input())):
  line = [int(x) for x in input().split()]
  R = line[0]
  C = line[1]
  N = line[2]

  u = min([unhappiness(x) for x in arrangements(available(R, C), N)])

  print ("Case #%d: %d" % (tc+1, u))
