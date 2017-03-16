#!/usr/bin/env python
verbose = False
def solve_slow(line_p, barb_speed):
   barb_occupied = [0]*len(barb_speed)
   for x in range(line_p-1):
      next_b = barb_occupied.index(0)
      barb_occupied[next_b] = barb_speed[next_b]
      #print(barb_occupied)
      #for i in range(len(barb_occupied)):
      #   barb_occupied[i] = max(0, barb_occupied[i]-1)
      while all(b > 0 for b in barb_occupied):
         b_slowest = min(barb_occupied)
         for i in range(len(barb_occupied)):
            barb_occupied[i] -= b_slowest
         #print(barb_occupied)
   return (barb_occupied.index(0)+1,)

def solve(line_p, barb_speed):
   barb_occupied = list(barb_speed)
   barb_cyc = [i for i in range(len(barb_speed))]
   while any(b > 0 for b in barb_occupied):
      for i in range(len(barb_occupied)):
         if barb_occupied[i] == 0:
            barb_cyc.append(i)
            barb_occupied[i] = barb_speed[i]
      b_slowest = min(barb_occupied)
      for i in range(len(barb_occupied)):
         barb_occupied[i] -= b_slowest
   return (barb_cyc[(line_p-1)%len(barb_cyc)]+1,)

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
         barbs, line_pos = [int(x) for x in f.readline().split(' ')]
         barb_speed = [int(x) for x in f.readline().split(' ')]
         #assert(solve_slow(line_pos, barb_speed) == solve(line_pos, barb_speed))
         print("Case #%d: %d"%((i+1,) + solve(line_pos, barb_speed)))
