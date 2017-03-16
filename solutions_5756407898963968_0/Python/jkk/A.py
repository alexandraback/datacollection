import sys
cases = int(sys.stdin.readline())
for case_no in range(1, cases+1):
  line = int(sys.stdin.readline()) - 1
  vals = [sys.stdin.readline() for i in range(4)]
  nums = set(vals[line].split())
  line = int(sys.stdin.readline()) - 1
  vals = [sys.stdin.readline() for i in range(4)]
  intersection = nums.intersection(set(vals[line].split()))
  ans = "Volunteer cheated!"
  if len(intersection) > 1:
    ans = "Bad magician!"
  elif len(intersection) == 1:
    ans = intersection.pop()
  print("Case #{}: {}".format(case_no, ans))
