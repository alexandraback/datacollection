from sys import stdin
from heapq import *

def solve(barber_times, place_in_line):
  place_in_line -= 1
  barbers = [[0, i] for i in range(len(barber_times))]
  heapify(barbers)

  product = 1
  for t in barber_times:
    product *= t
  time_chunk = product
  customers_per_time_chunk = 0
  for barber_time in barber_times:
    customers_per_time_chunk += time_chunk / barber_time
  place_in_line = place_in_line % customers_per_time_chunk

  served = 0
  while served < place_in_line:
    barber = heappop(barbers)
    served += 1
    
    barber[0] += barber_times[barber[1]]
    heappush(barbers, barber)
  return heappop(barbers)[1]

if __name__ == "__main__":
  num_cases = int(stdin.readline())
  for case_num in range(1, num_cases+1):
    num_barbers, place_in_line = [int(i) for i in stdin.readline().split()]
    barber_times = [int(i) for i in stdin.readline().split()]

    print >> open('log.txt', 'w'), "Case #", case_num, barber_times, place_in_line
    solution = solve(barber_times, place_in_line)

    print "Case #" + str(case_num) + ": " + str(solution+1)