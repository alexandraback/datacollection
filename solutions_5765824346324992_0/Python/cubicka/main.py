import heapq

def GCD(x, y):
  if y == 0: return x
  return GCD(y, x%y)

def Sieve(lim):
  global primes
  isprime = [False  if x%2 == 0 else True for x in range(lim)]
  isprime[1] = False
  isprime[2] = True

  primes.append(2)
  for k in range(3, lim, 2):
    if isprime[k]:
      primes.append(k)
      for m in range(k+k, lim, k):
        isprime[m] = False

primes = []
Sieve(100000)

raw = open("B-small-attempt1.in").read().strip().split('\n')
fout = open("out.txt", "w")

ncase = int(raw[0])
for xcase in range(1, ncase+1):
  print xcase
  nb, nn = [int(x) for x in raw[xcase*2-1].strip().split(' ')]
  barberTime = [int(x) for x in raw[xcase*2].strip().split(' ')]

  # print >>fout, nb, nn

  timeSeries = []
  heapq.heapify(timeSeries)
  total = 1
  for idx, x in enumerate(barberTime):
    d = GCD(total, x)
    total /= d
    total *= x
    heapq.heappush(timeSeries, (0, idx+1, x))

  turnMult = 0
  for x in barberTime:
    turnMult += total / x

  nn -= 1
  nn %= turnMult
  nn += 1

  for i in xrange(nn-1):
    if i%10000 == 0: print "time", i
    node = heapq.heappop(timeSeries)
    heapq.heappush(timeSeries, (node[0] + node[2],node[1], node[2]))

  # print >>fout, barberTime
  print >>fout, "Case #" + str(xcase) + ":", timeSeries[0][1]

