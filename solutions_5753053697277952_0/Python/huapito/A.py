import sys

abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

def solve(l):
  d = {}
  for i in range(len(l)):
    d[abc[i]] = l[i]
  r = []
  while max(d.values()) > 0:
#    print d
    r.append(next(d))
  return " ".join(r)
#  return "".join([str(x) for x in sorted(r)])

def next(dic):
  keys = [key for key in dic if dic[key] == max(dic.values())]
  if len(keys) in (1,3):
    dic[keys[0]] = dic[keys[0]] - 1
    return keys[0]
  else:
    dic[keys[0]] = dic[keys[0]] - 1
    dic[keys[1]] = dic[keys[1]] - 1
    return keys[0] + keys[1]


input_file = sys.argv[1]
with open(input_file) as f:
  T = int(f.readline().strip())
  
  for i in range(T):
    s = f.readline().strip()
    l = [int(x) for x in f.readline().strip().split(" ")]
    print "Case #%s: %s" % (i+1, solve(l))
