def solve1(x):
  # Find the sum of the negative differences between successive elements.
  return sum(a-b for (a,b) in zip(x[:-1], x[1:]) if a >= b)

def solve2(x):
  # Find the maximum difference in any time interval
  rate = max(a-b for (a,b) in zip(x[:-1], x[1:]) if a >= b)
  # In every time interval, the consumed pieces will be that rate or however 
  # many there are, whichever is lower. The rest of the difference must be
  # new mushrooms
  return sum(min(rate, a) for a in x[:-1])


def read_solve():
  length = int(input())
  x = list(map(int, input().split()))
  return '{} {}'.format(solve1(x), solve2(x))


def main():
  cases = int(input())
  for i in range(1, cases+1):
    print('Case #{}: {}'.format(i, read_solve()))

main()
