
INF = 99999999999999999
from math import floor, ceil

def word_to_canon_form(word):
  canon = []
  current_ch = word[0]
  current_len = 1
  
  for ch in word[1:]:
    if ch == current_ch:
      current_len += 1
    else:
      canon.append((current_ch, current_len))
      current_ch = ch
      current_len = 1

  canon.append((current_ch, current_len))
  return canon

def can_align(canons):
  canon_len = len(canons[0])
  for canon in canons:
    if len(canon) != canon_len:
      return False

  for i  in xrange(canon_len):
    ch_i = canons[0][i][0]
    for canon in canons:
      if canon[i][0] != ch_i:
        return False

  return True

def calc_dist(canons, i, val):
  return sum([abs(canon[i][1] - val) for canon in canons])

def move_to_ident(N, words):
  canons = [word_to_canon_form(word) for word in words]
  #for canon in  canons:
  #  print canon
  
  if not can_align(canons):
    return INF

  total_moves = 0
  canon_len = len(canons[0])
  for i in xrange(canon_len):
    avg = float(sum([canon[i][1] for canon in canons])) / len(canons)
    opt1, opt2 = int(floor(avg)), int(ceil(avg))
    #print "opt", opt1, opt2
    dist1, dist2 = calc_dist(canons, i, opt1), calc_dist(canons, i, opt2)
    #print "dist", dist1, dist2
    total_moves += min(dist1, dist2) 
   
  return int(total_moves)

if __name__ == '__main__':
  T = int(raw_input())
  for i in xrange(1,T+1):
    N = int(raw_input())
    
    words = []
    for j in xrange(N):
      words.append(raw_input().strip())

    res = move_to_ident(N, words)
    if res == INF:
      print "Case #%s: Fegla Won" % i
    else:
      print "Case #%s: %s" % (i, res)
