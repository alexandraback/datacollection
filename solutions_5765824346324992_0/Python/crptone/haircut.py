import heapq

#f = open('haircut.txt', 'r')
f = open('B-small-attempt1.in', 'r')
g = open('haircut.out', 'w')
lines = int(f.readline())
count = 1

def lcm(x, y):
  if x > y:
    greater = x
  else:
    greater = y
  while(True):
    if((greater % x == 0) and (greater % y == 0)):
      lcm = greater
      break
    greater += 1
  return lcm

while count <= lines:
  place = int(f.readline().strip().split()[1])
  barbers = list(map(int, f.readline().strip().split()))
  h = []
  m = 1
  for i in range(len(barbers)):
    m = lcm(m, barbers[i])
    heapq.heappush(h, (0, i, barbers[i]))

  many = 0
  for i in range(len(barbers)):
    many += m // barbers[i]

  place = place - (many * (place // many))
  #print(many, place)
  if place == 0:
    place += many
  for x in range(place-1):
    e = heapq.heappop(h)
    heapq.heappush(h, (e[0] + e[2], e[1], e[2]))
  answer = heapq.heappop(h)
  #print(answer)
  
  g.write('Case #' + str(count) + ': ' + str(answer[1]+1) + '\n')
  count += 1
  
f.close()
g.close()
