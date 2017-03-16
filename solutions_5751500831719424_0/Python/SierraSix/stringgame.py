import sys
import re
import math

def readcases():
  f = open(sys.argv[1], 'r')
  t = int(f.readline())

  cases = [];
  r = re.compile('[ \n]+')
  for i in xrange(t):
    n = int(f.readline())
    strs = []
    strsNR = []
    strsCC = []
    for j in xrange(n):
      strj = f.readline()
      strs.append(strj)
      noRepeat = ''
      charCounts = []
      thisChar = ''
      thisCount = 0
      for k in xrange(len(strj)):
        if thisChar == '':
          thisChar = strj[k]
        else:
          if thisChar == strj[k]:
            thisCount += 1
          else:
            noRepeat += thisChar
            charCounts.append(thisCount)
            thisCount = 0
            thisChar = strj[k]
      strsNR.append(noRepeat)
      strsCC.append(charCounts)
    cases.append({'n': n, 'strs': strs, 'nr': strsNR, 'cc': strsCC})
  f.close()
  return cases
def dostuff():
  cases = readcases()
  o = open('out.txt', 'w')
  for i in xrange(len(cases)):
    out = 'Case #' + str(i+1) + ': '
    case = cases[i]
    str0 = case['nr'][0]
    fwin = False
    for j in range(1 ,len(case['nr'])):
      if case['nr'][j] != str0:
        fwin = True
        break
    if fwin:
      out += 'Fegla Won'
    else:
      moves = 0
      for j in xrange(len(case['cc'][0])):
        a = []
        for k in xrange(len(case['cc'])):
          a.append(case['cc'][k][j])
        a.sort()
        if (len(a)%2):
          mid0 = a[len(a)/2-1]
          mid1 = a[len(a)/2]
          mov0 = mov1 = 0
          for k in xrange(len(a)):
            mov0 += abs(a[k] - mid0)
            mov1 += abs(a[k] - mid1)
          mov = min(mov0, mov1)
        else:
          mid = a[len(a)/2]
          mov = 0
          for k in xrange(len(a)):
            mov += abs(a[k] - mid)
        moves += mov
      out += str(moves)
    print out
    o.write(out + '\n');
  o.close();
def main():
  if len(sys.argv) != 2:
    print 'Usage: python stringgame.py <input>'
  else:
    dostuff()
if __name__ == '__main__':
  main()
    
