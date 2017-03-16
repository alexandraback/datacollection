def howLong(b, n, m):
   num = numDonePerCycle(m)
   assert num != 0 , 'num = 0'
   n = n % num
   if n == 0:
      n = num
   if n <= b:
      return n
   time = m[:]
   person = b+1 # the next person in line
   while(person <= n):
      #print('started the loop with: n=%d person=%d '%(n,person) + str(time))
      mins = min(time)
      ind = time.index(mins)
      assert ind != None , 'bad index'
      if mins == 0:
         if person == n:
            return ind + 1
         person += 1
         assert time[ind] == 0 , 'bad timing'
         time[ind] = m[ind]
      else:
         for x in range(b):
            time[x] -= mins
   return -1 # means it broke

def numDonePerCycle(m): # works
   g = gcm(m)
   num = 0
   for x in m:
      num += g / x
   return num

def gcm(l): # works
   m = max(l)
   g = m
   while not allmults(g, l):
      g += m
   return g

def allmults(g,l): # works
   for x in l:
      if g % x != 0:
         return False
   return True

file = open('B-small-attempt1.in', 'r')
out = open('outputB.txt', 'w')
num = int(file.readline().strip())

for x in range(num):
   l = file.readline().strip().split(' ')
   s = list(map(int, file.readline().strip().split(' ')))
   out.write('Case #'+str(x+1)+': ' + str(howLong(int(l[0]),int(l[1]),s)) + '\n')
   print('done with %d'%(x+1))

file.close()
out.close()