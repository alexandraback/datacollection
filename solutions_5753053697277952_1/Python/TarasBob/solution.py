#!/usr/bin/python
from sys import stdin, stderr

def solve(num_senators):
  parties = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
  parties1 = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
  assert parties == parties1
  pair_list = []
  for i, num in enumerate(num_senators):
    pair_list.append([num, parties[i]])
  result = []
  while True:
    if len(pair_list) == 2 and pair_list[0][0] == pair_list[1][0]:
      result.append(pair_list[0][1] + pair_list[1][1])
      pair_list[0][0] -= 1
      pair_list[1][0] -= 1
      if pair_list[0][0] == 0:
        return ' '.join(result)
      else:
        continue
    pair_list = sorted(pair_list)
    num, party_name = pair_list.pop()
    result.append(party_name)
    num -= 1
    if num > 0:
      pair_list.append([num, party_name])

num_cases = int(stdin.readline())
for case_num in range(num_cases):
  num_parties = stdin.readline()
  num_senators = [int(x) for x in stdin.readline().strip().split()]
  result = 'Case #{0}: {1}'.format(case_num + 1, solve(num_senators))
  print result
  print >>stderr, result
