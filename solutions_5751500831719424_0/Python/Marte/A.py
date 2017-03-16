
def comp_word(s):
  comps = []
  last = '_'
  for c in s:
    if c == last:
      comps[-1][1] += 1
    else:
      comps.append([c, 1])
      last = c
  return comps

def base(word):
  return ''.join([x for x, y in word])

for cas in xrange(1, input()+1):
  print "Case #%d:" % cas,
  N = input()
  words = []
  bases = set()
  for _ in xrange(N):
    words.append(comp_word(raw_input()))
    bases.add(base(words[-1]))
  if len(bases) != 1:
    print 'Fegla Won'
    continue
  min_moves = 0
  for i in xrange(len(words[0])):
    min_move = 10**10
    for n in xrange(1, 101):
      mov = 0
      for word in words:
        mov += abs(word[i][1] - n)
      min_move = min(min_move, mov)
    min_moves += min_move
  print min_moves
