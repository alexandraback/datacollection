import sys
import numpy as np
from scipy.spatial import ConvexHull

def collinear(p1, p2, p3):
  return (p1[1] - p2[1]) * (p1[0] - p3[0]) == (p1[1] - p3[1]) * (p1[0] - p2[0])

def backtrack(trees, result, level):
  if (level >= max(result)):
    return
  if (len(trees) <= 3):
    for v in range(0, len(result)):
      result[v] = min(result[v], level)
    return
  try:
    hull = ConvexHull(trees)
  except:
    for v in range(0, len(result)):
      result[v] = min(result[v], level)
    return
  for vv in range(0, len(hull.vertices)):
    for v in range(len(trees)):
      if collinear(trees[hull.vertices[vv]], trees[hull.vertices[(vv + 1) % len(hull.vertices)]], trees[v]):
        result[v] = min(result[v], level)
  for i in range(0, len(trees)):
    if (level+1 >= max(result)):
      return
    trees1 = np.delete(trees, i, 0)
    result1 = np.delete(result, i, 0)
    backtrack(trees1, result1, level + 1)
    for r in range(0, len(result1)):
      if r >= i:
        result[r+1] = min(result[r+1], result1[r])
      else:
        result[r] = min(result[r], result1[r])

def run(t):
  N, = map(int, raw_input().split())
  trees = []
  for i in range(0, N):
    x, y = map(int, raw_input().split())
    trees.append([x, y])
  trees = np.array(trees)
  result = np.ones(N) * 9999
  backtrack(trees, result, 0)

  print('Case #{}:'.format(t))
  for r in result:
    print(int(r))

T = int(raw_input())
for t in xrange(1, T + 1):
  run(t)
