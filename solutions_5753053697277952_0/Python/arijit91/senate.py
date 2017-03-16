import random

def get1(x):
  return chr(ord('A') + x)

def get2(x, y):
  return get1(x) + get1(y)

cases = int(raw_input())

t = 1
while True:
  print 'Case #%d:' % t,
  t += 1

  n = int(raw_input())
  scores = [ int(x) for x in raw_input().split() ]

  steps = []
  total = sum(scores)
  while total > 0:
    if len(scores) == 1:
      steps.append(get1(0))
      scores[0] -= 1
      total -= 1
    else:
      sorted_scores = sorted([ (x, scores[x]) for x in xrange(len(scores)) ], key = lambda x: -x[1])
      if sorted_scores[0][1] > sorted_scores[1][1]:
        steps.append(get1(sorted_scores[0][0]))
        scores[sorted_scores[0][0]] -= 1
        total -= 1
      else:
        if total != 3:
          steps.append(get2(sorted_scores[0][0], sorted_scores[1][0]))
          scores[sorted_scores[0][0]] -= 1
          scores[sorted_scores[1][0]] -= 1
          total -= 2
        else:
          steps.append(get1(sorted_scores[0][0]))
          scores[sorted_scores[0][0]] -= 1
          total -= 1

  print ' '.join(steps)

  if t == cases + 1:
    break
