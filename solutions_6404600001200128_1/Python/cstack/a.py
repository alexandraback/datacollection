from sys import stdin

def solve(time_points):
  deltas = [time_points[i+1] - time_points[i] for i in range(len(time_points) - 1)]
  decreases = [max(-i, 0) for i in deltas]
  biggest_drop = max(decreases)

  sum_method_1 = 0
  sum_method_2 = 0

  for i in range(len(decreases)):
    decrease = decreases[i]

    sum_method_1 += decrease

    sum_method_2 += min(biggest_drop, time_points[i])

  return str(sum_method_1) + " " + str(sum_method_2)

if __name__ == "__main__":
  num_cases = int(stdin.readline())
  for case_num in range(1, num_cases+1):
    num_time_points = int(stdin.readline())
    time_points = [int(i) for i in stdin.readline().split()]

    solution = solve(time_points)

    print "Case #" + str(case_num) + ": " + str(solution)