f = open('B-small-attempt0.in')
o = open('output.txt', 'w')
n = int(f.readline())

for i in range(n):
  r,c,y = [int(x) for x in f.readline().split(" ")]
  print i, r,c,y
  poss = 2**(r*c)
  score = r*c*4
  for j in range(poss):
    arr = []
    for a in range(r):
      row = []
      for b in range(c):
        row.append(j%2 == 0)
        j /= 2
      arr.append(row)
    if sum([row.count(True) for row in arr]) == y:
      #print arr
      temp_score = 0
      for a in range(r):
        for b in range(c):
          if arr[a][b]:
            if a < r-1 and arr[a+1][b]:
              #print a,b
              temp_score += 1
            if b < c-1 and arr[a][b+1]:
              #print a,b
              temp_score += 1
      score = min(score, temp_score)
  o.write('Case #'+str(i+1)+': '+str(score)+'\n')
o.close()
f.close()

"""
arr = []
bad = []
occ = []
for j in range(r):
  arr.append([0]*c)
  bad.append([0]*c)
  occ.append([False]*c)
for j in range(r):
  for k in range(c):
    score = 4
    if j == 0 or j == r-1:
      score -= 1
    if k == 0 or k == c-1:
      score -= 1
    arr[j][k] = score

print arr
for z in range(y):
  best_score = min([a for b in bad for a in b ])
  q = []
  for j in range(r):
    for k in range(c):
      if bad[j][k] == best_score:
        q.append((arr[j][k], j,k))
  q = sorted(q)
  _,x, y = q[0]
  occ[x][y] = True
  bad[x][y] = 10000000
  if x-1 >= 0:
    bad[x-1][y] += 1
  if x+1 < r:
    bad[x+1][y] += 1
  if y-1 >= 0:
    bad[x][y-1] += 1
  if y+1 < c:
    bad[x][y+1] += 1
  print occ
  print bad
"""