#! /usr/bin/env python
import sys

if len(sys.argv) < 2:
  print "Please give me an input file."
  sys.exit(1)

input_file = open(sys.argv[1], 'r')
test_count = int(input_file.readline())

if len(sys.argv) < 3:
  output = sys.stdout
  print "Not given output file, writing to stdout."
else:
  output = open(sys.argv[2], 'w')
  print "Writing to '%s'" % sys.argv[2]

def PosToChar(pos):
  return chr(ord('A') + pos)

for test_case in range(1, test_count + 1):
  N = int(input_file.readline().strip())
  Ps = map(int, input_file.readline().strip().split(' '))
  # The number of senators
  count = sum(Ps)
  Ps = list(map(list, enumerate(Ps)))
  result = []
  while count > 0:
    Ps = sorted(Ps, key=lambda senator: senator[1], reverse=True)
    char1 = Ps[0][0]
    Ps[0][1] -= 1
    count -= 1
    Ps = sorted(Ps, key=lambda senator: senator[1], reverse=True)
    skip = False
    for character, P in Ps[1:]:
      if ((P * 2) > (count - 1)):
        skip = True
        break
    if not skip:
      char2 = Ps[0][0]
      Ps[0][1] -= 1
      count -= 1
      result.append(PosToChar(char1) + PosToChar(char2))
    else:
      result.append(PosToChar(char1))

  output.write('Case #%d: ' % test_case)
  output.write(' '.join(result))
  output.write('\n')
