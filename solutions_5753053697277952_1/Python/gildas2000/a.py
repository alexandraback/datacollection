from codejam import CodeJam, parsers

def solve(ns, numbers):
  n = int(ns[0])
  order = []
  still = True
  while still:
    still = False
    for i in range(0, n):
      if numbers[i] > 0:
        order.append(i)
        numbers[i] -= 1
        still = True

  count = 0
  if len(order) % 2 == 1:
    count = 1
  out = ""
  for i in range(0, len(order)):
    out += chr(65+order[-1-i])
    count += 1
    if count % 2 == 0:
      out += ' '
  return out

@parsers.iter_parser
def parse(next):
  n = next().strip().split(' ')
  numbers = [int(x) for x in next().strip().split(' ')]
  return n, numbers

if __name__ == "__main__":
  CodeJam(parse, solve).main()
