import numpy
def valid(words):
  w0 = words[0]
  checker = []
  prev = '-'
  lengths = []
  l0 = []
  for l in w0:
    if l is not prev:
      checker.append(l)
      prev = l
      l0.append(1)
    else:
      l0[-1] += 1
  lengths.append(l0)
  len_checker = len(checker)

  for w in words[1:]:
    l0 = []
    prev = '-'
    counter = 0
    for l in w:
      if prev is not l:
        if counter > len_checker - 1 or l is not checker[counter]:
          return 'Fegla Won'
        l0.append(1)
        counter += 1
        prev = l
      else:
        l0[-1] += 1
    if counter is not len_checker:
      return 'Fegla Won'
    lengths.append(l0)
  lengths = numpy.array(lengths)
  return str(int(numpy.absolute(lengths - numpy.median(lengths, 0).round()).sum()))



n = int(raw_input())
for i in range(n):
  m = int(raw_input())
  words = []
  for j in range(m):
    words.append(raw_input())
  print 'Case #%d: %s' % (i+1, valid(words))


