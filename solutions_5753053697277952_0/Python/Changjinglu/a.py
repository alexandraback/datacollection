import string

letters = string.ascii_uppercase

num_cases = int(raw_input())
for case_index in range(1, num_cases + 1):
  n = int(raw_input())
  counts = list(map(int, raw_input().split()))
  moves = []
  while sum(counts) > 0:
    big = max(counts)
    pos = counts.index(big)
    move = [ letters[pos] ]
    counts[pos] -= 1
    if counts.count(big) % 2 == 1:
      pos = counts.index(big)
      move.append(letters[pos])
      counts[pos] -= 1
    moves.append(''.join(move))
  result = ' '.join(moves)
  print('Case #%d: %s' % (case_index, result))
