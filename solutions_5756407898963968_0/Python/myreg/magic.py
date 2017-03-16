def read_set():
  n = int(raw_input())
  _ = [raw_input() for i in range(n-1)]
  p = set(raw_input().split())
  _ = [raw_input() for i in range(4-n)]
  return p

T = int(raw_input())
for i in range(T):
  p1, p2 = read_set(), read_set()
  k  = p1&p2
  print "Case #%i:"%(i+1),
  if (len(k) == 0):
    print "Volunteer cheated!"
  elif (len(k) == 1):
    print k.pop()
  else:
    print "Bad magician!"

