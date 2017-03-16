def anyShroomsAnyTime(shrooms):
   sum = 0
   for i in range(len(shrooms)-1):
      if shrooms[i] - shrooms[i+1] > 0:
         sum += shrooms[i] - shrooms[i+1]
   return sum

def contantShrooms(shrooms):
   max = 0
   for i in range(len(shrooms)-1):
      if shrooms[i] - shrooms[i+1] > max:
         max = shrooms[i] - shrooms[i+1]
   min = max # min per every 10 seconds
   sum = 0
   for i in range(len(shrooms)-1):
      sum += min if shrooms[i] > min else shrooms[i]
   return sum

file = open('A-small-attempt0.in', 'r')
out = open('outputA.txt', 'w')
num = int(file.readline().strip())

for x in range(num):
   n = int(file.readline().strip())
   s = file.readline().strip().split(' ')
   s = list(map(int, s))
   out.write('Case #'+str(x+1)+': ' + str(anyShroomsAnyTime(s)) + ' ' + str(contantShrooms(s)) + '\n')

file.close()
out.close()