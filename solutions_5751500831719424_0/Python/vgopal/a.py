f = open('a_small.txt')
T = int(f.readline())
for turn in range(1, T+1):
  N = int(f.readline().strip())
  strings = [f.readline().strip() for _ in range(N)]
  length = max(len(s) for s in strings)
  possible = True
  if N == 2:
    one = strings[0]
    two = strings[1]
    index = 0
    moves = 0
    while index + 1 < length:
      # print one
      # print two
      # print '---------', moves
      if one[index] != two[index]:
        possible = False
        break
      elif len(one) > index+1 and len(two) > index+1 and one[index+1] == two[index+1]:
        index += 1
      elif len(one) > index+1 and len(two) > index+1:
        if one[index] == one[index+1]:
          one = one[:index+1] + one[index+2:]
        elif two[index] == two[index+1]:
          two = two[:index+1] + two[index+2:]
        else:
          possible = False
          break
        moves += 1
      elif len(one) > index + 1:
        if one[index] == one[index+1]:
          one = one[:index+1] + one[index+2:]
        else:
          possible = False
          break
        moves += 1
      elif len(two) > index + 1:
        if two[index] == two[index+1]:
          two = two[:index+1] + two[index+2:]
        else:
          possible = False
          break
        moves += 1
      else:
        break

  if possible:
    print "Case #" + str(turn) + ":", moves
  else:
    print "Case #" + str(turn) + ":", "Fegla Won"
