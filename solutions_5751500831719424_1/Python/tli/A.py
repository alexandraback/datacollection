from numpy import median

t = int(raw_input())

for i in xrange(t):
  ns = int(raw_input())
  s = []
  for j in xrange(ns):
    s.append(raw_input())

  prev = s[0][0]
  reduced = s[0][0]


  for ch in s[0][1:]:
    if ch == prev:
      continue
    else:
      reduced += ch
      prev = ch

  indexes = [0 for j in xrange(ns)]
  fail = False

  count = 0

  for ch in reduced:
    num = [0 for j in xrange(ns)]
    for j in xrange(ns):
      while indexes[j] < len(s[j]) and s[j][indexes[j]] == ch:
        indexes[j] += 1
        num[j] += 1
    if min(num) == 0:
      fail = True
      break
    else:
      num.sort()
      middle = num[len(num) / 2]
      for n in num:
        count = count + abs(n - middle)
  if not fail:
    for j in xrange(ns):
      if indexes[j] != len(s[j]):
        fail = True
        break
  if fail:
    print "Case #" + str(i + 1) + ":", "Fegla Won"
  else:
    print "Case #" + str(i + 1) + ":", count



