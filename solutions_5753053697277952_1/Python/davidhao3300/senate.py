f = open('A-large.in')
o = open('output.txt', 'w')
n = int(f.readline())

for i in range(n):
  print i
  num = int(f.readline())
  row = [int(x) for x in f.readline().strip().split(' ')]
  senate = sorted([(x, chr(idx+65)) for idx, x in enumerate(row)])
  senators = sum(row)
  order = []
  while senators > 0:
    print senate
    first = senate[-1]
    del senate[-1]
    senators -= 1
    order.append(first[1])
    if first[0] > 1:
      senate.append((first[0]-1, first[1]))
    if senators > 0:
      senate = sorted(senate)
      first = senate[-1]
      if first[1] > senators / 2 and senators != 2:
        order[-1] += first[1]
        del senate[-1]
        if first[0] > 1:
          senate.append((first[0]-1, first[1]))
        senate = sorted(senate)
        senators -= 1
    #print senate
    for x in [x[0] <= senators / 2 for x in senate]:
      if not x:
        o.write('ERROR')
    #print order
  if sum([len(x) for x in order]) != sum(row):
    o.write('ERROR')
  o.write('Case #{}: {}\n'.format(i+1, ' '.join(order)))
o.close()
f.close()