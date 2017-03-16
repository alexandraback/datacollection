
def ri():
  return int(raw_input())

def rs():
  return raw_input()

def ril():
  return map(int, raw_input().split())

def rsl():
  return map(str, raw_input().split())


def get(r):
  rows = list()
  rows.append(ril())
  rows.append(ril())
  rows.append(ril())
  rows.append(ril())
  return rows[r]

n = ri()

for x in range(n):
  a = ri()-1
  aa = get(a)
  b = ri()-1
  bb = get(b)
  foo = list(set(aa) & set(bb))
  if len(foo) == 1:
    print 'Case #%s:'%(x+1), foo[0]
  elif len(foo) == 0:
    print 'Case #%s:'%(x+1), 'Volunteer cheated!'
  else:
    print 'Case #%s:'%(x+1), 'Bad magician!'


