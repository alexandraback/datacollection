from fractions import gcd

# The big number is N. 
# The state repeats when all barbers are free.
# This first happens after the least common multiple of all barbers is done (in minutes).
# The people served, S, is the sum of all quotients.

# Find the remainder X = N mod S, and you will be served by the same barber as X.

# Note: For large B and X_i, alternate arrangements may have to be made.

def lcm(x):
  x = sorted(set(x))
  m = x[0]
  for c in x[1:]:
    m = m * c // gcd(m, c)
  return m

def solve(x, n):
  period_time = lcm(x)
  #print(period_time)
  #print(x)
  period_customers = sum((period_time // b) for b in x)
  #print(list((period_time // b) for b in x))
  #print(period_customers)
  # convert to zero-offset before modulo!
  n2 = ((n-1) % period_customers) + 1
  return simulate(x, n2)
  


def simulate(x, n):
  barbers = [0]*len(x)
  for i in range(n):
    # wait until one is free
    wait = min(barbers)
    for j in range(len(x)):
      barbers[j] -= wait

    k = barbers.index(0)
    barbers[k] = x[k] # reset counter
  return k

def read_solve():
  b, n = map(int, input().split())
  x = list(map(int, input().split()))
  return solve(x, n) + 1

def main():
  cases = int(input())
  for i in range(1, cases+1):
    print('Case #{}: {}'.format(i, read_solve()))

main()
