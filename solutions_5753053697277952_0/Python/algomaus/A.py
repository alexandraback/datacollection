#! /usr/bin/env python

def parse(lines):
  t = int(lines[0])
  act_line = 1
  cases = []
  for i in range(t):
    case = []
    n = int(lines[act_line])
    act_line = act_line + 1
    line = lines[act_line]
    act_line = act_line + 1
    line_splitted = line.split(" ")
    cases.append(line_splitted)
  return cases

def solve(case):
  alphabet = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
  sol_list = []
  
  case_tuples = []
  for i in range(len(case)):
    case_tuples.append((alphabet[i], int(case[i])))
    
  case_tuples.sort(key=lambda tup: tup[1], reverse=True)
  while (case_tuples[0][1] != 0):
    if case_tuples[1][1] == 0: # there is just 1 party left
      sol_list.append(case_tuples[0][0])
      new_tuple = (case_tuples[0][0], case_tuples[0][1] - 1)   
      case_tuples[0] = new_tuple
    elif case_tuples[0][1] > case_tuples[1][1]: # first party is larger than all others
      sol_list.append(case_tuples[0][0])
      new_tuple = (case_tuples[0][0], case_tuples[0][1] - 1)   
      case_tuples[0] = new_tuple
    elif len(case_tuples) >= 3 and case_tuples[0][1] == case_tuples[1][1] and case_tuples[0][1] == case_tuples[2][1]: # three equal numbers
      sol_list.append(case_tuples[0][0])
      new_tuple = (case_tuples[0][0], case_tuples[0][1] - 1)   
      case_tuples[0] = new_tuple
    else: # just two equal numbers
      string_list = [case_tuples[0][0], case_tuples[1][0]]
      sol_list.append("".join(string_list))
      new_tuple = (case_tuples[0][0], case_tuples[0][1] - 1)   
      case_tuples[0] = new_tuple
      new_tuple2 = (case_tuples[1][0], case_tuples[1][1] - 1)   
      case_tuples[1] = new_tuple2
    
    case_tuples.sort(key=lambda tup: tup[1], reverse=True)
  
  n = len(case)
  # do greedy approach
  
  
  return " ".join(sol_list)
    
#with open('A-large.in', 'r') as f:
with open('A-small-attempt0.in', 'r') as f:
#with open('input.txt', 'r') as f:
  cases = parse(f.read().splitlines())
for i in range(len(cases)):
  sol = solve(cases[i])
  print "Case #" + str(i+1) + ": " + sol
