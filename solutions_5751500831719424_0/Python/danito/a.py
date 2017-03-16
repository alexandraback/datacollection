#!/usr/bin/python2 -tt

def eliminate_repeated_letters(word):
  counter = []
  count = 1
  s = word[0]
  for i in word[1:]:
    if i == s[-1]:
      count += 1
    else:
      counter.append(count)
      count = 1
      s += i
  counter.append(count)
  return s, counter

def main(words):
  counter = 0
  letter_order = []
  letter_counters = []
  for w in words:
    o, c = eliminate_repeated_letters(w)
    letter_order.append(o)
    letter_counters.append(c)

  if len(set(letter_order)) > 1: return "Fegla Won"
  
  for pos in xrange(len(letter_counters[0])):
    counter += abs(letter_counters[0][pos] - letter_counters[1][pos])

  return counter


if __name__ == '__main__':
  import sys
  T = int(sys.stdin.readline())
  for i in xrange(T):
    words = []
    N = int(sys.stdin.readline())
    for j in xrange(N):
      words.append(sys.stdin.readline().strip())

    res = main(words)
    print "Case #%d: %s" % (i + 1, res)

