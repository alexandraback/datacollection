import sys

def solve(b, a):
  #print b[0]
  #print a
  l1 = set(b[0][a[0]-1])
  l2 = set(b[1][a[1]-1])
  l = l1 & l2
  if len(l) == 1:
    return str(list(l)[0])
  elif len(l) > 1:
    return 'Bad magician!'
  else:
    return 'Volunteer cheated!'


numcases = int(sys.stdin.readline())
for casenum in range(1,numcases+1):
  boards = []
  ans = []
  for j in range(2):
    ans.append(int(sys.stdin.readline()))
    board = []
    for i in range(4):
      board.append([int(x) for x in sys.stdin.readline().split()])
    boards.append(board)
  print 'Case #' + repr(casenum) + ': ' + solve(boards, ans)