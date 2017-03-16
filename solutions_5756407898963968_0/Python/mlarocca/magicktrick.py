'''
Created on 12/apr/2014

@author: mlarocca
'''
from sys import argv
N_ROWS = 4

MULTIPLE_CARDS_ERROR = "Bad magician!"
NO_CARDS_ERROR = "Volunteer cheated!"

def read_input(f):
  lines = open(f, 'r')
  n = int(lines.readline().strip())
  for i in xrange(n):
    
    r1 = int(lines.readline().strip()) - 1
    M1 = []
    for _ in xrange(N_ROWS):
      M1.append(set(lines.readline().strip().split(" ")))
    r2 = int(lines.readline().strip()) - 1
    M2 = []
    for _ in xrange(N_ROWS):
      M2.append(set(lines.readline().strip().split(" ")))  
    
    yield i+1, M1[r1], M2[r2]   
    
    
  
if __name__ == '__main__':
  for test_case, row_1, row_2 in read_input(argv[1]):
    res =  row_1 & row_2
    if len(res) == 1:
      print "Case #%d: %s" % (test_case, list(res)[0])
    elif len(res) > 1:
      print "Case #%d: %s"  % (test_case, MULTIPLE_CARDS_ERROR)
    else:
      print "Case #%d: %s"  % (test_case, NO_CARDS_ERROR)