import math
import itertools

f = open("B-small-attempt0.in", "r")
tests = int(f.readline())
out = open("B-small.out", "w")
for t in range(tests):
  r, c, n = map(int, f.readline().split())
  points = []
  for i in range(r):
    for j in range(c):
      points.append([i, j])
  best = 10000
  for subset in itertools.combinations(points, n):
    grid = []
    for i in range(r):
      row = []
      for j in range(c):
        row.append(0)
      grid.append(row)
    for point in subset:
      grid[point[0]][point[1]] = 1
    test = 0
    for i in range(r):
      for j in range(c):
        if grid[i][j] == 1:
          if j + 1 < c and grid[i][j+1] == 1:
            test += 1
          if i + 1 < r and grid[i+1][j] == 1:
            test += 1
    best = min(test, best)
  out.write("Case #{1}: {0}\n".format(best, t + 1))
