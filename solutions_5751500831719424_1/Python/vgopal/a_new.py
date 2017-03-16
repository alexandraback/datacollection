f = open('a_large.txt')
T = int(f.readline())
for turn in range(1, T+1):
  N = int(f.readline().strip())
  strings = [f.readline().strip() for _ in range(N)]

  length = max(len(s) for s in strings)
  possible = True
  index = 0
  moves = 0
  uniques = []
  for string in strings:
    c = string[0]
    unique = c
    for char in string:
      if char != c:
        c = char
        unique += c
    uniques.append(unique)

  test = uniques[0]
  for unique in uniques:
    if unique != test:
      possible = False
      break

  unique = uniques[0]
  indices = [0]*len(strings)
  if possible:
    for char in unique:
      lengths = [0]*len(strings)
      for i, string in enumerate(strings):
        length = 0
        while indices[i] < len(string) and string[indices[i]] == char:
          length += 1
          indices[i]+=1
          lengths[i] = length
      min_moves = float('inf')
      for num in range(1,101):
        val = sum(abs(num-x) for x in lengths)
        if val < min_moves:
          min_moves = val
      moves += min_moves



  if possible:
    print "Case #" + str(turn) + ":", moves
  else:
    print "Case #" + str(turn) + ":", "Fegla Won"
