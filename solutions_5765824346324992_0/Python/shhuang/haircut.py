import sys, math

EPSILON_MULT = 0.0000001

def gcd(x, y):
   """This function implements the Euclidian algorithm
   to find G.C.D. of two numbers"""

   while(y):
       x, y = y, x % y

   return x

# define lcm function
def lcm(x, y):
   """This function takes two
   integers and returns the L.C.M."""

   lcm = (x*y)//gcd(x,y)
   return lcm

def take_ceil(x):
    if abs(x - int(x)) < EPSILON_MULT * x:
        return int(x)
    else:
        return int(math.ceil(x))
        

def helper(place_in_line, times):
    #print place_in_line, times
    if len(times) == 1:
        return 1

    if max(times) == min(times):
        if place_in_line % len(times) == 0:
            return len(times)
        return place_in_line % len(times)

    lcm_time = lcm(times[0], times[1])
    for t in times[2:]:
        lcm_time = lcm(t, lcm_time)
    #print lcm_time

    num_haircuts_in_lcm_time = [lcm_time / t for t in times]
    rounds = place_in_line / sum(num_haircuts_in_lcm_time)
    #print place_in_line, sum(num_haircuts_in_lcm_time), rounds
    place_in_line -= rounds * sum(num_haircuts_in_lcm_time)

    #print rounds, place_in_line

    if place_in_line == 0:
        min_time = min(times)
        min_flow_idx = [i for (i, t) in enumerate(times) if t == min_time]
        return min_flow_idx[-1] + 1
    if place_in_line < len(times):
        return place_in_line

    flows_per_min = [1.0 / x for x in times]
    min_elapsed = 1
    place_in_line -= len(times)
    
    while True:
        #print times, min_elapsed
        for (i, t) in enumerate(times):
            if min_elapsed % t == 0:
                place_in_line -= 1
            if place_in_line == 0:
                return i + 1
        min_elapsed += 1
            
    return -1

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
    place_in_line = int(test[0].split()[1])
    times = [int(x) for x in test[1].split()]
    sol = helper(place_in_line, times)
    print 'Case #{}: {}'.format(case+1, sol)
  #sol = helper(test)
  #print 'Case #{}: {}'.format(case+1, sol)
