import sys

def helper(num_mushrooms):
  prev_n = -1
  num_eaten = 0
  for n in num_mushrooms:
    if prev_n != -1 and n < prev_n:
        num_eaten += (prev_n - n)
        assert (prev_n - n) > 0, "Number of mushrooms eaten cannot be negative"
    prev_n = n
          
  return num_eaten

def helper2(num_mushrooms):
  biggest_difference = 0
  prev_n = -1
  for n in num_mushrooms:
    if prev_n != -1:
      if prev_n - n > biggest_difference:
          biggest_difference = prev_n - n
    prev_n = n

  num_eaten = 0
  for n in num_mushrooms[:-1]:
    num_eaten += min(n, biggest_difference)
  return num_eaten

def parse_file(num_lines):
  with open(sys.argv[1], 'r') as f:
    lines = [l.rstrip('\n') for l in f.readlines()]
  i = 1
  tests = []
  while i < len(lines):
    new_test = []
    for j in range(num_lines):
      new_test.append(lines[i])
      i += 1
    tests.append(new_test)
  return int(lines[0]), tests

num_tests, tests = parse_file(2)
for case,test in enumerate(tests):
  num_mushrooms = [int(x) for x in test[1].split()]
  sol1 = helper(num_mushrooms)
  sol2 = helper2(num_mushrooms)
  print 'Case #{}: {} {}'.format(case+1, sol1, sol2)
  #sol = helper(test)
  #print 'Case #{}: {}'.format(case+1, sol)
