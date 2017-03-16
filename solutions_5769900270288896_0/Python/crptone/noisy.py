from copy import deepcopy

#f = open('noisy.txt', 'r')
f = open('B-small-attempt1.in', 'r')
g = open('noisy.out', 'w')
lines = int(f.readline())
count = 1
best = 99999

def traverse(m,r,c,n,h,a,b):
  global best
  #print(m,a,b)
  if n == 0:
    best = min(best, h)
  elif h < best:
    for i in range(a,r):
      for j in range(b,c):
        if not m[i][j]:
          m2 = deepcopy(m)
          m2[i][j] = True
          #print(m2,a,b)
          h2 = h
          if j < c-1 and m2[i][j+1]:
            h2 += 1
          if i < r-1 and m2[i+1][j]:
            h2 += 1
          if j > 0 and m2[i][j-1]:
            h2 += 1
          if i > 0 and m2[i-1][j]:
            h2 += 1
          if i == r - 1 and j == c - 1:
            traverse(m2,r,c,n-1,h2,i,j)
          elif j == c - 1 and i < r - 1:
            traverse(m2,r,c,n-1,h2,i+1,0)  
          else:
            traverse(m2,r,c,n-1,h2,i,j+1)
  
while count <= lines:
  l = f.readline().strip().split()
  r = int(l[0])
  c = int(l[1])
  n = int(l[2])
  
  best = 99999
  m = [[False for col in range(c)] for row in range(r)]
  traverse(m,r,c,n,0,0,0)
  print(count, best)
  g.write('Case #' + str(count) + ': ' + str(best) + '\n')
  count += 1
  
f.close()
g.close()
