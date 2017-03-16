#!/usr/bin/env python
verbose = False

def solve(levels):
   rates = []
   xp = levels[0]
   for x in levels[1:]:
      rates.append(xp-x)
      xp = x
   #print(rates)

   method1 = 0
   for x in rates:
      if x > 0:
         method1 += x

   rate = max(rates)
   method2 = 0
   for i, x in enumerate(rates):
      method2 += min(levels[i], rate)
      #if x < 0:
      #   method2 += levels[i]
      #else:
      #   method2 += rate
   return (method1, method2)

if __name__ == '__main__':
   import argparse
   parser = argparse.ArgumentParser()
   parser.add_argument("file",
                       help="The input file")
   parser.add_argument("-v", "--verbose", action='store_true', default=False,
                       help="be verbose")
   args = parser.parse_args()
   verbose = args.verbose
   with open(args.file) as f:
      T = int(f.readline())
      for i in range(T):
         mushes = int(f.readline())
         times = [int(x) for x in f.readline().split(' ')]
         print("Case #%d: %d %d"%((i+1,) + solve(times)))
         pass
