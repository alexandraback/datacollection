n = int(raw_input())
for testcase in range(n):
  k = int(raw_input())
  line = [int(x) for x in raw_input().split()]
  eaten = 0
  max_derivative = 0
  for i in range(k-1):
    missing = line[i] - line[i+1]
    if missing > 0:
      eaten += missing
      max_derivative = max(max_derivative, missing)
  eaten_constant = 0
  for i in range(len(line)-1):
    eaten_constant += min(line[i], max_derivative)
  print "Case #%s: %s %s"%(testcase+1, eaten, eaten_constant)

