import sys
from collections import defaultdict
sys.stdin.readline()

def min_dist(words):
  edits = 0
  i = 0
  done = False
  while not done:
    freq = defaultdict(int)
    for w in words:
      if i < len(w):
        freq[w[i]] += 1

    majority = ''
    for f in freq:
      if freq[f] >= n/2:
        majority = f
    # print(majority)

    for j, w in enumerate(words):
      if i >= len(w):
        if majority != '':
          if i-1 < len(w) and w[i-1] == majority:
            w = w + w[i-1]
            edits += 1
          else:
            return 'IMPOSSIBLE'
        else:
          continue

      if w[i] != majority:
        if i > 0 and w[i-1] == majority:
          w = w[:i] + w[i-1] + w[i:]
          edits += 1
        else:
          while i < len(w) and w[i] != majority and w[i-1] == w[i]:
            w = w[:i] + w[i+1:]
            edits += 1
      if (majority != '' and i >= len(w)) or (i < len(w) and w[i] != majority):
        return 'IMPOSSIBLE'
      words[j] = w

    # print(words)
    i += 1

    done = True
    for w in words:
      if i < len(w):
        done = False

  return edits

case = 0
while True:
  case += 1
  line = sys.stdin.readline()
  if line == '':
    break
  n = int(line)

  words = []
  for i in range(n):
    words.append(sys.stdin.readline().strip())

  d = min_dist(words)
  if d == 'IMPOSSIBLE':
    print('Case #%d: Fegla Won' % case)
  else:
    print('Case #%d: %d' % (case, d))
