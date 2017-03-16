#!/usr/bin/env python

import sys

def read():
  content = ''
  for line in sys.stdin:
    content += line
  return content

def main():
  content = read()
  lines = content.split('\n')
  cases = int(lines[0])
  lines = lines[1:]
  for i in range(cases):
    strings = int(lines[0])
    sublines = lines[1:strings+1]
    lines = lines[strings+1:]
    data = []
    for j in range(strings):
      current = []
      repeated = 0
      letter = ''
      for k in range(len(sublines[j])):
        if(sublines[j][k] == letter):
          repeated += 1
        else:
          if letter != '':
            current = current + [(letter, repeated)]
          letter = sublines[j][k]
          repeated = 1
      current = current + [(letter, repeated)]
      data.append(current)
    done = False
    ll = len(data[0])
    for j in range(strings):
      if len(data[j]) != ll:
        print 'Case #%d: Fegla Won'%(i+1)
        done = True
        break
    if done:
      continue
    for k in range(ll):
      cc = data[0][k][0]
      for j in range(strings):
        if cc != data[j][k][0]:
          print 'Case #%d: Fegla Won'%(i+1)
          done = True
          break
      if done:
        break
    if done:
      continue
    times = 0
    for k in range(ll):
      ss = []
      for j in range(strings):
        ss.append(data[j][k][1])
      ss.sort()
      mid = ss[(len(ss)-1)/2]
      for j in range(strings):
        times += abs(data[j][k][1] - mid)
    print 'Case #%d: %d'%(i+1, times)


if __name__ == '__main__':
  main()
