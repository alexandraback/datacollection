#f = open('mushroom.txt', 'r')
f = open('A-large.in', 'r')
g = open('mushroom.out', 'w')
lines = int(f.readline())
count = 1

while count <= lines:
  n = int(f.readline())
  m = list(map(int, f.readline().strip().split()))

  biggest = 0
  x = 0
  for i in range(len(m) - 1):
    if m[i] >= m[i+1]:
      x += m[i] - m[i+1]
    biggest = max(biggest, m[i] - m[i+1])

  y = 0
  for i in range(len(m) - 1):
    y += min(biggest, m[i])
  g.write('Case #' + str(count) + ': ' + str(x) + ' ' + str(y) + '\n')
  count += 1
  
f.close()
g.close()
