import sys

def solve(case):
  first_guess = int(case[0])
  first_row = set(case[first_guess].split())
  second_guess = int(case[5])
  second_row = set(case[second_guess + 5].split())
  common = first_row.intersection(second_row)
  if (len(common) == 0):
    return 'Volunteer cheated!'
  elif (len(common) == 1):
    return common.pop()
  else:
    return 'Bad magician!'


if __name__ == '__main__':
  with open(sys.argv[1]) as f:
    cases = int(f.readline())
    for case_num in xrange(cases):
      case = []
      for i in xrange(10):
        case.append(f.readline().strip())
      print 'Case #%d: %s' % (case_num + 1, solve(case))
