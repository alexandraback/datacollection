import sys

def encode(s):
  count = [1]
  key = s[0]
  for c in s[1:]:
    if c == key[-1]:
      count[-1] +=1 
    else:
      count.append(1)
      key += c
  return (key, count)

sys.stdin  = open("A-small-attempt0.in")
sys.stdout = open("A-small-attempt0.out", "w")
num_cases = input()

for case_no in range(1, num_cases+1):
  n = int(raw_input())
  lost = False
  key = None
  counts = []
  for i in range(n):
    s = raw_input()
    cur_key, count = encode(s)
    #print cur_key, count
    counts.append(count)
    if (key is not None) and (cur_key != key):
      lost = True
    key = cur_key
  ans = 0
  if lost:
    print 'Case #%d: Fegla Won' % (case_no)
  else:
    l = len(counts[0])
    for i in range(l):
      a = map(lambda x: x[i], counts)
      a.sort()
      ans += sum(map(lambda x: abs(x-a[n/2]), a))
    print 'Case #%d: %d' % (case_no, ans)