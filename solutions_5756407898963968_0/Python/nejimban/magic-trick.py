import re
from sys import stdin
T = int(stdin.readline()) # ignored
data = re.findall('(\d)\s+((?:\d+(?: \d+)+\s+)+)', stdin.read(), flags=re.S)
sets = [set(x.splitlines()[int(i)-1].split()) for (i, x) in data]
for i, (s1, s2) in enumerate(zip(sets[::2], sets[1::2]), 1):
  s = s1 & s2
  l = len(s)
  print('Case #%d: %s' % (i,
    l == 0 and 'Volunteer cheated!' or l > 1 and 'Bad magician!' or s.pop()))
