#!/usr/bin/env python3.3

def _get_row():
  nr = int(input())-1
  for r in range(4):
    line = input()
    if r == nr:
      res = set(int(num) for num in line.split())
  return res


def main():
  tests = int(input())
  for case in range(tests):
    common = _get_row() & _get_row()
    if not common:
      result = 'Volunteer cheated!'
    elif len(common) > 1:
      result = 'Bad magician!'
    else:
      result = common.pop()
    print('Case #{}: {}'.format(case+1, result))


if __name__ == '__main__':
  main()
