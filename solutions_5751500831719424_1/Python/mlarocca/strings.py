'''
Created on 12/apr/2014

@author: mlarocca
'''
from sys import argv

def transform_strings(strs):
  def transform (s):
    res = []
    current = s[0]
    current_cnt = 1
    n = len(s)
    for i in xrange(1, n):
      if s[i] == s[i-1]:
        current_cnt += 1
      else:
        res.append((current, current_cnt))
        current = s[i]
        current_cnt = 1
    res.append((current, current_cnt))
    return res

  strs = map(transform, strs)
  lengths = map(lambda s: len(s), strs)
  n = len(strs)
  m = len(strs[0])
  
  if lengths.count(lengths[0]) != n:
    #can't make them all the same
    return None

  tot_dist = 0
  for i in xrange(m):
    #for every sequence in strings
    c, l_sum = strs[0][i]

    for j in xrange(1, n):
      #for every string
      s = strs[j][i]
      if s[0] != c:
        return None
      else:
        l_sum += s[1]

    l_sum = int(round(float(l_sum) / n)) #average number of repetitions
    for j in xrange(n):
      tot_dist += abs(strs[j][i][1] - l_sum)

  return tot_dist


def read_input(f):
  lines = open(f, 'r')
  N = int(lines.readline().strip())
  for i in xrange(N):
    
    m = int(lines.readline().strip())
    strs = []
    for j in xrange(m):
      strs.append(lines.readline().strip())
    
    yield i+1, strs  
    
    
  
if __name__ == '__main__':
  for test_case, strs in read_input(argv[1]):
    dist = transform_strings(strs)
    
    if dist == None:
      print "Case #%d: %s" % (test_case, "Fegla Won")
    else:
      print "Case #%d: %d"  % (test_case, dist)