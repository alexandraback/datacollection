import sys


def get_number_of_tests(fd):
  n = fd.readline()
  return int(n)


def get_row(fd):
  n = fd.readline()
  return int(n)


def read_rows(fd):
  for i in xrange(4):
    line = fd.readline()
    row = line.strip().split()
    yield map(int, row)


def get_picked_row(fd):
  row_index = get_row(fd)
  rows = list(read_rows(fd))
  picked_row = rows[row_index - 1]
  return picked_row


def main(fd):
  for i in xrange(get_number_of_tests(fd)):
    try:
      round1 = set(get_picked_row(fd))
      round2 = set(get_picked_row(fd))
      intersected = round1.intersection(round2)
      count = len(intersected)
      if count == 0:
        print 'Case #%d: Volunteer cheated!' % (i + 1)
      elif count == 1:
        print 'Case #%d: %d' % ((i + 1), intersected.pop())
      else:
        print 'Case #%d: Bad magician!' % (i + 1)
    except Exception, e:
      print >> sys.stderr, e

if __name__ == '__main__':
  main(sys.stdin)
