
def read_int(): return int(raw_input())
def read_pair_list(): return [(int(pair.split(',')[0]), int(pair.split(',')[1])) for pair in raw_input().split()]
def read_int_list(): return [int(x) for x in raw_input().split()]
def read_pair(): return [int(x) for x in raw_input().strip().split(',')]
def read_string(): return raw_input().strip()


def parse_input():
  T = read_int()
  cases = []
  for _ in xrange(T):
    read_int()
    cases.append(read_int_list())
  return cases


CHECK_MAJORITY = True


def solve_case(case):
  s = sum(case)
  plan = []
  while s > 0:
    m = max(case)

    ids_max = [i for i in xrange(len(case)) if case[i] == m]
    nr_max = len(ids_max)

    if nr_max % 2 == 0:
      plan.append((ids_max[0], ids_max[1]))
      case[ids_max[0]] -= 1
      case[ids_max[1]] -= 1
      s -= 2
    else:
      if plan and plan[-1] == (ids_max[0],):
        plan[-1] = (ids_max[0], ids_max[0])
      else:
        plan.append((ids_max[0],))
      case[ids_max[0]] -= 1
      s-=1



  # convert to letters
  letters = [
      [chr(ord('A') + x) for x in step] for step in plan]
  words = [''.join(x) for x in letters]
  return words




def solve_case_bf(case):
  return None


CHECK_BF = False


if __name__ == '__main__':
  for idx, args in enumerate(parse_input()):
    res = solve_case(args)
    print 'Case #%d:' % (idx + 1), ' '.join(res)

    if CHECK_BF:
      res_bf = solve_case_bf(case)
      if not res_bf == res:
        print 'ERROR: brute force solution =', res
