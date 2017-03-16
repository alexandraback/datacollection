from math import log

def howunhappy(r,c,n):
   if (r * c + 1) // 2 >= n:
      return 0
   min = float('inf')
   for apt in assortments(n, r*c):
      h = unhappiness(apt,n,r,c)
      if h < min:
         min = h
   return min

def assortments(n, l):
   for i in range(2**l):
      ls = [int(x) for x in bin(i)[2:]]
      ls = [0]*(l-len(ls))+ls
      if sum(ls) == n:
         yield ls

def unhappiness(apt,n,r,c):
   uh = 0
   for i in range(r*c):
      if apt[i] and i % c < c-1 and apt[i+1]:
         uh += 1
      if apt[i] and i < (r-1)*c and apt[i + c]:
         uh += 1
   return uh

file = open('B-small-attempt1.in', 'r')
out = open('outputB.txt', 'w')

num = int(file.readline().strip())

for x in range(num):
   l = file.readline().strip().split()
   r , c , n = int(l[0]), int(l[1]), int(l[2])
   out.write('Case #'+str(x+1)+': ' + str(howunhappy(r,c,n)) + '\n')
   print('done with %3d'%x)

#print(set(permutations([True]*2+[False],3)))
file.close()
out.close()