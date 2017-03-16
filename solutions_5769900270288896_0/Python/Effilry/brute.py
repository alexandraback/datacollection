import itertools

def readint():  return int(input())
def readline(): return input().split()
def readints(): return list(map(int, readline()))

def neighbors(grid, x, y, p = None):
  if p != None: grid[p[1]][p[0]] = 0
  res = (0 if x == 0                else grid[y][x - 1]) + \
        (0 if x == len(grid[0]) - 1 else grid[y][x + 1]) + \
        (0 if y == 0                else grid[y - 1][x]) + \
        (0 if y == len(grid) - 1    else grid[y + 1][x])
  if p != None: grid[p[1]][p[0]] = 1
  return res

def solve(R,C,N):
  def to_xy(i):
    return i % C, i // C

  to_improve = []
  grid = [[0] * C for _ in range(R)]
  unh = 0
  for i in range(N):
    minval = float('infinity')
    minpoint = None
    for (x,y) in itertools.product(range(C), range(R)):
      if grid[y][x] == 0:
        minval = min(minval, neighbors(grid,x,y))
    for (x,y) in itertools.product(range(C), range(R)):
      if grid[y][x] == 0 and neighbors(grid,x,y) == minval:
        minpoint = (x,y)
        break
    unh += neighbors(grid, x, y)
    to_improve += [(x,y)]
    grid[y][x] = 1

  # improve assignment
  while len(to_improve) > 0:
    x, y = to_improve.pop()
    minpoint = None
    minval = float('infinity')
    for (x1,y1) in itertools.product(range(C), range(R)):
      if neighbors(grid, x1, y1) < minval and grid[y1][x1] == 0:
        minval = neighbors(grid, x1, y1, (x,y))
        minpoint = (x1,y1)
  # for row in grid: print(row)
  # print("try to move {}: best is {} @ {}".format((x,y), minpoint, minval))
  # print(unh, neighbors(grid,x,y), neighbors(grid,minpoint[0],minpoint[1]))
    if minval < neighbors(grid, x, y):
      x1, y1 = minpoint
      unh -= neighbors(grid,  x,  y)
      grid[y][x]   = 0
      grid[y1][x1] = 1
      unh += neighbors(grid, x1, y1)
      to_improve += [minpoint]

# for row in grid: print(row)

  return unh

_T = readint()
for _t in range(_T):
  R, C, N = readints()
  print("Case #{}: {}".format(_t + 1, solve(R,C,N)))

