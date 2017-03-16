import sys
import re

primes = [0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53]

def readcases():
  f = open(sys.argv[1], 'r')
  t = int(f.readline())

  cases = [];
  r = re.compile('[ \n]+')
  for i in xrange(t):
    choice1 = int(f.readline())
    before = map(int, r.split(f.readline() + f.readline() + f.readline() + f.readline())[:-1])
    choice2 = int(f.readline())
    after = map(int, r.split(f.readline() + f.readline() + f.readline() + f.readline())[:-1])
    cases.append({'choice1': choice1, 'choice2': choice2, 'before': before, 'after': after})
  f.close()
  return cases
def magician():
  cases = readcases()
  o = open('out.txt', 'w')
  for i in xrange(len(cases)):
    out = 'Case #' + str(i+1) + ': '
    sel1 = cases[i]['before'][(cases[i]['choice1'] - 1)*4 : cases[i]['choice1']*4]
    sel2 = cases[i]['after'][(cases[i]['choice2'] - 1)*4 : cases[i]['choice2']*4]
    sel2_sum = reduce(lambda a,b:a*primes[b], sel2, 1)
    matches = []
    for j in xrange(4):
      if sel2_sum % primes[sel1[j]] == 0:
        matches.append(sel1[j])
    if len(matches) == 0:
      out = out + 'Volunteer cheated!\n'
    elif len(matches) == 1:
      out = out + str(matches[0]) + '\n'
    elif len(matches) > 1:
      out = out + 'Bad magician!\n'
    o.write(out);
  o.close();
def main():
  if len(sys.argv) != 2:
    print 'Usage: python magicial.py <input>'
  else:
    magician()
if __name__ == '__main__':
  main()
    
