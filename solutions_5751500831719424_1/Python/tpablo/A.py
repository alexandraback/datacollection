#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import sys, os, shutil
import math as m, random as r
import numpy as np
import multiprocessing as mp


def describe(word):
  ret = []
  lc = ''
  n = 0
  for c in word:
    if c == lc:
      n += 1
    else:
      if lc: ret.append([lc, n])
      lc = c
      n = 1
  if lc: ret.append([lc, n])
  return ret


def doable(d1, d2):
  if len(d1) != len(d2): return False
  for i in range(len(d1)):
    if d1[i][0] != d2[i][0]: return False
  return True


def solve(vect):
  result = 100
  for k in range(min(vect), max(vect)+1):
    t = 0
    for v in vect: t += abs(k - v)
    result = min(result, t)
  return result

def solve_single_test(LOCK, t, data, out):
  LOCK.acquire()
  OUT = open(out, 'wt')
  OUT.write('Case #%d: ' % (t + 1))
  
  words = data
  
  descriptions = [describe(w) for w in words]
  
  feglaWon = False
  
  for i in range(1, len(words)):
    if not doable(descriptions[0], descriptions[i]):
      feglaWon = True
      break
  
  if feglaWon:
    OUT.write('Fegla Won\n')
  else:
    moves = 0
    for i in range(len(descriptions[0])):
      vect = [descriptions[j][i][1] for j in range(len(words))]
      moves += solve(vect)
    
    OUT.write('%d\n' % moves)
  
  OUT.close()
  LOCK.release()


def get_single_test_data(IN):
  N = int(IN.readline())
  words = []
  for _ in range(N):
    words.append(IN.readline().strip())
  return words


def main():
  assert len(sys.argv) > 1
  in_path = sys.argv[1]
  assert in_path.endswith('.in')
  IN = open(in_path, 'rt')
  os.chdir(os.path.dirname(sys.argv[0]))
  T = int(IN.readline())
  data = []
  for t in range(T): data.append(get_single_test_data(IN))
  IN.close()
  
  out_dirname = in_path[:-3]
  if os.path.exists(out_dirname): shutil.rmtree(out_dirname)
  os.makedirs(out_dirname)
  
  test_filenames = [os.path.join(out_dirname, 'test%.5d.out' % (t + 1)) for t in range(T)]
  
  LOCK = mp.BoundedSemaphore(1)
  processes = []
  for t in range(T): processes.append(mp.Process(target=solve_single_test, args=(LOCK, t, data[t], test_filenames[t])))
  
  for p in processes: p.start()
  for p in processes: p.join()
  
  out_path = '%s.out' % (out_dirname)
  
  FULL_OUT = open(out_path, 'wt')
  
  for t in range(T):
    TEST_RESULT = open(test_filenames[t], 'rt')
    for l in TEST_RESULT:
      FULL_OUT.write(l)
    TEST_RESULT.close()
  
  FULL_OUT.close()

if __name__ == '__main__':
  main()

