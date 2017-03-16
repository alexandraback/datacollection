from sys import stdin

def main():
  T = int(next(stdin))
  for i in xrange(1,T+1):
    choice1 = int(next(stdin))
    possibilities1 = set(arrang()[choice1-1])
    choice2 = int(next(stdin))
    possibilities2 = set(arrang()[choice2-1])
    result = possibilities1 & possibilities2
    if len(result) == 1:
      ans = next(iter(result))
    elif len(result) > 1:
      ans = "Bad magician!"
    else:
      ans = "Volunteer cheated!"
    print "Case #{}: {}".format(i, ans)

def arrang():
  rows = [next(stdin) for _ in xrange(4)]
  return [map(int, row.split(" ")) for row in rows]

main()  
