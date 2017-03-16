def destutter(s):
  chars = []
  for c in s:
    if chars == []:
      chars.append(c)
    elif chars[-1] != c:
      chars.append(c)
  return ''.join(chars)

def lengths(s):
  lengths = []
  for c in s:
    if lengths == []:
      last = c
      lengths.append(1)
    elif c == last:
      lengths[-1] += 1
    else:
      last = c
      lengths.append(1)
  return lengths


t = int(raw_input())

ns = []
strings = []

for i in xrange(t):
  n = int(raw_input())
  ns.append(n)
  s = []
  for i in xrange(n):
    s.append(raw_input())
  strings.append(s)

outputs = []

for i in xrange(t):
  n = ns[i]
  string_list = strings[i]

  fegla_won = False
  destuttered = map(destutter, string_list)
  for d in destuttered:
    if d != destuttered[0]:
      fegla_won = True
  if fegla_won:
    outputs.append("Case #%d: Fegla Won" % (i + 1))
  else:
    moves = 0
    m = len(destuttered[0])
    lengths_list = map(lengths, string_list)
    for j in xrange(m):
      min_dist = 1000000
      for k in xrange(101):
        dist = sum([abs(l[j] - k) for l in lengths_list])
        if dist < min_dist:
          min_dist = dist
      moves += min_dist
    outputs.append("Case #%d: %d" % (i + 1, moves))

print '\n'.join(outputs)
